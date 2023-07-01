#include <iostream>
#include <stack>
#include "post.h"

using namespace std;

bool Token::operator==(char b) //��ū�� #���� �ƴ��� ���� -> token�� ���̰� 1�̰� #�̸� true��ȯ
{ 
	return len == 1 && str[0] == b; 
}

bool Token::operator!=(char b) //��ū�� #�� �ٸ��� Ȯ�� -> token�� ���̰� 1�� �ƴϰų�, token�� ù��° ���ڰ� #�� �ƴϸ� true��ȯ
{ 
	return len != 1 || str[0] != b;
}


Token::Token() {}


Token::Token(char c) : len(1), type(c)
{
	str = new char[1]; 
	str[0] = c;
} // default type = c itself


Token::Token(char c, char c2, int ty) : len(2), type(ty)
{
	str = new char[2]; 
	str[0] = c; 
	str[1] = c2;
}

Token::Token(char* arr, int l, int ty = ID) : len(l), type(ty) 
{
	str = new char[len + 1];

	for (int i = 0; i < len; i++) 
		str[i] = arr[i];

	str[len] = '\0';

	if (type == NUM) //type�� ������ �� ���ڶ�� �ش� ��ū�� �������� ����ؼ� ival�� �����Ѵ�. �ش� ������ ���ڰ��� str�� �������
	{
		ival = arr[0] - '0';
		for (int i = 1; i < len; i++) 
			ival = ival * 10 + arr[i] - '0';
	}

	else if (type == ID) //type�� ������ �� ������� �ش� ��ū�� ival���� 0���� �����
		ival = 0;

	else 
		throw "must be ID or NUM";
}

bool Token::IsOperand() //��ū�� type�� �ǿ����� (�����̰ų� ����)�̸� true��ȯ 
{ 
	return type == ID || type == NUM; 
}

ostream& operator<<(ostream& os, Token t) 
{
	if (t.type == UMINUS)  //unary - �������� ��� -u���
		os << "-u";

	else if (t.type == NUM) //���� ��ū(�ǿ�����)�� ����� ��� ���ڿ��� �ƴ� ���ڸ� ���
		os << t.ival;

	else //�� ���� ��� ��ū�� ����� ���ڿ� ���� ���
		for (int i = 0; i < t.len; i++) 
			os << t.str[i];
	
	os << " "; //��� ������ ���� �߰�

	return os;
}

bool GetID(Expression& e, Token& tok) //ID ���ڿ��̸� ������ �о tok�� ����
{
	char arr[MAXLEN]; int idlen = 0;
	char c = e.str[e.pos]; //�ش� �ε������� �����ϴ� �ϳ��� ���ڸ� c�� ����

	if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')) //c���� ���ڰ��� �ƴϸ�
		return false; //ID���� �ƴϹǷ� false��ȯ

	arr[idlen++] = c; //c���� arr�迭�� ����
	e.pos++; //���� �ε��� ��ġ �ϳ� ����

	while ((c = e.str[e.pos]) >= 'a' && c <= 'z'|| c >= 'A' && c <= 'Z'	|| c >= '0' && c <= '9') //ID ������ ���� ������
	{
		arr[idlen++] = c; e.pos++; //arr�迭�� �����ϴ� ����
	}

	arr[idlen] = '\0'; //ID���� �� �������� �ι��� ������ ���� ���ڿ��� �������

	tok = Token(arr, idlen, ID); // return an ID (��ū�� ID�� �ʱ�ȭ)

	return true;
}

bool GetInt(Expression& e, Token& tok) //NUM ���ڿ��̸� ������ �о tok�� ����
{
	//�ڵ� �Է�
	char arr[MAXLEN]; int idlen = 0;
	char c = e.str[e.pos]; //�ش� �ε������� �����ϴ� �ϳ��� ���ڸ� c�� ����
	 
	if (!(c >= '0' && c <= '9')) //c���� ���ڰ��� �ƴ϶��
		return false; //NUM�� �ƴϹǷ� false��ȯ

	arr[idlen++] = c; //c���� arr�迭�� ����
	e.pos++; //���� �ε��� ��ġ �ϳ� ����

	while ((c = e.str[e.pos]) >= '0' && c <= '9' ) //NUM ������ ���� ������
	{
		arr[idlen++] = c; e.pos++; //arr�迭�� �����ϴ� ����
	}

	arr[idlen] = '\0';
	tok = Token(arr, idlen, NUM); // return an NUM(��ū�� NUM���� �ʱ�ȭ)

	return true;
}

