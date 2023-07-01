#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

/*
함수 이름: Book
기능: Book 클래스의 생성자로써의 기능을 수행한다. 또한 객체 생성과 동시에 책의 대여 여부를 나타내는 값인 bookState값은 true로 초기화한다.
매개변수: const char* bName -> 도서의 제목
         const char* bAuthor -> 저자의 이름
		 int bYear -> 도서의 출판 연도
		 int bPage -> 도서의 페이지 수

반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
Book::Book(const char* bName, const char* bAuthor, int bYear, int bPage)
{
	int nLen = strlen(bName) + 1;
	int aLen = strlen(bAuthor) + 1;
	
	bookName = new char[nLen];
	strcpy(bookName, bName);
		
	bookAuthor = new char[aLen];
	strcpy(bookAuthor, bAuthor);
		
	bookPage = bPage;
	bookYear = bYear;
	bookState = true; 

}



/*
함수 이름: getBookName
기능: 멤버변수 bookName의 값을 반환한다.
매개변수: 없음
반환값: 도서의 제목

작성날짜: 2021/04/11
작성자: 박시홍
*/
char* Book::getBookName() const
{
	return bookName;
}



/*
함수 이름: getBookAuthor
기능: 멤버변수 bookAuthor의 값을 반환한다.
매개변수: 없음
반환값: 도서의 저자 이름

작성날짜: 2021/04/11
작성자: 박시홍
*/
char* Book::getBookAuthor() const
{
	return bookAuthor;
}



/*
함수 이름: getBookYear
기능: 멤버변수 bookYear의 값을 반환한다.
매개변수: 없음
반환값: 도서의 출판 연도 정보

작성날짜: 2021/04/11
작성자: 박시홍
*/
int Book::getBookYear() const
{
	return bookYear;
}



/*
함수 이름: getBookPage
기능: 멤버변수 bookPage의 값을 반환한다.
매개변수: 없음
반환값: 도서의 페이지 수 정보

작성날짜: 2021/04/11
작성자: 박시홍
*/
int Book::getBookPage() const
{
	return bookPage;
}



/*
함수 이름: getBookState
기능: 멤버변수 bookState의 값을 반환한다.
매개변수: 없음
반환값: 도서의 책 대여 여부 값 -> true: 현재 책이 대여 가능함
                              false: 현재 책 대여가 불가능함

작성날짜: 2021/04/11
작성자: 박시홍
*/
bool Book::getBookState()
{
	return bookState;
}


/*
함수 이름: changeBookState
기능: 멤버변수 bookState의 값을 변경한다.
      책 대여 여부 값이 true이면 false를 반환하도록, 
	  책 대여 여부 값이 false이면 true를 반환하도록 하는 기능을 수행한다.
     
매개변수: 없음
반환값: 변경된 도서의 책 대여 여부 값 

작성날짜: 2021/04/11
작성자: 박시홍
*/
bool Book::changeBookState()
{
	if (bookState == true)
	{
		bookState = false;
		return bookState;
	}
		
	else
	{
		bookState = true;
		return bookState;
	}

}


/*
함수 이름 ~Book
기능: Book 클래스의 소멸자로서의 기능을 수행한다. 생성자에서 동적할당한 메모리를 소멸시켜준다.
매개변수: 없음
반환값: 없음

작성날짜: 2021/04/11
작성자: 박시홍
*/
Book::~Book()
{
	delete[] bookAuthor; 
	delete[] bookName;
}
