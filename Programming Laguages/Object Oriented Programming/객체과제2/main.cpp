#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h" //������� Student.h�� �ҷ��´�.
#include "UndergraduateStudent.h" //������� UndergraduateStudent.h�� �ҷ��´�.
#include "GraduateStudent.h" //������� GraduateStudent.h�� �ҷ��´�.
#include "ScholarshipManagement.h" //������� ScholarshipManagement.h�� �ҷ��´�.

using namespace std;


/* �Լ��̸�: main
   ���:
    - ������ ���� ���� ������ �������� �л����� ���б� ���� �� ������ �����ϴ� ����� �����Ѵ�. 
    - Ŭ���� StudentList�� Student ��ü���� ������ ��� �ִ�. 
    - Ŭ���� ScholarshipManagement�� �л����� ���б� ����, ���б� ������ ���� ��� �� ���л� �����ϴ� ����� �����Ѵ�.

   �Ű�����: ����
   ��ȯ��: 0�̸� ���� ����, �� ���� ���� ��ȯ�Ǹ� ������ ����ȴ�.

   �ۼ���¥ : 2021/05/17
   �ۼ��� : �ڽ�ȫ
*/
int main(void)
{

	Student* StudentList[6]; //ũ�Ⱑ 6�� Student ��ü�� ������ �迭 StudentList ����
	
	for (int i = 0; i < 6; i++)
	{
		StudentList[i] = NULL; //������ �迭�� ��ҵ��� null�� �ʱ�ȭ
	}
	
	/*
	�л� ���� �Է�(�ϵ��ڵ�)
	*/
	
	StudentList[0] = new UndergraduateStudent("Kim", 9, 6, 3.75, 4.0, "Football"); //�кλ�1 ��ü �����Ҵ��Ͽ� ����
	StudentList[1] = new UndergraduateStudent("Park", 6, 9, 3.75, 3.5, "Baseball"); //�кλ�2 ��ü �����Ҵ��Ͽ� ����
	StudentList[2] = new UndergraduateStudent("Lee", 12, 3, 4.0, 3.75, "Valleyball"); //�кλ�3 ��ü �����Ҵ��Ͽ� ����

	StudentList[3] = new GraduateStudent("Yoon", 6, 6, 4.0, 3.5,"Database", "����"); //���п���1 ��ü �����Ҵ��Ͽ� ����
	StudentList[4] = new GraduateStudent("Hong", 9, 3, 4.0, 3.5, "Algorithm", "�ڻ�"); //���п���2 ��ü �����Ҵ��Ͽ� ����
	StudentList[5] = new GraduateStudent("Min", 9, 3, 3.5, 3.75, "OS", "����"); //���п���3 ��ü �����Ҵ��Ͽ� ����
	
	ScholarshipManagement scholarManager(StudentList, 6); //ScholarshipManagement ��ü ����, ���ڷ� StudentList, �л� �� 6�� ���ڷ� ����

	scholarManager.run(); //scholarManager�� ����Լ� run����
	
	for (int i = 0; i < 6; i++) //�����Ҵ��� �л� ��ü �޸𸮵��� ������Ų��.
	{
		delete StudentList[i];
	}

	return 0;
}