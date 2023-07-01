#include <iostream>
#include <stack>
#include "post.h"

using namespace std;

bool Token::operator==(char b) //토큰이 #인지 아닌지 구분 -> token의 길이가 1이고 #이면 true반환
{ 
	return len == 1 && str[0] == b; 
}

bool Token::operator!=(char b) //토큰이 #과 다른지 확인 -> token의 길이가 1이 아니거나, token의 첫번째 문자가 #이 아니면 true반환
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

	if (type == NUM) //type이 연산자 중 숫자라면 해당 토큰의 정수값을 계산해서 ival에 저장한다. 해당 숫자의 문자값은 str에 담겨있음
	{
		ival = arr[0] - '0';
		for (int i = 1; i < len; i++) 
			ival = ival * 10 + arr[i] - '0';
	}

	else if (type == ID) //type이 연산자 중 변수라면 해당 토큰의 ival값을 0으로 만든다
		ival = 0;

	else 
		throw "must be ID or NUM";
}

bool Token::IsOperand() //토큰의 type이 피연산자 (변수이거나 숫자)이면 true반환 
{ 
	return type == ID || type == NUM; 
}

ostream& operator<<(ostream& os, Token t) 
{
	if (t.type == UMINUS)  //unary - 연산자일 경우 -u출력
		os << "-u";

	else if (t.type == NUM) //숫자 토큰(피연산자)을 출력할 경우 문자열이 아닌 숫자를 출력
		os << t.ival;

	else //그 외의 경우 토큰에 저장된 문자열 값을 출력
		for (int i = 0; i < t.len; i++) 
			os << t.str[i];
	
	os << " "; //출력 때마다 공백 추가

	return os;
}

bool GetID(Expression& e, Token& tok) //ID 문자열이면 내용을 읽어서 tok에 저장
{
	char arr[MAXLEN]; int idlen = 0;
	char c = e.str[e.pos]; //해당 인덱스에서 시작하는 하나의 문자를 c에 저장

	if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')) //c값이 문자값이 아니면
		return false; //ID값이 아니므로 false반환

	arr[idlen++] = c; //c값을 arr배열에 저장
	e.pos++; //수식 인덱스 위치 하나 증가

	while ((c = e.str[e.pos]) >= 'a' && c <= 'z'|| c >= 'A' && c <= 'Z'	|| c >= '0' && c <= '9') //ID 성분이 끝날 때까지
	{
		arr[idlen++] = c; e.pos++; //arr배열에 저장하는 과정
	}

	arr[idlen] = '\0'; //ID성분 다 끝났으면 널문자 삽입을 통해 문자열로 만들어줌

	tok = Token(arr, idlen, ID); // return an ID (토큰을 ID로 초기화)

	return true;
}

bool GetInt(Expression& e, Token& tok) //NUM 문자열이면 내용을 읽어서 tok에 저장
{
	//코드 입력
	char arr[MAXLEN]; int idlen = 0;
	char c = e.str[e.pos]; //해당 인덱스에서 시작하는 하나의 문자를 c에 저장
	 
	if (!(c >= '0' && c <= '9')) //c값이 숫자값이 아니라면
		return false; //NUM이 아니므로 false반환

	arr[idlen++] = c; //c값을 arr배열에 저장
	e.pos++; //수식 인덱스 위치 하나 증가

	while ((c = e.str[e.pos]) >= '0' && c <= '9' ) //NUM 성분이 끝날 때까지
	{
		arr[idlen++] = c; e.pos++; //arr배열에 저장하는 과정
	}

	arr[idlen] = '\0';
	tok = Token(arr, idlen, NUM); // return an NUM(토큰을 NUM으로 초기화)

	return true;
}

void SkipBlanks(Expression& e) //수식이 아직 남아있고, 현재 위치의 인덱스의 문자값이 공백이거나 tab이면 skip하고 넘어감
{
	char c;
	while (e.pos < e.len && ((c = e.str[e.pos]) == ' ' || c == '\t'))
		e.pos++;
}


bool TwoCharOp(Expression& e, Token& tok)
{
	//7가지 두글자 토큰(연산자)들 // <= >= == != && || -u을 처리

	char c = e.str[e.pos]; 
	char c2 = e.str[e.pos + 1];
	int op; // LE GE EQ NE AND OR UMINUS

	if (c == '<' && c2 == '=') //LE
		op = LE;

	// 코드입력: 각 두 글자 토큰(연산자)에 대해 알맞은 type값 op에 저장
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
		return false; // 맞는 두 글자 토큰이 아니면 false를 return한다.

	tok = Token(c, c2, op); //토큰을 두글자 토큰으로 초기화

	e.pos += 2; //수식 두칸 확인 성공했으므로 e.pos값 2 증가시켜준다.

	return true;
}


