#include <iostream>
#include <stack>
#include "post.h"

using namespace std;

int GetVal(Token& opnd) //피연산자 토큰(NUM)에서 ival(정수값)을 가져온다
{
	if (opnd.type == NUM) //토큰의 type이 NUM일 경우
	{
		return opnd.ival; //정수값 반환
	}

	return 0; // ID인 경우는 0을 return하자
}


Token UnaryOp(int op, Token& x) // UMINUS와 ‘!’의 두가지 경우만 처리함
{ 
	if (!x.IsOperand())  //토큰이 피연산자라면 실행 x 토큰이 피연산자가 아니라면 실행 -> x는 -를 불여줘야하는 피연산자가 옴 즉, x가 피연산자가 아니라면 예외임
		throw "Operand Only for Unary Operator";

	Token tmp; //연산 결과값을 반환해줄 토큰 생성
	tmp.type = NUM; //반환할 땐 정수 결과값을 반환해야하므로 연산을 해줄 토큰은 숫자형 피연산자로 세팅

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


Token BinaryOp(int op, Token& left, Token& right) //일반적인 연산 경우 -> 스택에 있는 두개의 피연산자를 pop하여 연산
{
	if (!left.IsOperand() || !right.IsOperand()) //둘 중 하나라도 피연산자가 아니면 예외임
	{
		throw "Two Operands required for Binary Operation";
	}

	Token tmp; //연산 결과값을 반환해줄 토큰 생성
	tmp.type = NUM; //반환할 땐 정수 결과값을 반환해야하므로 연산을 해줄 토큰은 숫자형 피연산자로 세팅

	int val1 = GetVal(left), val2 = GetVal(right); //left와 right의 값을 val1, val2에 각각 저장

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

Token DeleteFromStack(stack<Token>& stack) // 스택의 top에 있는 것을 꺼내어 return한다.
{ 
	
	if (stack.empty())
	{
		throw "Trying to pop from an empty stack";
	}
	
	Token tmp = stack.top();
	
	stack.pop();
	
	return tmp;
}

void Eval(Expression e) // postfix표현식을 입력으로 받아 그 값을 계산한다.
{ 
	
	stack<Token> stack;
	Token opnd1, opnd2;

	for (Token x = NextToken(e, false); x != '#'; x = NextToken(e, false))
	{
		if (x.IsOperand()) //토큰이 피연산자라면
		{
			stack.push(x); //스택에 push
		}

		else   // x is an operator (x가 연산자라면 연산을 진행한 후 스택에 push해야함)
		{
			if (x.type == UMINUS || x.type == '!')  // unary operator
			{
				opnd1 = DeleteFromStack(stack); //opnd1은 피연산자여야함
				stack.push(UnaryOp(x.type, opnd1)); //unary operator을 이용한 연산 결과를 다시 스택에 push
			}

			else // binary operator
			{
				
				opnd2 = DeleteFromStack(stack); //opnd2는 우측에 들어갈 피연산자
				opnd1 = DeleteFromStack(stack); //opnd1은 좌측에 들어갈 피연산자
				stack.push(BinaryOp(x.type, opnd1, opnd2)); //이항 연산자를 이용한 연산 결과를 다시 스택에 push
				
			}
		}
	}

	cout << DeleteFromStack(stack) << endl;// 최종 계산 결과를 출력하자
}