#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "GraduateStudent.h"

using namespace std;



/*
   함수이름: 클래스 GraduateStudent의 생성자
   기능:

   객체 생성 시 부모클래스 Student의 생성자 호출을 통해 Student의 멤버 변수 name / majorCredits / culturalCredits / majorGPA / culturalGPA 를 인자로 전달된 값으로 초기화하고,
   GraduateStudent의 생성자를 통해 labName, courseName을 인자로 전달된 값으로 초기화하며, 대학원생 정보를 반환할 문자열 GstudentInfoStr을 Null로 초기화한다.

   매개변수 : const char* sName / int sMajorCredits / int sCulturalCredits / double sMajorGPA / double sCulturalGPA / const char* sLabName / const char* sCourseName
   반환값: 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
GraduateStudent::GraduateStudent(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA, const char* sLabName, const char* sCourseName)
	:Student(sName, sMajorCredits, sCulturalCredits, sMajorGPA, sCulturalGPA)
{
	labName = new char[strlen(sLabName) + 5];
	courseName = new char[strlen(sLabName) + 5];

	strcpy(labName, sLabName);
	strcpy(courseName, sCourseName);

	GstudentInfoStr = NULL;
}



/*
   함수이름: getLabName
   기능: 멤버변수 labName에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: labName

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
char* GraduateStudent::getLabName() const
{
	return labName;
}



/*
   함수이름: getCourseName
   기능: 멤버변수 courseName에 저장된 값을 반환한다.
   매개변수: 없음
   반환값: courseName

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
char* GraduateStudent::getCourseName() const
{
	return courseName;
}



/*
   함수이름: getGPA
   기능: 대학원생의 평점을 계산하고, 그 값을 반환한다.
		대학원생의 평점 계산 방식 : [{(이수전공학점 X 전공평점 X 1.1) + (이수교양학점 X 교양평점 X 0.9)} / (이수전공학점 + 이수교양학점)]

   매개변수: 없음
   반환값: 대학원생의 GPA

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
double GraduateStudent::getGPA() const
{
	double GPA = 0.0;
	GPA = ((getMajorCredits() * getMajorGPA()*(1.1) + (getCulturalCredits() * getCulturalGPA()*(0.9))) / ((double)getMajorCredits() + (double)getCulturalCredits()));
	return GPA;
}



/*
   함수이름: getTuition
   기능: 대학원생의 등록금을 계산하고, 그 값을 반환한다.
		대학원생의 등록금 계산 방식 : (이수전공학점 X 12) + (이수교양학점 X 4)
		대학원생(전공과목 학점당 12만원, 교양과목 학점당 4만원)

   매개변수: 없음
   반환값: 대학원생의 등록금

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
int GraduateStudent::getTuition() const
{
	int tuitionFee = 0;
	tuitionFee = (getMajorCredits() * 12) + (getCulturalCredits() * 4);
	return tuitionFee;
}



/*
* 함수 이름: getStudentInfo
* 기능: 대학원생의 정보(이름, 전공학점, 교양학점, 전공평점, 교양평점, 소속연구실, 학위과정)를 통합한 문자열을 반환한다.
* 매개변수: 없음
* 반환값: 대학원생의 정보를 담은 문자열
*/
char* GraduateStudent::getStudentInfo() 
{

	char GstudentInfoArr[70] = { 0, }; //대학원생 정보를 담는 문자배열 선언, 초기화

	sprintf(GstudentInfoArr, "%s %d %d %.2f %.2f %s %s", this->getStudentName(), this->getMajorCredits(), this->getCulturalCredits(), this->getMajorGPA(), this->getCulturalGPA(), this->getLabName(),this->getCourseName()); //대학원생 정보를 통합한 문자열을 만들고, GstudentInfoArr에 저장
	
	GstudentInfoStr = new char[strlen(GstudentInfoArr) + 5]; //대학원생 정보를 반환할 문자열을 동적할당하여 메모리를 확보한다.

	strcpy(GstudentInfoStr, GstudentInfoArr); //GstudentInfoArr에 있는 문자열 내용을 GstudentInfoStr 문자열에 복사한다.
	
	return GstudentInfoStr; //대학원생 정보를 반환한다.

	
}



/*
   함수이름: 클래스 GraduateStudent의 소멸자
   기능 : GraduateStudent 객체가 소멸될 때 호출된다.
		 동적할당한 소속연구실, 학위과정, 대학원생 정보 문자열 메모리를 해제시켜준다.
   매개변수 : 없음
   반환값 : 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
GraduateStudent::~GraduateStudent()
{
	delete[] labName;
	delete[] courseName;
	delete[] GstudentInfoStr;
}