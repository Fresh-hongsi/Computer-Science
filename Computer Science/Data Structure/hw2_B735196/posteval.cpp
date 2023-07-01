//B735196 박시홍

#include <iostream>
#include "post.h"

using namespace std;

void Eval(Expression); 

int main(void)
{
	char line[MAXLEN]; //버퍼(최대 입력받을 수 있는 문자 80개)

	while (cin.getline(line, MAXLEN)) //키보드에 입력받은 것을 line씩 가져옴
	{
		Expression e(line); // Assume postfix notation // 수식 e생성(lne 버퍼를 이용하여 Expression을 만듦) -> 여기서 e는 후위표기식

		try
		{
			Eval(e); //수식 계산
		}

		catch (char const* msg) //예외 발생 출력
		{
			cerr << "Exception: " << msg << endl;
		}
	}
}