bool OneCharOp(Expression& e, Token& tok)
{
	//11가지 한글자 연산자들 // -, !, *, /, %. +. <, >, (, ), = 들을 처리
	char c = e.str[e.pos];

	if (c == '-' || c == '!' || c == '*' || c == '/' || c == '%' ||
		c == '+' || c == '<' || c == '>' || c == '(' || c == ')' || c == '=')
	{
		tok = Token(c); //토큰을 한글자 토큰으로 초기화

		e.pos++; //수식 두칸 확인 성공했으므로 e.pos값 1 증가시켜준다

		return true;
	}

	return false;
}


Token NextToken(Expression& e, bool INFIX = true)
{
	static bool oprrFound = true; // 종전에 연산자 발견되었다고 가정.
	
	Token tok;

	SkipBlanks(e); // skip blanks if any
	
	if (e.pos == e.len) // No more token left in this expression
	{
		if (INFIX) 
			oprrFound = true; 
		
		return Token('#'); //수식 끝났으므로 #토큰 반환
	}


	if (GetID(e, tok) || GetInt(e, tok)) //읽어들인 게 ID나 NUM이라면(피연산자)
	{
		if (INFIX) 
			oprrFound = false; //연산자가 아니므로 oprrFound는 false
		
		return tok;
	}


	if (TwoCharOp(e, tok) || OneCharOp(e, tok))  //읽어들인게 연산자라면
	{
		if (tok.type == '-' && INFIX && oprrFound) // operator 후 -발견 (이 수식이 중위표기식이고, 새로 읽어들인 토큰이 '-'이고, 전에 읽어들인게 연산자라면)
			tok = Token('-', 'u', UMINUS); // unary minus(-u)로 바꾸시오
		
		if (INFIX) 
			oprrFound = true; //연산자이므로 oprrFound는 true
		
		return tok;
	}

	throw "Illegal Character Found";
}


int icp(Token& t) 
{ 
	// in-coming priority
	int ty = t.type;

	/* ty가 '('면 0, UMINUS나 '!'면 1,
	 '*'나 '/'나 '%'면 2, ‘+’나 '-'면 3,'<'나 '>'나 LE나 GE면 4,
	 EQ나 NE면 5, AND면 6, OR이면 7,'='이면 8, '#'면 9를 return한다.*/

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
   //코드 입력

	/* ty가 '('면 9, UMINUS나 '!'면 1,
	 '*'나 '/'나 '%'면 2, ‘+’나 '-'면 3,'<'나 '>'나 LE나 GE면 4,
	 EQ나 NE면 5, AND면 6, OR이면 7,'='이면 8, '#'면 10를 return한다.*/
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
	// STL stack이용하고, 교재의 마지막 for문을 다음 같이 바꾼다 */
	// while (stack.top()!='#') { cout << stack.top(); stack.pop(); }
	// stack.pop();

	stack<Token> stack; // 스택의 초기화

	stack.push('#');

	for (Token x = NextToken(e); x != '#'; x = NextToken(e))
	{

		if (x.IsOperand())  //토큰이 피연산자일 경우 그냥 출력
			cout << x;

		else if (x == ')') //토큰이 )일경우 ( 만날 때까지 출력하고 pop
		{// unstack until ‘(‘
			for (; stack.top() != '('; stack.pop())
				cout << stack.top();


			stack.pop(); // unstack ‘(‘
		}

		else //연산자일 경우 우선순위 비교 연산 진행
		{ // x is an operator

			for (; isp(stack.top()) <= icp(x); stack.pop()) //스택 안에 있는 연산자의 우선순위가 들어오는 연산자의 우선순위보다 작거나 같을 경우 - 즉 스택 안 연산자가 더 힘이 셀 경우 출력하고 pop진행
			{	
				if (x == '=' && stack.top() == '=') //예외적인 상황 -> 우결합 연산자 =의 경우는 나중에 나타난 =의 힘이 더 세므로 스택에 push해주어야함
				{
					break;
				}

				cout << stack.top();
			}

			stack.push(x); //들어오는 연산자가 우선순위가 더 높을 경우 -> stack에 push진행 
		}
	}
		// end of expression; empty the stack
	 while (stack.top()!='#') 
	 { 
		 cout << stack.top(); 
		 stack.pop(); 
	 }

	 stack.pop(); //#토큰 pop

	cout << endl;
}

