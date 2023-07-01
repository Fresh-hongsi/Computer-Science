#ifndef __GRADUATESTUDENT_H__
#define __GRADUATESTUDENT_H__
#include "Student.h" //헤더파일 Student.h를 불러온다.



/*
   클래스 이름: GraduateStudent -> < Student 클래스를 public 상속 >
   클래스 멤버 변수: labName / courseName / GstudentInfoStr
   기능: 대학원생에 대한 다음과 같은 기능을 구현함

   1. 생성자 호출을 통해 부모클래스의 멤버변수들을 초기화하고, 소속연구실 정보, 학위과정 정보, 대학원생 정보를 반환할 문자열을 초기화한다.
   2. 대학원생의 소속연구실 정보를 반환한다.
   3. 대학원생의 학위과정 정보를 반환한다.
   4. 학위 과정에 맞게 계산된 대학원생의 평점을 반환한다.
   5. 학부생의 수강 신청에 맞게 계산된 등록금 금액을 반환한다.
   6. 대학원생 정보(이름, 전공학점, 교양학점, 전공평점, 교양평점, 소속연구실, 학위과정)를 통합한 문자열을 반환한다.
   7. 소멸자를 통해, 동적할당한 메모리가 있다면 그것을 해제시킨다.

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
class GraduateStudent :public Student
{
private:
	char* labName; //소속연구실
	char* courseName; //학위과정
	char* GstudentInfoStr; //대학원생 정보를 반환할 문자열

public:
	GraduateStudent(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA, const char* sLabName, const char* sCourseName);

	char* getLabName() const;

	char* getCourseName() const;

	virtual double getGPA() const;

	virtual int getTuition() const;

	virtual char* getStudentInfo();

	virtual ~GraduateStudent();


};

#endif