#ifndef __SCHOLARSHIPMANAGEMENT_H__
#define __SCHOLARSHIPMANAGEMENT_H__
#include "Student.h" //헤더파일 Student.h를 불러온다.


/*
 클래스 이름: ScholarshipManagement
 클래스 멤버 변수: studentList / num_of_students
 기능:

 1. 생성자를 통해 Student객체 포인터 배열을 매개변수로 받아 Student**형 멤버변수 studentList를 초기화하고, 학생 수를 매개변수로 받아 num_of_students를 초기화한다.
 2. run함수 내에서는 다음과 같은 기능을 수행한다.
    (case 1) 장학금 지원 : 지원하는 학생 수와 지원자의 번호를 연속으로 입력받아 장학금을 신청한다.
	(case 2) 장학금 지원자 정보 : 장학금 신청이 완료된 지원자들의 정보(기본정보 + 평점, 등록금)를 출력한다.  
	(case 3) 장학생 선정 : 학점이 가장 높은 학생 2명을 선정하고, 선정된 학생들의 정보(기본정보 + 평점, 등록금)를 출력한다. 단, 2명 미만 지원한 경우에는 모두 선정하고, 정보를 출력한다. 
	(case 4) 종료하기 : 메시지 출력 후 프로그램을 종료하는 기능을 수행한다.

작성날짜: 2021/05/17
작성자: 박시홍
*/
class ScholarshipManagement
{
private:
	Student** studentList;// studentList는 student들의 주소값을 지닌 배열(Student객체 포인터 배열)의 주소를 지님.
	int num_of_students; //학생의 수

public:
	ScholarshipManagement(Student** list, int studentNum);

	void run();

	

};

#endif