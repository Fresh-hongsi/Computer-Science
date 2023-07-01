#pragma once
#ifndef POST_H
#define POST_H

// token types for non one-char tokens
#define ID 257	//피연산자(변수 이름)
#define NUM 258	//피연산자(숫자)
#define EQ 259	//==연산자
#define NE 260	//!=연산자
#define GE 261	//>=연산자
#define LE 262	//<=연산자
#define AND 263	//&&연산자
#define OR 264	//||연산자
#define UMINUS 265 //-u연산자
#define MAXLEN 80 //문자열의 최대 길이

struct Expression //수식 구조체
{
	Expression(char* s) : str(s), pos(0)	//수식의 생성자, line내용을 받아와서 line내용으로 초기화
	{
		for (len = 0; str[len] != '\0'; len++); //line을 스캔하면서 문자열에 들어있는 문자의 개수를 count(널문자는 count하지 않음)
	}

	char* str; //수식 문자열
	int pos; //수식 문자 배열의 원소의 인덱스
	int len; //문자 개수
};
 
 
struct Token	//토큰 구조체
{
	bool operator==(char);	//토큰이 #인지 아닌지 구분 -> token의 길이가 1이고 #이면 true반환
	bool operator!=(char);	//토큰이 #과 다른지 확인 -> token의 길이가 1이 아니고, token의 첫번째 문자가 #이 아니면 true반환
	
	Token(); //디폴트 토큰 생성자
	Token(char);// 1-char token: type equals the token itself -문자 하나짜리 연산자일 때 사용해서 토큰 생성

	Token(char, char, int); // 2-char token(e.g. <=) & its type(e.g. LE) - 문자 두개짜리 연산자일 때 사용해서 토큰 생성

	Token(char*, int, int);//operand with its length & type(defaulted to ID) - 피연산자(변수거나 숫자)일 떄 사용해서 토큰 생성
	
	bool IsOperand(); // true if the token type is ID(변수) or NUM(숫자)

	int type; // ascii code for 1-char op; predefined for other tokens
	char* str; // token value
	int len; // length of str
	int ival; // used to store an integer for type NUM; init to 0 for ID
};


using namespace std;

ostream& operator<<(ostream& os, Token t); //토큰 출력을 위한 <<연산자 오버로딩 함수

Token NextToken(Expression&, bool); //수식을 인자로 받아와서 토큰을 하나씩 가져오기 위함 // 2nd arg인 bool type인자는 infix 수식일 경우 true임

#endif