#ifndef __CLIENT_H__
#define __CLIENT_H__
#include "Movie.h"


/*
클래스 이름 : Client <Entity 클래스>
클래스 멤버 변수:  name / ID / PW / phoneNum / LogInStatus / myMovieIdx / myMovieList 

기능 : 회원에 대한 다음과 같은 기능을 구현함

	< private 멤버함수 >
	 1. char* getClientName(): 회원의 이름을 반환한다.
	 2. char* getClientPhoneNum(): 회원의 휴대폰 번호를 반환한다.
	 3. int getMyMovieIdx(): 회원이 예매한 영화 숫자 인덱스 값을 반환한다.
	
	< public 멤버함수 >
	 1. Client(const char* cName, const char* cID, 	const char* cPW, const char* cPhoneNum)
	   -> 회원의 이름, ID, 패스워드, 휴대폰번호 정보를 받아 객체를 생성한다. 회원의 로그인 상태 여부를 나타내는 값, 회원이 예매한 영화 숫자 인덱스 값, 회원이 예매한 영화 리스트는 객체 생성과 동시에 생성자 내에서 초기화한다.
	 
	 2. char* getClientID()
	   -> 회원의 ID 정보를 반환한다.
	
	 3. char* getClientPW()
	   ->회원의 패스워드 정보를 반환한다.
	 
	 4. void changeLogInStatus()
	   -> 회원의 로그인 상태 여부 값을 반환한다. false -> 로그인이 되지 않음 / true -> 로그인이 완료

	 5. void changeLogInStatus()
	   -> 회원의 로그인 상태 여부 값을 바꿔준다.

	 6. void addMovie(Movie* myMovie)
	   -> 예매한 영화의 정보를 회원의 예매 내역에 추가한다

	 7. void showMyMovieList()
	   -> 회원의 영화 예매 내역에 있는 영화들의 정보를 출력한다.

	 8. ~Client()
	  -> 소멸자를 통해 동적할당한 메모리를 해제한다. 
	

작성날짜 : 2021/05/31
작성자 : 박시홍
*/

class Client
{
private:
	char* name; //회원의 이름
	char* ID; //회원의 ID
	char* PW; //회원의 패스워드
	char* phoneNum; //회원의 휴대폰 번호
	bool LogInStatus; //회원의 로그인 상태
	int myMovieIdx; //회원이 예매한 영화 숫자 인덱스
	Movie* myMovieList[10]; //회원이 예매한 영화 리스트
	
	char* getClientName();

	char* getClientPhoneNum();

	int getMyMovieIdx();
	
public:

	Client(const char* cName, const char* cID, 	const char* cPW, const char* cPhoneNum);

	char* getClientID();

	char* getClientPW();

	bool getLogInStatus();

	void changeLogInStatus();

	void addMovie(Movie* myMovie);

	void showMyMovieList();

	~Client();
};
#endif