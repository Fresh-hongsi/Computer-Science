#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Client.h" //헤더파일 Client.h를 불러온다.

using namespace std;

/*
   함수이름: 클래스 Client의 생성자
   기능 :  Client 클래스의 생성자로써의 기능을 수행한다. 
          생성자 호출을 통해 Client의 멤버 변수 name / ID / PW / phoneNum을 인자로 전달된 값으로 각각 동적할당하여 초기화한다.
          또한 객체 생성과 동시에 회원의 로그인 상태 여부를 나타내는 값은 false, 회원이 예매한 영화 숫자 인덱스 값은 0, 회원이 예매한 영화 리스트인 myMovieList(객체 포인터 배열)은 NULL값으로 초기화한다.
		  

   매개변수 : const char* cName -> 회원의 이름
             const char* cID -> 회원의 ID
			 const char* cPW -> 회원의 패스워드
	         const char* cPhoneNum -> 회원의 휴대폰 번호
			 

   반환값 : 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
Client::Client(const char* cName, const char* cID, const char* cPW, const char* cPhoneNum)
{
	name = new char[strlen(cName) + 5];
	strcpy(name, cName);

	ID = new char[strlen(cID) + 5];
	strcpy(ID, cID);

	PW = new char[strlen(cPW) + 5];
	strcpy(PW, cPW);

	phoneNum = new char[strlen(cPhoneNum) + 5];
	strcpy(phoneNum, cPhoneNum);


	for (int i = 0; i < 10; i++)
	{
		myMovieList[i] = NULL;
	}

	myMovieIdx = 0;
	LogInStatus = false;

}


/*
   함수이름: getClientName
   기능: 멤버변수 name에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: name

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Client::getClientName()
{
	return name;
}


/*
   함수이름: getClientID
   기능: 멤버변수 ID에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: ID

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Client::getClientID()
{
	return ID;
}


/*
   함수이름: getClientPW
   기능: 멤버변수 PW에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: PW

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Client::getClientPW()
{
	return PW;
}


/*
   함수이름: getClientPhoneNum
   기능: 멤버변수 phoneNum에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: phoneNum

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Client::getClientPhoneNum()
{
	return phoneNum;
}


/*
   함수 이름: getLogInStatus
   기능: 멤버변수 LogInStatus의 값을 반환한다.
   매개변수: 없음
   반환값: 회원의 로그인 상태 여부 값 -> true: 현재 로그인이 완료됨
									 false: 현재 로그인이 되지 않음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
bool Client::getLogInStatus()
{

	return LogInStatus;
}


/*
   함수 이름: changeLogInStatus
   기능: 멤버변수 LogInStatus의 값을 변경한다.
	  로그인 상태 여부 값이 true이면 false를 반환하도록,
	  로그인 상태 여부 값이 false이면 true를 반환하도록 하는 기능을 수행한다.

   매개변수: 없음
   반환값: 변경된 회원의 로그인 상태 여부 값

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void Client::changeLogInStatus()
{
	if (LogInStatus == false) //로그인이 되지 않았었다면
	{
		this->LogInStatus = true; //로그인 상태를 로그인 완료로 변경 (로그인 승인)

	}

	else //로그인이 되어있었다면
	{
		this->LogInStatus = false; //로그인 상태를 로그인 되지 않음으로 변경 (로그아웃 기능)
	}
	

}


/*
   함수이름: getMyMovieIdx
   기능: 멤버변수 myMovieIdx에 저장된 값을 반환한다.      
   매개변수: 없음
   반환값: myMovieIdx

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
int Client::getMyMovieIdx()
{
	return myMovieIdx;
}


/*
   함수이름: addMovie
   기능: 회원의 영화 리스트에 회원이 예매한 영화를 추가한다.
        즉, Client 객체의 멤버인 Movie* myMovieList[10]에 Movie객체를 담는다. Movie객체가 myMovieList 배열에 저장되면, 영화 숫자 인덱스는 1 증가시켜 놓는다.
   매개변수: Movie* myMovie
   반환값: 없음
  
   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void Client::addMovie(Movie* myMovie)
{
	myMovieList[myMovieIdx] = myMovie;
	myMovieIdx++;
}


/*
   함수이름: showMyMovieList
   기능 : myMovieList에 있는 영화들의 정보(영화 이름, 영화 감독, 영화 장르)가 담긴 문자열을 모두 출력한다.
   매개변수 : 없음
   반환값 : 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
void Client::showMyMovieList()
{
	for (int i = 0; i < myMovieIdx; i++)
	{
		cout << " -> " << myMovieList[i]->getMovieInfo();
		cout << endl;
	}
}


/*
   함수이름: 클래스 Client의 소멸자
   기능 : Client 객체가 소멸될 때 호출된다.
		 동적할당한 회원 이름, 회원의 ID, 회원의 패스워드, 회원의 휴대폰 번호 메모리들을 해제시켜준다.
   매개변수 : 없음
   반환값 : 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
Client::~Client()
{
	delete[]name;
	delete[]PW;
	delete[]ID;
	delete[]phoneNum;
}