void SkipBlanks(Expression& e) //������ ���� �����ְ�, ���� ��ġ�� �ε����� ���ڰ��� �����̰ų� tab�̸� skip�ϰ� �Ѿ
{
	char c;
	while (e.pos < e.len && ((c = e.str[e.pos]) == ' ' || c == '\t'))
		e.pos++;
}


bool TwoCharOp(Expression& e, Token& tok)
{
	//7���� �α��� ��ū(������)�� // <= >= == != && || -u�� ó��

	char c = e.str[e.pos]; 
	char c2 = e.str[e.pos + 1];
	int op; // LE GE EQ NE AND OR UMINUS

	if (c == '<' && c2 == '=') //LE
		op = LE;

	// �ڵ��Է�: �� �� ���� ��ū(������)�� ���� �˸��� type�� op�� ����
	else if (c == '>' && c2 == '=') //GE
		op = GE;

	else if (c == '=' && c2 == '=') //EQ
		op = EQ;
	
	else if (c == '!' && c2 == '=') //NE
		op = NE;
	
	else if (c == '&' && c2 == '&') //AND
		op = AND;

	else if (c == '|' && c2 == '|') //OR
		op = OR;

	else if (c == '-' && c2 == 'u') //-u
		op = UMINUS;
	
	else
		return false; // �´� �� ���� ��ū�� �ƴϸ� false�� return�Ѵ�.

	tok = Token(c, c2, op); //��ū�� �α��� ��ū���� �ʱ�ȭ

	e.pos += 2; //���� ��ĭ Ȯ�� ���������Ƿ� e.pos�� 2 ���������ش�.

	return true;
}


bool OneCharOp(Expression& e, Token& tok)
{
	//11���� �ѱ��� �����ڵ� // -, !, *, /, %. +. <, >, (, ), = ���� ó��
	char c = e.str[e.pos];

	if (c == '-' || c == '!' || c == '*' || c == '/' || c == '%' ||
		c == '+' || c == '<' || c == '>' || c == '(' || c == ')' || c == '=')
	{
		tok = Token(c); //��ū�� �ѱ��� ��ū���� �ʱ�ȭ

		e.pos++; //���� ��ĭ Ȯ�� ���������Ƿ� e.pos�� 1 ���������ش�

		return true;
	}

	return false;
}


Token NextToken(Expression& e, bool INFIX = true)
{
	static bool oprrFound = true; // ������ ������ �߰ߵǾ��ٰ� ����.
	
	Token tok;

	SkipBlanks(e); // skip blanks if any
	
	if (e.pos == e.len) // No more token left in this expression
	{
		if (INFIX) 
			oprrFound = true; 
		
		return Token('#'); //���� �������Ƿ� #��ū ��ȯ
	}


	if (GetID(e, tok) || GetInt(e, tok)) //�о���� �� ID�� NUM�̶��(�ǿ�����)
	{
		if (INFIX) 
			oprrFound = false; //�����ڰ� �ƴϹǷ� oprrFound�� false
		
		return tok;
	}


	if (TwoCharOp(e, tok) || OneCharOp(e, tok))  //�о���ΰ� �����ڶ��
	{
		if (tok.type == '-' && INFIX && oprrFound) // operator �� -�߰� (�� ������ ����ǥ����̰�, ���� �о���� ��ū�� '-'�̰�, ���� �о���ΰ� �����ڶ��)
			tok = Token('-', 'u', UMINUS); // unary minus(-u)�� �ٲٽÿ�
		
		if (INFIX) 
			oprrFound = true; //�������̹Ƿ� oprrFound�� true
		
		return tok;
	}

	throw "Illegal Character Found";
}


