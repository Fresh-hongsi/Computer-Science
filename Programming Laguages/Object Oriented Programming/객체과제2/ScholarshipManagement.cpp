#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h" //헤더파일 Student.h를 불러온다.
#include "ScholarshipManagement.h" //헤더파일 ScholarshipManagement.h를 불러온다.

using namespace std;


/*
   함수이름: 클래스 ScholarshipManagement의 생성자
   기능 : 객체 생성 시 클래스 ScholarshipManagement의 멤버변수 studentList는 매개변수인 Student** list(Student 객체 포인터 배열)로 초기화하고,
         num_of_students(학생 수)는 이니셜라이저를 통해 매개변수 studentNum으로 초기화한다.
   매개변수 : 없음
   반환값 : 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
ScholarshipManagement::ScholarshipManagement(Student** list, int studentNum):num_of_students(studentNum)
{
	studentList= list;
}



/*
   함수 이름: run
   기능: run함수 내에서는 다음과 같은 기능을 수행한다. 

        (case 1) 장학금 지원 : 지원하는 학생 수와 지원자의 번호를 연속으로 입력받아 장학금을 신청한다.
		        <상세 기능>
				- 장학금 신청할 학생의 수를 applyNum 변수로 입력받는다.
				- 장학금 신청할 학생들의 수만큼 학생들의 번호를 각각 사용자로부터 입력받기 위해 studentArray[10]을 선언하였다.
				- 사용자로부터 입력받은 studentArray배열의 요소들은 각각 실제 학생들의 정보가 저장된 배열의 인덱스+1의 값을 지니므로, 이에 맞추어 실제 학생들의 정보 인덱스 값에 접근하여 학생의 장학금 신청 상태를 true로 바꾸어준다.

	    (case 2) 장학금 지원자 정보 : 장학금 신청이 완료된 지원자들의 정보(기본정보 + 평점, 등록금)를 출력한다.  
		        <상세 기능>
				- 장학금 신청이 완료된 학생들의 장학금 신청 여부 값은 true이므로, 장학금 신청 여부 값이 true인 학생들의 기본 정보 + 평점 정보 + 등록금 정보를 각각 반환받아 출력한다. 

	    (case 3) 장학생 선정 : 학점이 가장 높은 학생 2명을 선정하고, 선정된 학생들의 정보(기본정보 + 평점, 등록금)를 출력한다. 단, 2명 미만 지원한 경우에는 모두 선정하고, 정보를 출력한다.
		        <상세 기능>
				- 장학금 지원한 학생의 수를 계산한 값을 appliedNum 변수에 저장한다.
				
				- 장학금 지원자 수가 2명 이하인 경우: 장학금 신청 여부를 확인한 후, 지원 상태가 true인 사람들을 모두 장학생으로 선정하고, 선정된 학생들의 기본정보 + 평점 정보 + 등록금 정보를 출력한다.
				
				- 장학금 지원자 수가 3명 이상인 경우: 장학금 신청 여부를 확인한 후, 신청한 학생들의 GPA들을 담을 수 있는 scoreArr[10] 배열을 선언하고, 신청한 학생들의 GPA만을 각각 scoreArr배열에 담아 GPA값이 높은 순서대로 정렬하였다.
				                                  select1, select2는 장학금으로 선정될 GPA값을 지니는 변수로,  select1은 가장 높은 GPA 값(scoreArr[0])으로, select2는 두번째로 높은 GPA 값(scoreArr[1])으로 초기화하였다.
												  그 후, 장학생으로 선정될 GPA값(select1, select2)을 지니는 학생을 찾아 해당하는 학생의 기본 정보 + 평점 정보 + 등록금 정보를 각각 반환받아 출력한다.

	    (case 4) 종료하기 : 메시지 출력 후 프로그램을 종료하는 기능을 수행한다.
   
   매개변수: 없음
   반환값: 없음

   작성날짜: 2021/05/17
   작성자: 박시홍
*/
void ScholarshipManagement::run()
{
	int menuSelect; //메뉴 번호를 입력받을 수 있는 변수 선언
	bool loopStop = false; //while 루프를 빠져나오기 위한 변수 선언. loopStop -> false : 계속 while문 실행, loopStop -> true : while문 탈출


	while (1)
	{
		cout << "메뉴: " << endl;
		cout << "1. 장학금 지원" << endl;
		cout << "2. 장학금 지원자 정보" << endl;
		cout << "3. 장학생 선정" << endl;
		cout << "4. 종료하기" << endl;
		cout << "* 연산을 입력하십시오: ";

		cin >> menuSelect; //사용자로부터 메뉴 번호를 입력받음

		switch (menuSelect) //입력받은 메뉴 번호를 바탕으로, 번호에 해당하는 메뉴의 기능을 수행하도록 switch 문을 구현함.
		{



		case 1: //장학금 지원 기능 수행
		{

			int applyNum = 0; //장학금을 신청할 학생의 수를 사용자로부터 입력받기 위한 변수 선언
			int studentArray[10] = { 0, }; //장학금 신청할 학생들의 인덱스 번호를 입력받기 위해 정의된 배열이다.

			for (int i = 0; i < num_of_students; i++) //배열을 통해 넘어온 학생들의 기본 정보를 순서대로 출력한다.
			{
				cout << (i + 1) << ") ";
				cout << studentList[i]->getStudentInfo();
				cout << endl;
			}

			cout << "*지원 대상 학생들의 수와 각각의 번호를 연속해서 입력하시오: ";

			cin >> applyNum; //장학금 신청할 학생의 수를 사용자로부터 입력받는다.

			for (int i = 0; i < applyNum; i++) //장학금 신청할 학생의 수만큼 학생의 번호를 studentArray배열에 순차적으로 각각 입력받는다.
			{
				cin >> studentArray[i];
			}

			for (int i = 0; i < applyNum; i++) //실제 학생의 정보는 studentList[studentArray[i]-1]에 저장되어있으므로, 여기에 접근해 장학금 신청한 학생들의 장학금 신청 상태를 false에서 true로 바꿔준다. 
			{
				studentList[studentArray[i] - 1]->changeApplicationStatus();
			}

			cout << endl << endl << endl;

			break;
		}




		case 2: //장학금 지원자 정보 출력 기능 수행
		{
			for (int i = 0; i < num_of_students; i++)
			{
				if (studentList[i]->getApplicationStatus() == true) //장학금 지원 상태가 true인지 확인
				{
					cout << "- ";
					cout << studentList[i]->getStudentInfo(); //장학금 지원 상태가 true인 학생들의 기본 정보를 반환받아 이를 출력한다.
					printf(" %.2f ", studentList[i]->getGPA()); //장학금 지원 상태가 true인 학생들의 평점을 반환받아 이를 출력한다.
					cout << studentList[i]->getTuition() << "만원" << endl; //장학금 지원 상태가 true인 학생들의 등록금 정보를 반환받아 이를 출력한다.
				}
			}
			cout << endl << endl << endl;
			break;
		}




		case 3: //장학생 선정 기능 수행
		{
			int appliedNum = 0; //장학금 지원자 수 

			for (int i = 0; i < num_of_students; i++)
			{
				if (studentList[i]->getApplicationStatus() == true) //장학금 지원 상태가 true인지 확인
				{
					appliedNum++; //장학금 지원자 수 계산
				}
			}

			if (appliedNum <= 2) //장학금 신청한 학생이 둘 이하라면,
			{
				for (int i = 0; i < num_of_students; i++)
				{
					if (studentList[i]->getApplicationStatus() == true) //장학금 신청한 학생들의

					{
						cout << "- ";
						cout << studentList[i]->getStudentInfo(); //기본 정보를 반환받아 출력한다.
						printf(" %.2f ", studentList[i]->getGPA()); //평점 정보를 반환받아 출력한다.
						cout << studentList[i]->getTuition() << "만원" << endl; //등록금 정보를 반환받아 출력한다.

					}
				}
			}

			if (appliedNum > 2) //장학금 신청한 학생이 3명 이상이라면
			{

				double scoreArr[10] = { 0.0, }; // GPA가 높은 순서대로 정렬해줄 배열 선언
				double select1 = 0.0; //가장 높은 GPA값을 담을 변수 선언
				double select2 = 0.0; //두번째로 높은 GPA값을 담을 변수 선언


				for (int i = 0; i < num_of_students; i++)
				{
					if (studentList[i]->getApplicationStatus() == true) 
					{
						scoreArr[i] = studentList[i]->getGPA(); //scoreArr는 1차적으로 장학금 신청한 학생들의 GPA값만을 담는 배열이다.
						                                        
					}
				}


				for (int i = 0; i < num_of_students - 1; i++) //scoreArr배열을 GPA값이 높은 순서대로 정렬해준다.
				{
					for (int j = 0; j < num_of_students - 1; j++)
					{
						if (scoreArr[j] <= scoreArr[j + 1])
						{
							double temp = scoreArr[j];
							scoreArr[j] = scoreArr[j + 1];
							scoreArr[j + 1] = temp;
						}
					}
				}


				select1 = scoreArr[0]; //가장 높은 GPA값으로 select1 초기화
				select2 = scoreArr[1]; //두번 쨰로 높은 GPA값으로 select2 초기화


				for (int i = 0; i < num_of_students; i++)
				{
					if (studentList[i]->getApplicationStatus() == true)
					{
						if (studentList[i]->getGPA() == select1 || studentList[i]->getGPA() == select2) //가장 높은 GPA값을 지닌 학생과 두번쨰로 높은 GPA값을 지닌 학생을 대상으로
						{
							cout << "- ";
							cout << studentList[i]->getStudentInfo(); //기본 정보를 반환받아 출력한다.
							printf(" %.2f ", studentList[i]->getGPA()); //평점 정보를 반환받아 출력한다.
							cout << studentList[i]->getTuition() << "만원" << endl; //등록금 정보를 반환받아 출력한다.
						}
					}
				}
			}
				cout << endl << endl << endl;
				break;
		}

		



		case 4: //종료하기
		{
			cout << " - 종료합니다." << endl;
			loopStop = true;  //사용자가 4번을 고르면 loopStop 변수가 true가 되고, 이를 통해 while문을 빠져나온다.
			break;
		}

		}

		if (loopStop == true) //while문 탈출
			break;
	};

}





