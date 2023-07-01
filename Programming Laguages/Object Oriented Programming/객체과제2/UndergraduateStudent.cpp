#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "UndergraduateStudent.h"

using namespace std;



/*
   함수이름: 클래스 UndergraduateStudent의 생성자
   기능:

   객체 생성 시 부모클래스 Student의 생성자 호출을 통해 Student의 멤버 변수 name / majorCredits / culturalCredits / majorGPA / culturalGPA 를 인자로 전달된 값으로 초기화하고,
   UndergraduateStudent의 생성자를 통해 clubName을 인자로 전달된 값으로 초기화하며, 학부생 정보를 반환할 문자열 UstudentInfoStr을 Null로 초기화한다.

   매개변수 : const char* sName / int sMajorCredits / int sCulturalCredits / double sMajorGPA / double sCulturalGPA / const char * sClubName
   반환값: 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
UndergraduateStudent::UndergraduateStudent(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA, const char* sClubName)
	:Student(sName, sMajorCredits, sCulturalCredits, sMajorGPA, sCulturalGPA)
{
	clubName = new char[strlen(sClubName) + 5];
	
	strcpy(clubName, sClubName);

	UstudentInfoStr = NULL;
}


/*
   함수이름: getClubName
   기능: 멤버변수 clubName에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: clubName

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
char* UndergraduateStudent::getClubName() const
{
	return clubName;
}



/*
   함수이름: getGPA
   기능: 학부생의 평점을 계산하고, 그 값을 반환한다.
        학부생의 평점 계산 방식 : [{(이수전공학점 X 전공평점) + (이수교양학점 X 교양평점)} / (이수전공학점 + 이수교양학점)]
   
   매개변수: 없음
   반환값: 학부생의 GPA

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
double UndergraduateStudent::getGPA() const
{
	double GPA=0.00;
	GPA = ((((getMajorCredits() * getMajorGPA()) + (getCulturalCredits() * getCulturalGPA()))) / ((double)getMajorCredits() + (double)getCulturalCredits()));
	
	return GPA;
}



/*
   함수이름: getTuition
   기능: 학부생의 등록금을 계산하고, 그 값을 반환한다.
		학부생의 등록금 계산 방식 : (이수전공학점 X 10 ) + (이수교양학점 X 6)
		학부생(전공과목 학점당 10만원, 교양과목 학점당 6만원)

   매개변수: 없음
   반환값: 학부생의 등록금

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
int UndergraduateStudent::getTuition() const
{
	int tuitionFee = 0;
	tuitionFee = (getMajorCredits() * 10) + (getCulturalCredits() * 6);
	
	return tuitionFee;

}



/*
* 함수 이름: getStudentInfo
* 기능: 학부생의 정보(이름, 전공학점, 교양학점, 전공평점, 교양평점, 소속동아리)를 통합한 문자열을 반환한다.
* 매개변수: 없음
* 반환값: 학부생의 정보를 담은 문자열
* 
* 작성날짜: 2021/05/17
  작성자: 박시홍
*/

char* UndergraduateStudent::getStudentInfo() 
{
	
	char UstudentInfoArr[70] = { 0, }; //학부생 정보를 담는 문자배열 선언, 초기화
	
	sprintf(UstudentInfoArr, "%s %d %d %.2f %.2f %s", this->getStudentName(), this->getMajorCredits(), this->getCulturalCredits(), this->getMajorGPA(), this->getCulturalGPA(), this->getClubName()); //학부생 정보를 통합한 문자열을 만들고, UstudentInfoArr에 저장
	
	UstudentInfoStr = new char[strlen(UstudentInfoArr) + 5]; //학부생 정보를 반환할 문자열을 동적할당하여 메모리를 확보한다.

	strcpy(UstudentInfoStr,UstudentInfoArr); //UstudentInfoArr에 있는 문자열 내용을 UstudentInfoStr 문자열에 복사한다.
	
	return UstudentInfoStr;  //학부생 정보를 반환한다.
	
	
}



/*
   함수이름: 클래스 UndergraduateStudent의 소멸자
   기능 : UndergraduateStudent 객체가 소멸될 때 호출된다.
         동적할당한 소속동아리, 학부생 정보 문자열 메모리를 해제시켜준다.
   매개변수 : 없음
   반환값 : 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
UndergraduateStudent::~UndergraduateStudent()
{
	delete[] clubName;
	delete[] UstudentInfoStr;
}

