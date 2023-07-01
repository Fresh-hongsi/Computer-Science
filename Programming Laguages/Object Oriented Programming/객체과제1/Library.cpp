#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Library.h"

using namespace std;

/*
함수 이름: Library
기능: Library 클래스의 생성자로서의 기능을 수행한다. 
     객체 생성 시에 도서관의 이름, 도서 객체 배열, 도서 추가 가능한 인덱스 값을 초기화한다.
매개변수: char* lName -> 도서관 이름
반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
Library::Library(const char* lName) :bookNum(0)
{

	int lLen = strlen(lName + 1);
	strcpy(libraryName, lName);

	for (int i = 0; i < 10; i++)
	{
		bArr[i] = NULL;
	}
}
	

/*
함수 이름: bookRegister (도서 등록 함수)
기능: 도서의 제목, 저자 이름, 출판 연도, 페이지수 정보를 받아 Book 객체를 동적으로 할당하여 초기화한 후, Book 객체 포인터 배열에 순차적으로 Book객체의 주소값을 저장한다.
     또한 Book 객체가 배열에 저장될 때마다 도서 추가 가능한 인덱스 값을 1씩 증가시킨다.

매개변수: const char* title -> 도서의 제목
		 const char* name -> 저자의 이름
		 int year -> 도서의 출판 연도
		 int page -> 도서의 페이지 수
반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
void Library::bookRegister(const char* title, const char* name, int year, int page) 
{
	bArr[bookNum] = new Book(title, name, year, page);
	bookNum++; //도서가 한권 등록되었으므로 도서 추가 가능한 인덱스 번호는 미리 1 증가시켜놓는다.
}


/*
함수 이름: bookRental_Possible (대여 가능한 도서 목록 출력 함수)
기능: Book 객체 포인터 배열에 저장된 Book 객체들이 대여 가능한 상태라면, 도서 제목, 저자 이름, 출판 연도, 페이지 수 정보들을 get함수로 반환받은후 출력한다.
     
매개변수: 없음
반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
void Library::bookRental_Possible() 
{

	for (int i = 0; i < bookNum; i++)
	{

		if (bArr[i]->getBookState() == true) //해당 도서가 대여 가능한 상태인지 확인한다. 대여 가능(true)하면 해당 도서의 정보를 출력한다. 
		{
			cout << ' ' << i + 1 << ')';
			cout << bArr[i]->getBookName() << ", ";
			cout << bArr[i]->getBookAuthor() << ", ";
			cout << bArr[i]->getBookYear() << ", ";
			cout << bArr[i]->getBookPage();
			cout << endl;


		}

	}
}



/*
함수 이름: bookRental (도서 대여 함수)
기능: 

     1. 사용자에게 대여 신청할 도서의 번호를 입력받아 도서 대여를 진행한다. 이후 대여 신청한 도서의 정보를 출력한다.
     2. 대여 완료된 도서는 도서 대여 여부 값을 (true 에서 false로) 변경해준다.
	 3. 도서 포인터 객체 배열에서 도서의 대여 여부에 따라 정렬을 해준다.
		- 도서 인덱스 값(bookNum)을 기점으로 인덱스 앞은 현재 대여 가능한 도서, 인덱스부터는 대여 완료된 도서가 배열에 자리하도록 Book형 포인터로 Swap기능을
		  사용함으로써 구현하였다. 

매개변수: 없음
반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
void Library::bookRental(void) 
{
	int n;

	cout << "* 대여할 도서 번호를 입력하시오: ";
	cin >> n;

	if (bArr[n-1]->getBookState() == false)
	{
		cout << "잘못된 번호 입력! " << endl << endl;
		return;
	}

	cout << "- ";
	cout << bArr[n - 1]->getBookName();
	cout << ", ";
	cout << bArr[n - 1]->getBookAuthor();
	cout << ", ";
	cout << bArr[n - 1]->getBookYear();
	cout << ", ";
	cout << bArr[n - 1]->getBookPage();
	cout << endl;

	bArr[n - 1]->changeBookState(); //책이 대여 완료되었으므로 책의 대여(존재) 여부 값은 false가 된다.

	for (int i = n - 1; i < bookNum - 1; i++) //Swap을 사용하여 대여 가능 도서와 대여 불가능한 도서를 인덱스 값을 기점으로 정렬을 진행한다.
	{
		Book* temp = bArr[i]; 
		bArr[i] = bArr[i + 1]; 
		bArr[i + 1] = temp;
	}
	bookNum--; //도서가 대여되었으므로 도서 인덱스 값은 1만큼 줄어든다.

}


/*
함수 이름: bookRental_Statistics (대여된 도서 통계 출력 함수)
기능:

	 1. 전체 도서에서 대여된 도서의 수와 대여된 도서의 페이지 수 합을 출력한다.
	  - 대여된 도서와 대여되지 않은 도서는 getBookState 함수로부터 반환받은 대여여부 값을 바탕으로 구분한다. 
	  - 도서 대여 여부가 false이면, 대여된 도서의 수와 대여된 페이지 수의 합 계산을 진행한다.

매개변수: 없음
반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
void Library:: bookRental_Statistics(void)
{
	int rented_book = 0; //현재까지 대여된 도서의 수
	int rented_pageSum = 0; //현재까지 대여된 도서의 페이지 수 합

	for (int i = 0; i < 3; i++)
	{
		if (bArr[i]->getBookState() == false)
		{
			rented_book++;
			rented_pageSum += bArr[i]->getBookPage();
		}

	}
	cout << " - 도서 대여 수 : " << rented_book << endl;
	cout << " - 대여 도서 페이지 수 합 : " << rented_pageSum;
	

}


/*
함수 이름 ~Library
기능: Library 클래스의 소멸자로서의 기능을 수행한다. 생성자에서 동적할당한 메모리를 소멸시켜준다.
매개변수: 없음
반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
Library::~Library()
{
	for (int i = 0; i < 3; i++)
	{
		delete bArr[i];
	}
	
}



