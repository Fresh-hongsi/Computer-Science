#ifndef __UNDERGRADUATESTUDENT_H__
#define __UNDERGRADUATESTUDENT_H__
#include "Student.h" //������� Student.h�� �ҷ��´�.



/*
   Ŭ���� �̸�: UndergraduateStudent -> < Student Ŭ������ public ��� >
   Ŭ���� ��� ����: clubName / UstudentInfoStr
   ���: �кλ��� ���� ������ ���� ����� ������

   1. ������ ȣ���� ���� �θ�Ŭ������ ����������� �ʱ�ȭ�ϰ�, �Ҽӵ��Ƹ� ����, �л� ������ ��ȯ�� ���ڿ��� �ʱ�ȭ�Ѵ�.
   2. �кλ��� �Ҽӵ��Ƹ� ������ ��ȯ�Ѵ�.
   3. ���� ������ �°� ���� �кλ��� ������ ��ȯ�Ѵ�.
   4. �кλ��� ���� ��û�� �°� ���� ��ϱ� �ݾ��� ��ȯ�Ѵ�.
   5. �кλ� ����(�̸�, ��������, ��������, ��������, ��������, �Ҽӵ��Ƹ�)�� ������ ���ڿ��� ��ȯ�Ѵ�.
   6. �Ҹ��ڸ� ����, �����Ҵ��� �޸𸮰� �ִٸ� �װ��� ������Ų��.

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
class UndergraduateStudent :public Student
{
private:
	char* clubName; //�Ҽӵ��Ƹ�
	char* UstudentInfoStr; //�кλ� ������ ��ȯ�� ���ڿ�

public:
	UndergraduateStudent(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA, const char* sClubName);

	char* getClubName() const;

	virtual double getGPA() const; 

	virtual int getTuition() const; 

	virtual char* getStudentInfo();

	virtual ~UndergraduateStudent();
		

};

#endif