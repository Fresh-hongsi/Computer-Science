#ifndef __UNDERGRADUATESTUDENT_H__
#define __UNDERGRADUATESTUDENT_H__
#include "Student.h" //헤더파일 Student.h를 불러온다.



/*
   클래스 이름: UndergraduateStudent -> < Student 클래스를 public 상속 >
   클래스 멤버 변수: clubName / UstudentInfoStr
   기능: 학부생에 대한 다음과 같은 기능을 구현함

   1. 생성자 호출을 통해 부모클래스의 멤버변수들을 초기화하고, 소속동아리 정보, 학생 정보를 반환할 문자열을 초기화한다.
   2. 학부생의 소속동아리 정보를 반환한다.
   3. 학위 과정에 맞게 계산된 학부생의 평점을 반환한다.
   4. 학부생의 수강 신청에 맞게 계산된 등록금 금액을 반환한다.
   5. 학부생 정보(이름, 전공학점, 교양학점, 전공평점, 교양평점, 소속동아리)를 통합한 문자열을 반환한다.
   6. 소멸자를 통해, 동적할당한 메모리가 있다면 그것을 해제시킨다.

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
class UndergraduateStudent :public Student
{
private:
	char* clubName; //소속동아리
	char* UstudentInfoStr; //학부생 정보를 반환할 문자열

public:
	UndergraduateStudent(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA, const char* sClubName);

	char* getClubName() const;

	virtual double getGPA() const; 

	virtual int getTuition() const; 

	virtual char* getStudentInfo();

	virtual ~UndergraduateStudent();
		

};

#endif