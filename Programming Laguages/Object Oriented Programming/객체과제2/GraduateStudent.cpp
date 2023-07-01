#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "GraduateStudent.h"

using namespace std;



/*
   �Լ��̸�: Ŭ���� GraduateStudent�� ������
   ���:

   ��ü ���� �� �θ�Ŭ���� Student�� ������ ȣ���� ���� Student�� ��� ���� name / majorCredits / culturalCredits / majorGPA / culturalGPA �� ���ڷ� ���޵� ������ �ʱ�ȭ�ϰ�,
   GraduateStudent�� �����ڸ� ���� labName, courseName�� ���ڷ� ���޵� ������ �ʱ�ȭ�ϸ�, ���п��� ������ ��ȯ�� ���ڿ� GstudentInfoStr�� Null�� �ʱ�ȭ�Ѵ�.

   �Ű����� : const char* sName / int sMajorCredits / int sCulturalCredits / double sMajorGPA / double sCulturalGPA / const char* sLabName / const char* sCourseName
   ��ȯ��: ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
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
   �Լ��̸�: getLabName
   ���: ������� labName�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: labName

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
char* GraduateStudent::getLabName() const
{
	return labName;
}



/*
   �Լ��̸�: getCourseName
   ���: ������� courseName�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: courseName

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
char* GraduateStudent::getCourseName() const
{
	return courseName;
}



/*
   �Լ��̸�: getGPA
   ���: ���п����� ������ ����ϰ�, �� ���� ��ȯ�Ѵ�.
		���п����� ���� ��� ��� : [{(�̼��������� X �������� X 1.1) + (�̼��������� X �������� X 0.9)} / (�̼��������� + �̼���������)]

   �Ű�����: ����
   ��ȯ��: ���п����� GPA

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
double GraduateStudent::getGPA() const
{
	double GPA = 0.0;
	GPA = ((getMajorCredits() * getMajorGPA()*(1.1) + (getCulturalCredits() * getCulturalGPA()*(0.9))) / ((double)getMajorCredits() + (double)getCulturalCredits()));
	return GPA;
}



/*
   �Լ��̸�: getTuition
   ���: ���п����� ��ϱ��� ����ϰ�, �� ���� ��ȯ�Ѵ�.
		���п����� ��ϱ� ��� ��� : (�̼��������� X 12) + (�̼��������� X 4)
		���п���(�������� ������ 12����, ������� ������ 4����)

   �Ű�����: ����
   ��ȯ��: ���п����� ��ϱ�

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
int GraduateStudent::getTuition() const
{
	int tuitionFee = 0;
	tuitionFee = (getMajorCredits() * 12) + (getCulturalCredits() * 4);
	return tuitionFee;
}



/*
* �Լ� �̸�: getStudentInfo
* ���: ���п����� ����(�̸�, ��������, ��������, ��������, ��������, �Ҽӿ�����, ��������)�� ������ ���ڿ��� ��ȯ�Ѵ�.
* �Ű�����: ����
* ��ȯ��: ���п����� ������ ���� ���ڿ�
*/
char* GraduateStudent::getStudentInfo() 
{

	char GstudentInfoArr[70] = { 0, }; //���п��� ������ ��� ���ڹ迭 ����, �ʱ�ȭ

	sprintf(GstudentInfoArr, "%s %d %d %.2f %.2f %s %s", this->getStudentName(), this->getMajorCredits(), this->getCulturalCredits(), this->getMajorGPA(), this->getCulturalGPA(), this->getLabName(),this->getCourseName()); //���п��� ������ ������ ���ڿ��� �����, GstudentInfoArr�� ����
	
	GstudentInfoStr = new char[strlen(GstudentInfoArr) + 5]; //���п��� ������ ��ȯ�� ���ڿ��� �����Ҵ��Ͽ� �޸𸮸� Ȯ���Ѵ�.

	strcpy(GstudentInfoStr, GstudentInfoArr); //GstudentInfoArr�� �ִ� ���ڿ� ������ GstudentInfoStr ���ڿ��� �����Ѵ�.
	
	return GstudentInfoStr; //���п��� ������ ��ȯ�Ѵ�.

	
}



/*
   �Լ��̸�: Ŭ���� GraduateStudent�� �Ҹ���
   ��� : GraduateStudent ��ü�� �Ҹ�� �� ȣ��ȴ�.
		 �����Ҵ��� �Ҽӿ�����, ��������, ���п��� ���� ���ڿ� �޸𸮸� ���������ش�.
   �Ű����� : ����
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
GraduateStudent::~GraduateStudent()
{
	delete[] labName;
	delete[] courseName;
	delete[] GstudentInfoStr;
}