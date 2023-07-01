#ifndef __STUDENT_H__
#define __STUDENT_H__

/*
클래스 이름 : Student(추상 클래스)
클래스 멤버 변수:  name / majorCredits / culturalCredits / majorGPA / culturalGPA / applicationStatus
기능 : 학생에 대한 다음과 같은 기능을 구현함

	 1. 학생의 이름, 이수전공학점, 이수교양학점, 전공평점, 교양평점 정보를 받아 객체를 생성한다. 또한 도서 대여 여부를 나타내는 값은 객체 생성과 동시에 초기화한다.
	 2. 학생의 이름을 반환한다.
	 3. 학생의 이수 전공학점을 반환한다.
	 4. 학생의 이수 교양학점을 반환한다.
	 5. 학생의 전공평점을 반환한다.
	 6. 학생의 교양평점을 반환한다.
	 7. 장학금 신청 여부 값을 반환한다.
	 8. 장학금 신청 여부 값을 바꿔준다.
	 9. 순수가상함수 선언을 통해 객체들의 마지막 오버라이딩된 getStudentInfo 함수를 호출할 수 있도록 함.
	 10. 순수가상함수 선언을 통해 객체들의 마지막 오버라이딩된 getGPA 함수를 호출할 수 있도록 함.
	 11. 순수가상함수 선언을 통해 객체들의 마지막 오버라이딩된 getTuition 함수를 호출할 수 있도록 함.
	 12. 소멸자를 통해 동적할당한 메모리를 해제한다. 가상 소멸자를 선언을 통해 포인터 변수의 자료형과 상관없이 상속관계의 가장 아래에 있는 유도 클래스부터 순차적으로 소멸자가 호출되도록 함.

작성날짜 : 2021/05/17
작성자 : 박시홍
*/

class Student
{
private:
	char* name; //학생 이름
	int majorCredits; //이수 전공학점
	int culturalCredits; //이수 교양학점
	double majorGPA; //전공평점
	double culturalGPA; //교양평점
	bool applicationStatus; //장학금 신청 여부 값

public:
	Student(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA);

	char* getStudentName() const;

	int getMajorCredits() const;

	int getCulturalCredits() const;

	double getMajorGPA() const;

	double getCulturalGPA() const;

	bool getApplicationStatus() const;

	void changeApplicationStatus();

	virtual char* getStudentInfo() = 0; //학생 정보 문자열 반환

	virtual double getGPA() const = 0 ; //학생 평점 정보 반환

	virtual int getTuition() const = 0; //학생 등록금 정보 반환

	virtual ~Student();

};
#endif