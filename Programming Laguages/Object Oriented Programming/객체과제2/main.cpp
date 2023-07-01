#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h" //헤더파일 Student.h를 불러온다.
#include "UndergraduateStudent.h" //헤더파일 UndergraduateStudent.h를 불러온다.
#include "GraduateStudent.h" //헤더파일 GraduateStudent.h를 불러온다.
#include "ScholarshipManagement.h" //헤더파일 ScholarshipManagement.h를 불러온다.

using namespace std;


/* 함수이름: main
   기능:
    - 대학의 여러 학위 과정에 재학중인 학생들의 장학금 지원 및 선정을 관리하는 기능을 수행한다. 
    - 클래스 StudentList는 Student 객체들의 정보를 담고 있다. 
    - 클래스 ScholarshipManagement는 학생들의 장학금 지원, 장학금 지원자 정보 출력 및 장학생 선정하는 기능을 수행한다.

   매개변수: 없음
   반환값: 0이면 정상 종료, 그 외의 값이 반환되면 비정상 종료된다.

   작성날짜 : 2021/05/17
   작성자 : 박시홍
*/
int main(void)
{

	Student* StudentList[6]; //크기가 6인 Student 객체의 포인터 배열 StudentList 선언
	
	for (int i = 0; i < 6; i++)
	{
		StudentList[i] = NULL; //포인터 배열의 요소들을 null로 초기화
	}
	
	/*
	학생 정보 입력(하드코딩)
	*/
	
	StudentList[0] = new UndergraduateStudent("Kim", 9, 6, 3.75, 4.0, "Football"); //학부생1 객체 동적할당하여 생성
	StudentList[1] = new UndergraduateStudent("Park", 6, 9, 3.75, 3.5, "Baseball"); //학부생2 객체 동적할당하여 생성
	StudentList[2] = new UndergraduateStudent("Lee", 12, 3, 4.0, 3.75, "Valleyball"); //학부생3 객체 동적할당하여 생성

	StudentList[3] = new GraduateStudent("Yoon", 6, 6, 4.0, 3.5,"Database", "석사"); //대학원생1 객체 동적할당하여 생성
	StudentList[4] = new GraduateStudent("Hong", 9, 3, 4.0, 3.5, "Algorithm", "박사"); //대학원생2 객체 동적할당하여 생성
	StudentList[5] = new GraduateStudent("Min", 9, 3, 3.5, 3.75, "OS", "석사"); //대학원생3 객체 동적할당하여 생성
	
	ScholarshipManagement scholarManager(StudentList, 6); //ScholarshipManagement 객체 생성, 인자로 StudentList, 학생 수 6을 인자로 전달

	scholarManager.run(); //scholarManager의 멤버함수 run실행
	
	for (int i = 0; i < 6; i++) //동적할당한 학생 객체 메모리들을 해제시킨다.
	{
		delete StudentList[i];
	}

	return 0;
}