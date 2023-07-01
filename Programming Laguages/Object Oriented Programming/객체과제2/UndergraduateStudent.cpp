#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "UndergraduateStudent.h"

using namespace std;



/*
   �Լ��̸�: Ŭ���� UndergraduateStudent�� ������
   ���:

   ��ü ���� �� �θ�Ŭ���� Student�� ������ ȣ���� ���� Student�� ��� ���� name / majorCredits / culturalCredits / majorGPA / culturalGPA �� ���ڷ� ���޵� ������ �ʱ�ȭ�ϰ�,
   UndergraduateStudent�� �����ڸ� ���� clubName�� ���ڷ� ���޵� ������ �ʱ�ȭ�ϸ�, �кλ� ������ ��ȯ�� ���ڿ� UstudentInfoStr�� Null�� �ʱ�ȭ�Ѵ�.

   �Ű����� : const char* sName / int sMajorCredits / int sCulturalCredits / double sMajorGPA / double sCulturalGPA / const char * sClubName
   ��ȯ��: ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
UndergraduateStudent::UndergraduateStudent(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA, const char* sClubName)
	:Student(sName, sMajorCredits, sCulturalCredits, sMajorGPA, sCulturalGPA)
{
	clubName = new char[strlen(sClubName) + 5];
	
	strcpy(clubName, sClubName);

	UstudentInfoStr = NULL;
}


/*
   �Լ��̸�: getClubName
   ���: ������� clubName�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: clubName

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
char* UndergraduateStudent::getClubName() const
{
	return clubName;
}



/*
   �Լ��̸�: getGPA
   ���: �кλ��� ������ ����ϰ�, �� ���� ��ȯ�Ѵ�.
        �кλ��� ���� ��� ��� : [{(�̼��������� X ��������) + (�̼��������� X ��������)} / (�̼��������� + �̼���������)]
   
   �Ű�����: ����
   ��ȯ��: �кλ��� GPA

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
double UndergraduateStudent::getGPA() const
{
	double GPA=0.00;
	GPA = ((((getMajorCredits() * getMajorGPA()) + (getCulturalCredits() * getCulturalGPA()))) / ((double)getMajorCredits() + (double)getCulturalCredits()));
	
	return GPA;
}



/*
   �Լ��̸�: getTuition
   ���: �кλ��� ��ϱ��� ����ϰ�, �� ���� ��ȯ�Ѵ�.
		�кλ��� ��ϱ� ��� ��� : (�̼��������� X 10 ) + (�̼��������� X 6)
		�кλ�(�������� ������ 10����, ������� ������ 6����)

   �Ű�����: ����
   ��ȯ��: �кλ��� ��ϱ�

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
int UndergraduateStudent::getTuition() const
{
	int tuitionFee = 0;
	tuitionFee = (getMajorCredits() * 10) + (getCulturalCredits() * 6);
	
	return tuitionFee;

}



/*
* �Լ� �̸�: getStudentInfo
* ���: �кλ��� ����(�̸�, ��������, ��������, ��������, ��������, �Ҽӵ��Ƹ�)�� ������ ���ڿ��� ��ȯ�Ѵ�.
* �Ű�����: ����
* ��ȯ��: �кλ��� ������ ���� ���ڿ�
* 
* �ۼ���¥: 2021/05/17
  �ۼ���: �ڽ�ȫ
*/

char* UndergraduateStudent::getStudentInfo() 
{
	
	char UstudentInfoArr[70] = { 0, }; //�кλ� ������ ��� ���ڹ迭 ����, �ʱ�ȭ
	
	sprintf(UstudentInfoArr, "%s %d %d %.2f %.2f %s", this->getStudentName(), this->getMajorCredits(), this->getCulturalCredits(), this->getMajorGPA(), this->getCulturalGPA(), this->getClubName()); //�кλ� ������ ������ ���ڿ��� �����, UstudentInfoArr�� ����
	
	UstudentInfoStr = new char[strlen(UstudentInfoArr) + 5]; //�кλ� ������ ��ȯ�� ���ڿ��� �����Ҵ��Ͽ� �޸𸮸� Ȯ���Ѵ�.

	strcpy(UstudentInfoStr,UstudentInfoArr); //UstudentInfoArr�� �ִ� ���ڿ� ������ UstudentInfoStr ���ڿ��� �����Ѵ�.
	
	return UstudentInfoStr;  //�кλ� ������ ��ȯ�Ѵ�.
	
	
}



/*
   �Լ��̸�: Ŭ���� UndergraduateStudent�� �Ҹ���
   ��� : UndergraduateStudent ��ü�� �Ҹ�� �� ȣ��ȴ�.
         �����Ҵ��� �Ҽӵ��Ƹ�, �кλ� ���� ���ڿ� �޸𸮸� ���������ش�.
   �Ű����� : ����
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
UndergraduateStudent::~UndergraduateStudent()
{
	delete[] clubName;
	delete[] UstudentInfoStr;
}

