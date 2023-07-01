#ifndef __TICKETINGMANAGEMENT_H__
#define __TICKETINGMANAGEMENT_H__
#include "Client.h"
#include "Movie.h"


/*
클래스 이름 : TicketingManagement <Control 클래스>
클래스 멤버 변수:  clientList / clientNum / movieList / movieNum / systemLogInStatus / userID / userPW / userMovieName


기능 : 영화 예매에 대한 다음과 같은 기능을 구현함

	< private 멤버함수 >
	 1. void showMenu(): 메뉴 창을 출력한다.
	 2. int user_selectMenu(): 사용자에게 실행할 메뉴 번호를 입력받고, 이를 반환한다.
	 3. char* user_inputID(): 사용자에게 ID를 입력받고, 이를 반환한다.
	 4. char* user_inputPW(): 사용자에게 패스워드를 입력받고, 이를 반환한다.
	 5. int user_selectMovie(): 사용자에게 예매할 영화의 번호를 입력받고, 이를 반환한다.
	 6. char* user_inputMovieName(): 사용자에게 예매할 영화의 제목을 입력받고, 이를 반환한다.
	 7. bool checkSystemLogInStatus(): 시스템 상 로그인이 되어있는 지 확인한다.
	 8. void stopLogIn(): 시스템상 로그인이 되어있다면, 더이상의 로그인 시도를 차단한다.
	 9. void LogIn(): 로그인 기능을 수행한다.
	 10. void showListAndTicketing(): 영화 전체 조회 및 예매 기능을 수행한다.
	 11. void searchAndTicketing(): 영화 검색 및 예매 기능을 수행한다.
	 12. void showAllTicketedMovie(): 예매된 영화 정보 조회 기능을 수행한다.
	 13. void exit(): 프로그램 종료 기능을 수행한다.

	< public 멤버함수 >
	1. TicketingManagement(Client** cList, int cNum, Movie** mList, int mNum)
	  -> 회원 리스트, 회원 수, 영화 리스트, 영화 수 정보를 받아 객체를 생성한다. 
	     시스템 상의 로그인 상태 여부 값, 사용자에게 입력받아 저장할 ID 문자열, 사용자에게 입력받아 저장할 패스워드 문자열, 사용자에게 입력받아 저장할 영화제목 문자열은 객체 생성과 동시에 생성자 내에서 초기화한다.

	2. void run()
	  -> 프로그램 내에서 로그인 / 영화 전체 조회 및 예매 / 영화 검색 및 예메 / 예매 영화 조회 / 종료하기 기능을 수행한다. 

	3. ~TicketingManagement()
	  -> 소멸자를 통해 동적할당한 메모리를 해제한다. 


작성날짜 : 2021/05/31
작성자 : 박시홍
*/
class TicketingManagement
{
private:
	Client** clientList; // clientList는 client들의 주소값을 지닌 배열(client객체 포인터 배열)의 주소를 지님.
	int clientNum; //회원의 수
	Movie** movieList; // movieList는 movie들의 주소값을 지닌 배열(client객체 포인터 배열)의 주소를 지님.
	int movieNum; //영화의 수

	bool systemLogInStatus; //시스템 상 로그인이 가능한지 확인하기 위한 변수 
	char* userID; //프로그램 사용자에게 직접 입력 받은 회원의 ID를 저장하기 위한 변수
	char* userPW; //프로그램 사용자에게 직접 입력 받은 회원의 패스워드를 저장하기 위한 변수
	char* userMovieName; //프로그램 사용자가 영화 검색할 때 입력한 영화 제목을 저장하기 위한 문자열

	void showMenu();

	int user_selectMenu();

	char* user_inputID();

	char* user_inputPW();

	int user_selectMovie();

	char* user_inputMovieName();

	bool checkSystemLogInStatus();

	void stopLogIn();

	
	void LogIn();

	void showListAndTicketing();

	void searchAndTicketing();

	void showAllTicketedMovie();

	void exit();
	

public:


	TicketingManagement(Client** cList, int cNum, Movie** mList, int mNum);

	void run();

	~TicketingManagement();



};
#endif