#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h" //������� Student.h�� �ҷ��´�.

using namespace std;

/*
   �Լ��̸�: Ŭ���� Student�� ������
   ��� :  Student Ŭ������ �����ڷν��� ����� �����Ѵ�. ���� ��ü ������ ���ÿ� ���б� ��û ���θ� ��Ÿ���� ���� applicationStatus���� false�� �ʱ�ȭ�Ѵ�.

   �Ű����� : const char* sName -> �л��� �̸�
             int sMajorCredits -> �л��� �̼� ��������
			 int sCulturalCredits -> �л��� �̼� ��������
			 double sMajorGPA -> �л��� ���� ����
			 double sCulturalGPA -> �л��� ���� ����

   ��ȯ�� : ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
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
   �Լ��̸�: getStudentName
   ���: ������� name�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: name

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
char* Student::getStudentName() const
{
	return name;
}


/*
   �Լ��̸�: getMajorCredits
   ���: ������� majorCredits�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: majorCredits

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
int Student::getMajorCredits() const
{
	return majorCredits;
}



/*
   �Լ��̸�: getCulturalCredits
   ���: ������� culturalCredits�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: culturalCredits

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
int Student::getCulturalCredits() const
{
	return culturalCredits;
}



/*
   �Լ��̸�: getMajorGPA
   ���: ������� majorGPA�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: majorGPA

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
double Student::getMajorGPA() const
{
	
	return majorGPA;
}



/*
   �Լ��̸�: getCulturalGPA
   ���: ������� culturalGPA�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: culturalGPA

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
double Student::getCulturalGPA() const
{
	return culturalGPA;
}



/*
   �Լ� �̸�: getApplicationStatus
   ���: ������� applicationStatus�� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: �л��� ���б� ��û ���� �� -> true: ���� ���б� ��û�� �Ϸ��
							         false: ���� ���б� ��û�� ���� ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
bool Student::getApplicationStatus() const
{
	
	return applicationStatus;
}



/*
   �Լ� �̸�: changeApplicationStatus
   ���: ������� applicationStatus�� ���� �����Ѵ�.
	  ���б� ��û ���� ���� true�̸� false�� ��ȯ�ϵ���,
	  ���б� ��û ���� ���� false�̸� true�� ��ȯ�ϵ��� �ϴ� ����� �����Ѵ�.

   �Ű�����: ����
   ��ȯ��: ����� �л��� ���б� ��û ���� ��

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
void Student::changeApplicationStatus()
{
	if (applicationStatus == false) //���б� ��û�� ���ߴٸ�
	{
		this->applicationStatus = true; //���¸� ��û�������� ����
		
	}

	else //���б� ��û�� �ߴٸ�
	{
		this->applicationStatus = false; //���¸� ��û���� �������� ����
	}
}



/*
   �Լ��̸�: Ŭ���� Student�� �Ҹ���
   ���: �����Ҵ��� �л��� �̸� �޸𸮸� ������Ų��
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
Student::~Student()
{
	delete[] name;
}

	
