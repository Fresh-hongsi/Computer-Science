#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h" //헤더파일 Student.h를 불러온다.

using namespace std;

/*
   함수이름: 클래스 Student의 생성자
   기능 :  Student 클래스의 생성자로써의 기능을 수행한다. 또한 객체 생성과 동시에 장학금 신청 여부를 나타내는 값인 applicationStatus값은 false로 초기화한다.

   매개변수 : const char* sName -> 학생의 이름
             int sMajorCredits -> 학생의 이수 전공학점
			 int sCulturalCredits -> 학생의 이수 교양학점
			 double sMajorGPA -> 학생의 전공 평점
			 double sCulturalGPA -> 학생의 교양 평점

   반환값 : 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
Student::Student(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA)
{
	name = new char[strlen(sName) + 5];
	strcpy(name, sName);

	majorCredits = sMajorCredits;
	culturalCredits = sCulturalCredits;
	majorGPA = sMajorGPA;
	culturalGPA = sCulturalGPA;

	applicationStatus = false;

}


/*
   함수이름: getStudentName
   기능: 멤버변수 name에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: name

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
char* Student::getStudentName() const
{
	return name;
}


/*
   함수이름: getMajorCredits
   기능: 멤버변수 majorCredits에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: majorCredits

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
int Student::getMajorCredits() const
{
	return majorCredits;
}



/*
   함수이름: getCulturalCredits
   기능: 멤버변수 culturalCredits에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: culturalCredits

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
int Student::getCulturalCredits() const
{
	return culturalCredits;
}



/*
   함수이름: getMajorGPA
   기능: 멤버변수 majorGPA에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: majorGPA

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
double Student::getMajorGPA() const
{
	
	return majorGPA;
}



/*
   함수이름: getCulturalGPA
   기능: 멤버변수 culturalGPA에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: culturalGPA

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
double Student::getCulturalGPA() const
{
	return culturalGPA;
}



/*
   함수 이름: getApplicationStatus
   기능: 멤버변수 applicationStatus의 값을 반환한다.
   매개변수: 없음
   반환값: 학생의 장학금 신청 여부 값 -> true: 현재 장학금 신청이 완료됨
							         false: 현재 장학금 신청이 되지 않음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
bool Student::getApplicationStatus() const
{
	
	return applicationStatus;
}



/*
   함수 이름: changeApplicationStatus
   기능: 멤버변수 applicationStatus의 값을 변경한다.
	  장학금 신청 여부 값이 true이면 false를 반환하도록,
	  장학금 신청 여부 값이 false이면 true를 반환하도록 하는 기능을 수행한다.

   매개변수: 없음
   반환값: 변경된 학생의 장학금 신청 여부 값

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
void Student::changeApplicationStatus()
{
	if (applicationStatus == false) //장학금 신청을 안했다면
	{
		this->applicationStatus = true; //상태를 신청했음으로 변경
		
	}

	else //장학금 신청을 했다면
	{
		this->applicationStatus = false; //상태를 신청하지 않음으로 변경
	}
}



/*
   함수이름: 클래스 Student의 소멸자
   기능: 동적할당한 학생의 이름 메모리를 해제시킨다
   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
Student::~Student()
{
	delete[] name;
}

	
