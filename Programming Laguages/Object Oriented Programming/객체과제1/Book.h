#ifndef __BOOK_H__
#define __BOOK_H__

/*
클래스 이름 : Book
기능 : 도서에 대한 다음과 같은 기능을 구현함

     1. 도서의 제목, 저자 이름, 출판 연도, 페이지 수 정보를 받아 객체를 생성한다. 또한 도서 대여 여부를 나타내는 값은 객체 생성과 동시에 초기화한다. 
     2. 도서의 제목을 반환한다.
     3. 도서의 저자 이름을 반환한다.
	 4. 도서의 출판 연도를 반환한다.
	 5. 도서의 페이지 수 정보를 반환한다.
	 6. 도서의 대여 여부 값을 반환한다.
	 7. 도서의 대여 여부 값을 변경한다.

작성날짜 : 2021/04/11
작성자 : 박시홍
*/


class Book
{
private:
	char* bookName; //책 제목
	char* bookAuthor; //책 저자이름
	int bookYear; //책 출판연도
	int bookPage; //책 페이지 수
	bool bookState; //책 대여여부를 나타내는 값


public:
	Book(const char* bName, const char* bAuthor, int bYear, int bPage);

	char* getBookName() const;
	
	char* getBookAuthor() const;
	
	int getBookYear() const;

	int getBookPage() const;
	
	bool getBookState();

	bool changeBookState();
	
	~Book();
	
};

#endif