#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Client.h" //헤더파일 Client.h를 불러온다.
#include "Movie.h" //헤더파일 Movie.h를 불러온다.
#include "TicketingManagement.h" //헤더파일 TicketingManagement.h를 불러온다.
#include <cstring>

using namespace std;


/* 함수이름: main
   기능: 영화 예매 시스템을 실행하는 기능을 수행한다.
	  <상세기능>
	   - clientArr는 Client 객체들을 담고 있다.
	   - movieArr는 Movie 객체들을 담고 있다. 
	   - 회원 객체 포인터 배열, 회원의 수, 영화 객체 포인터 배열, 영화의 수를 매개변수로 전달하며 TicketingManagement 객체 1개 생성한 뒤, 생성된 객체의 멤버함수 run을 호출함으로써 예매 시스템이 작동되도록 명령한다.
   
   매개변수: 없음
   반환값: 0이면 정상 종료, 그 외의 값이 반환되면 비정상 종료된다.

   작성날짜 : 2021/05/31
   작성자 : 박시홍
*/
int main(void)
{

	Client* clientArr[2];  //크기가 2인 Client 객체의 포인터 배열 clienArr 선언
	Movie* movieArr[4]; //크기가 4인 Movie 객체의 포인터 배열 movieArr 선언

	for (int i = 0; i < 2; i++)
	{
		clientArr[i] = NULL; //회원 객체 포인터 배열의 요소들을 NULL로 초기화
	}

	for (int i = 0; i < 4; i++)
	{
		movieArr[i] = NULL; //영화 객체 포인터 배열의 요소들을 NULL로 초기화
	}


	/*
	 회원 정보 입력(하드코딩)
	*/
	clientArr[0] = new Client("Kim", "ID_Kim", "PW_Kim", "010-1234-5678");
	clientArr[1] = new Client("Lee", "ID_Lee", "PW_Lee", "010-9876-5432");

	/*
	 영화 정보 입력(하드코딩)
	*/
	movieArr[0] = new Movie("Show", "Park", "Drama");
	movieArr[1] = new Movie("Brother", "Hong", "Action");
	movieArr[2] = new Movie("WayOut", "Kang", "Mystery");
	movieArr[3] = new Movie("Call", "Ryu", "History");

	TicketingManagement ticketManager(clientArr, 2, movieArr, 4); //회원 객체 포인터 배열, 회원의 수, 영화 객체 포인터 배열, 영화의 수를 매개변수로 전달하며 TicketingManagement 객체 생성
	
	ticketManager.run(); //ticketManager의 멤버함수 run 실행
	
	for (int i = 0; i < 2; i++) //동적할당한 회원 객체 메모리들을 해제시킨다.
	{
		delete clientArr[i];
	}

	for (int i = 0; i < 4; i++) //동적할당한 영화 객체 메모리들을 해제시킨다.
	{
		delete movieArr[i];
	}

	return 0;

}