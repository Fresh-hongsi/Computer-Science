#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Movie.h" //헤더파일 Movie.h를 불러온다.

using namespace std;


/*
   함수이름: 클래스 Movie의 생성자
   기능 :  Movie 클래스의 생성자로써의 기능을 수행한다.
          생성자 호출을 통해 Movie의 멤버 변수 movieName / movieDirector / movieGenre를 인자로 전달된 값으로 각각 동적할당하여 초기화한다.
		  또한 객체 생성과 동시에 영화 정보를 반환할 문자열인 movieInfoStr은 NULL값으로 초기화한다.


   매개변수 : const char* mName -> 영화의 제목
			 const char* mDirector -> 영화 감독 이름
			 const char* mGenre -> 영화의 장르
			 
   반환값 : 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
Movie::Movie(const char* mName, const char* mDirector, const char* mGenre)
{
	movieName = new char[strlen(mName) + 5];
	strcpy(movieName, mName);

	movieDirector = new char[strlen(mDirector) + 5];
	strcpy(movieDirector, mDirector);

	movieGenre = new char[strlen(mGenre) + 5];
	strcpy(movieGenre, mGenre);

	movieInfoStr = NULL;
}



/*
   함수이름: getMovieName
   기능: 멤버변수 movieName에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: movieName

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Movie::getMovieName()
{
	return movieName;
}


/*
   함수이름: getMovieDirector
   기능: 멤버변수 movieDirector에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: movieDirector

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Movie::getMovieDirector()
{
	return movieDirector;
}


/*
   함수이름: getMovieGenre
   기능: 멤버변수 movieGenre에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: movieGenre

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Movie::getMovieGenre()
{
	return movieGenre;
}


/*
   함수이름: getMovieInfo
   기능: 멤버 변수 movieInfoStr에 영화 제목, 영화 감독, 영화 장르 정보를 포함한 문자열을 저장하고, 이를 반환한다.
   매개변수: 없음
   반환값: movieInfoStr

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
char* Movie::getMovieInfo()
{
	char movieInfoArr[50] = { 0, };

	sprintf(movieInfoArr, "%s, %s, %s", this->getMovieName(), this->getMovieDirector(), this->getMovieGenre());

	movieInfoStr = new char[strlen(movieInfoArr) + 5];

	strcpy(movieInfoStr, movieInfoArr);

	return movieInfoStr;
}



/*
   함수이름: 클래스 Movie의 소멸자
   기능 : Movie 객체가 소멸될 때 호출된다.
		 동적할당한 영화 제목, 영화 감독, 영화 장르, 영화 정보 문자열 메모리들을 해제시켜준다.
   매개변수 : 없음
   반환값 : 없음

   작성날짜: 2021/05/31
   작성자: 박시홍
*/
Movie::~Movie()
{
	delete[]movieName;
	delete[]movieDirector;
	delete[]movieGenre;
	delete[]movieInfoStr;
}