#include <iostream>
#include <stack>
#include "post.h"

using namespace std;

int GetVal(Token& opnd) //�ǿ����� ��ū(NUM)���� ival(������)�� �����´�
{
	if (opnd.type == NUM) //��ū�� type�� NUM�� ���
	{
		return opnd.ival; //������ ��ȯ
	}

	return 0; // ID�� ���� 0�� return����
}


Token UnaryOp(int op, Token& x) // UMINUS�� ��!���� �ΰ��� ��츸 ó����
{ 
	if (!x.IsOperand())  //��ū�� �ǿ����ڶ�� ���� x ��ū�� �ǿ����ڰ� �ƴ϶�� ���� -> x�� -�� �ҿ�����ϴ� �ǿ����ڰ� �� ��, x�� �ǿ����ڰ� �ƴ϶�� ������
		throw "Operand Only for Unary Operator";

	Token tmp; //���� ������� ��ȯ���� ��ū ����
	tmp.type = NUM; //��ȯ�� �� ���� ������� ��ȯ�ؾ��ϹǷ� ������ ���� ��ū�� ������ �ǿ����ڷ� ����

	if (op == UMINUS) 
	{
		tmp.ival = -GetVal(x);
	}

	else if (op == '!')
	{
		tmp.ival = !GetVal(x);
	}

	else 
		throw "Invalid unary operator";
	
	
	return tmp;
}


Token BinaryOp(int op, Token& left, Token& right) //�Ϲ����� ���� ��� -> ���ÿ� �ִ� �ΰ��� �ǿ����ڸ� pop�Ͽ� ����
{
	if (!left.IsOperand() || !right.IsOperand()) //�� �� �ϳ��� �ǿ����ڰ� �ƴϸ� ������
	{
		throw "Two Operands required for Binary Operation";
	}

	Token tmp; //���� ������� ��ȯ���� ��ū ����
	tmp.type = NUM; //��ȯ�� �� ���� ������� ��ȯ�ؾ��ϹǷ� ������ ���� ��ū�� ������ �ǿ����ڷ� ����

	int val1 = GetVal(left), val2 = GetVal(right); //left�� right�� ���� val1, val2�� ���� ����

	if (op == '+') 
	{
		tmp.ival = (val1 + val2);
	}

	else if (op == '-') 
	{
		tmp.ival = (val1 - val2);
	}

	else if (op == '*') 
	{
		tmp.ival = (val1 * val2);
	}

	else if (op == '/') 
	{
		tmp.ival = (val1 / val2);
	}

	else if (op == '%') 
	{
		tmp.ival = (val1 % val2);
	}

	else if (op == '<')
	{
		tmp.ival = (val1 < val2);
	}

	else if (op == '>') 
	{
		tmp.ival = (val1 > val2);
	}

	else if (op == GE)
	{
		tmp.ival = (val1 >= val2);
	}

	else if (op == LE) 
	{
		tmp.ival = (val1 <= val2);
	}

	else if (op == EQ)
	{
		tmp.ival = (val1 == val2);
	}

	else if (op == NE)
	{
		tmp.ival = (val1 != val2);
	}

	else if (op == AND) 
	{
		tmp.ival = (val1 && val2);
	}

	else if (op == OR) 
	{
		tmp.ival = (val1 || val2);
	}

	else if (op == '=') throw "Assignment Not Yet Implemented";

	else throw "No such binary operator";

	return tmp;
}

Token DeleteFromStack(stack<Token>& stack) // ������ top�� �ִ� ���� ������ return�Ѵ�.
{ 
	
	if (stack.empty())
	{
		throw "Trying to pop from an empty stack";
	}
	
	Token tmp = stack.top();
	
	stack.pop();
	
	return tmp;
}

void Eval(Expression e) // postfixǥ������ �Է����� �޾� �� ���� ����Ѵ�.
{ 
	
	stack<Token> stack;
	Token opnd1, opnd2;

	for (Token x = NextToken(e, false); x != '#'; x = NextToken(e, false))
	{
		if (x.IsOperand()) //��ū�� �ǿ����ڶ��
		{
			stack.push(x); //���ÿ� push
		}

		else   // x is an operator (x�� �����ڶ�� ������ ������ �� ���ÿ� push�ؾ���)
		{
			if (x.type == UMINUS || x.type == '!')  // unary operator
			{
				opnd1 = DeleteFromStack(stack); //opnd1�� �ǿ����ڿ�����
				stack.push(UnaryOp(x.type, opnd1)); //unary operator�� �̿��� ���� ����� �ٽ� ���ÿ� push
			}

			else // binary operator
			{
				
				opnd2 = DeleteFromStack(stack); //opnd2�� ������ �� �ǿ�����
				opnd1 = DeleteFromStack(stack); //opnd1�� ������ �� �ǿ�����
				stack.push(BinaryOp(x.type, opnd1, opnd2)); //���� �����ڸ� �̿��� ���� ����� �ٽ� ���ÿ� push
				
			}
		}
	}

	cout << DeleteFromStack(stack) << endl;// ���� ��� ����� �������
}