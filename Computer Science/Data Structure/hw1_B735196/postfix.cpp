//B735196 박시홍
#include <iostream>
#include "post.h"

using namespace std;

void Postfix(Expression);
int main()
{
	char line[MAXLEN]; //버퍼(최대 입력받을 수 있는 문자 80개)
	
	while (cin.getline(line, MAXLEN)) //키보드에 입력받은 것을 line씩 가져옴
	{
		Expression e(line); //수식 e생성(lne 버퍼를 이용하여 Expression을 만듦) -> 여기서 e는 중위표기식
		
		try 
		{
			Postfix(e); //후위표기식으로 변환
		}

		catch (char const* msg) //예외처리 메커니즘
		{
			cerr << "Exception: " << msg << endl; //예외 발생 출력
		}
	}
}