#ifndef __MOVIE_H__
#define __MOVIE_H__


/*
클래스 이름 : Movie <Entity 클래스>
클래스 멤버 변수:  movieName / movieDirector / movieGenre / movieInfoStr 

기능 : 영화에 대한 다음과 같은 기능을 구현함

	 < private 멤버함수 >
	 1. char* getMovieDirector()
	   -> 영화 감독 이름 정보를 반환한다.
	
	 2. char* getMovieGenre()
	   -> 영화의 장르 정보를 반환한다.

	< public 멤버함수 >
	 1. Movie(const char* mName, const char* mDirector, const char* mGenre)
	   -> 영화의 제목, 영화 감독, 영화 장르 정보를 받아 객체를 생성한다. 영화 정보를 반환할 문자열은 객체 생성과 동시에 생성자 내에서 NULL로 초기화한다.
	 
	 2. char* getMovieName()
	   -> 영화의 제목 정보를 반환한다.
	 
	 3. char* getMovieInfo()
	   -> 영화 제목, 영화 감독, 영화 장르 정보를 포함한 문자열을 반환한다.
	 
	 4. ~Movie()
	   -> 소멸자를 통해 동적할당한 메모리를 해제한다.

작성날짜 : 2021/05/31
작성자 : 박시홍
*/
class Movie
{
private:
	char* movieName;
	char* movieDirector;
	char* movieGenre;
	char* movieInfoStr; //영화 정보를 반환할 문자열
	

	char* getMovieDirector();

	char* getMovieGenre();


public:
	Movie(const char* mName, const char* mDirector, const char* mGenre);

	char* getMovieName();

	char* getMovieInfo(); //영화 정보 문자열 반환 함수

	~Movie();
};
#endif