int icp(Token& t) 
{ 
	// in-coming priority
	int ty = t.type;

	/* ty�� '('�� 0, UMINUS�� '!'�� 1,
	 '*'�� '/'�� '%'�� 2, ��+���� '-'�� 3,'<'�� '>'�� LE�� GE�� 4,
	 EQ�� NE�� 5, AND�� 6, OR�̸� 7,'='�̸� 8, '#'�� 9�� return�Ѵ�.*/

	switch (ty)
	{
	case '(':
		return 0;
		break;

	case '!':
	case UMINUS:
		return 1;
		break;

	case '*':
	case '/':
	case '%':
		return 2;
		break;

	case '+':
	case '-':
		return 3;
		break;

	case '<':
	case '>':
	case LE:
	case GE:
		return 4;
		break;

	case EQ:
	case NE:
		return 5;
		break;

	case AND:
		return 6;
		break;

	case OR:
		return 7;
		break;

	case '=':
		return 8;
		break;

	case '#':
		return 9;
		break;

	default:
		break;
	}

}


int isp(Token& t) 
{
	//in-stack priority
   //�ڵ� �Է�

	/* ty�� '('�� 9, UMINUS�� '!'�� 1,
	 '*'�� '/'�� '%'�� 2, ��+���� '-'�� 3,'<'�� '>'�� LE�� GE�� 4,
	 EQ�� NE�� 5, AND�� 6, OR�̸� 7,'='�̸� 8, '#'�� 10�� return�Ѵ�.*/
	int ty = t.type;
	switch (ty)
	{
	case '(':
		return 9;
		break;

	case '!':
	case UMINUS:
		return 1;
		break;

	case '*':
	case '/':
	case '%':
		return 2;
		break;

	case '+':
	case '-':
		return 3;
		break;

	case '<':
	case '>':
	case LE:
	case GE:
		return 4;
		break;

	case EQ:
	case NE:
		return 5;
		break;

	case AND:
		return 6;
		break;

	case OR:
		return 7;
		break;

	case '=':
		return 8;
		break;

	case '#':
		return 10;
		break;
	
	default: 
		break;
	}
}


void Postfix(Expression e) 
{
	// STL stack�̿��ϰ�, ������ ������ for���� ���� ���� �ٲ۴� */
	// while (stack.top()!='#') { cout << stack.top(); stack.pop(); }
	// stack.pop();

	stack<Token> stack; // ������ �ʱ�ȭ

	stack.push('#');

	for (Token x = NextToken(e); x != '#'; x = NextToken(e))
	{

		if (x.IsOperand())  //��ū�� �ǿ������� ��� �׳� ���
			cout << x;

		else if (x == ')') //��ū�� )�ϰ�� ( ���� ������ ����ϰ� pop
		{// unstack until ��(��
			for (; stack.top() != '('; stack.pop())
				cout << stack.top();


			stack.pop(); // unstack ��(��
		}

		else //�������� ��� �켱���� �� ���� ����
		{ // x is an operator

			for (; isp(stack.top()) <= icp(x); stack.pop()) //���� �ȿ� �ִ� �������� �켱������ ������ �������� �켱�������� �۰ų� ���� ��� - �� ���� �� �����ڰ� �� ���� �� ��� ����ϰ� pop����
			{	
				if (x == '=' && stack.top() == '=') //�������� ��Ȳ -> ����� ������ =�� ���� ���߿� ��Ÿ�� =�� ���� �� ���Ƿ� ���ÿ� push���־����
				{
					break;
				}

				cout << stack.top();
			}

			stack.push(x); //������ �����ڰ� �켱������ �� ���� ��� -> stack�� push���� 
		}
	}
		// end of expression; empty the stack
	 while (stack.top()!='#') 
	 { 
		 cout << stack.top(); 
		 stack.pop(); 
	 }

	 stack.pop(); //#��ū pop

	cout << endl;
}

