#include "Book.h"
#include "Library.h"
#include <iostream>

using namespace std;



/*
함수 이름: main
기능: Library 객체가 10개의 Book 객체를 저장하고 관리한다.
매개변수: 없음
반환값: int -> 0 이면 프로그램이 종료된다.

작성날짜: 2021/04/11
작성자: 박시홍
*/
int main(void)
{
	Library lib("Hongik Library"); //Library 객체 생성, 매개변수로 Hongik Library를 받아 lib 객체를 생성과 동시에 초기화를 진행함.


	int menuSelect;       //메뉴의 번호를 선택하는 변수 선언
	bool loopStop = false;  //while 루프를 빠져나오기 위한 변수 선언. loopStop -> true : 계속 while문 실행, loopStop -> false : while문 탈출
	                                                              

	lib.bookRegister("Bird", "Kim", 2010, 234);    // 도서 등록을 진행함, 도서의 정보를 받아 bookRegister함수를 통해 도서 객체를 생성하고 초기화한다.
	lib.bookRegister("Dog", "Lee", 2011, 342);     // 도서 등록을 진행함, 도서의 정보를 받아 bookRegister함수를 통해 도서 객체를 생성하고 초기화한다.
  	lib.bookRegister("Hippo", "Park", 2015, 112);  // 도서 등록을 진행함, 도서의 정보를 받아 bookRegister함수를 통해 도서 객체를 생성하고 초기화한다. 



	while (1)
	{
		cout << "메뉴: " << endl;
		cout << "1. 도서 대여" << endl;
		cout << "2. 도서 대여 통계" << endl;
		cout << "3. 종료하기" << endl;
		cout << "* 연산을 입력하십시오: ";
		
		cin >> menuSelect;

		switch (menuSelect) //입력받은 메뉴 번호를 바탕으로, 번호에 해당하는 메뉴의 기능을 수행하도록 switch 문을 구현함.
		{
			case 1:
			{

				lib.bookRental_Possible(); //bookRental_Possible 함수와 bookRental 함수를 순차적으로 호출함으로써 도서 대여 기능을 수행함.
				lib.bookRental();

				cout << endl << endl;
				break;

			}
			case 2:
			{
				lib.bookRental_Statistics();  //bookRental_Statistics 함수를 호출함으로써 도서 대여 통계 출력 기능을 수행함.
				
				cout << endl << endl;
				break;
			}
			case 3:
			{
				cout << " - 종료합니다." << endl;
				loopStop = true;  //사용자가 3번을 고르면 loopStop 변수가 true가 되고, 이를 통해 while문을 빠져나온다.
				break;
			}

		}
		if (loopStop == true) //while문 탈출
			break;
	}
	return 0;


}
