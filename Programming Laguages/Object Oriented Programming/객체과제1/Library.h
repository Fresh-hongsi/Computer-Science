#ifndef __LIBRARY_H__
#define __LIBRARY_H__
#include "Book.h"



/*
클래스 이름 : Library
기능 : 도서관에 대한 다음과 같은 기능을 구현함

     1. 생성자를 통해 도서관의 이름, 도서 객체 포인터 배열, 도서 추가 가능한 인덱스 번호값을 초기화한다.
	 2. 도서의 제목, 저자 이름, 출판 연도, 페이지 수를 받아서 도서 객체를 동적할당하여 초기화한 후, 도서 객체 포인터 배열에 주소값을 넣음으로써 도서를 등록한다.
	 3. 대여 가능한 도서의 정보를 출력한다.
	 4. 대여할 도서의 번호를 입력받아 도서의 대여를 진행한다. 도서의 대여가 완료되면 해당 도서의 정보를 출력한다. 
	 5. 대여된 도서들의 통계 정보를 출력한다. 즉, 대여 완료된 도서의 수와 대여 완료된 도서들의 페이지 수 합계 정보를 출력한다.
	

작성날짜 : 2021/04/11
작성자 : 박시홍
*/
class Library
{
private:
	char libraryName[20]; //도서관 이름
	Book* bArr[10]; //도서 객체 포인터 배열
	int bookNum; //도서 추가 가능한 현재 인덱스 번호

public:
	Library(const char* lName);
	
	
	void bookRegister(const char* title, const char* name, int year, int page);  //도서 등록 함수
	
	void bookRental_Possible(); //대여 가능한 도서 목록 출력 함수
	
	void bookRental(void); //도서 대여 함수
	
	void bookRental_Statistics(void); //대여된 도서 통계 출력 함수
	
	~Library();

};

#endif