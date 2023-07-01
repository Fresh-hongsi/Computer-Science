#ifndef __GRADUATESTUDENT_H__
#define __GRADUATESTUDENT_H__
#include "Student.h" //������� Student.h�� �ҷ��´�.



/*
   Ŭ���� �̸�: GraduateStudent -> < Student Ŭ������ public ��� >
   Ŭ���� ��� ����: labName / courseName / GstudentInfoStr
   ���: ���п����� ���� ������ ���� ����� ������

   1. ������ ȣ���� ���� �θ�Ŭ������ ����������� �ʱ�ȭ�ϰ�, �Ҽӿ����� ����, �������� ����, ���п��� ������ ��ȯ�� ���ڿ��� �ʱ�ȭ�Ѵ�.
   2. ���п����� �Ҽӿ����� ������ ��ȯ�Ѵ�.
   3. ���п����� �������� ������ ��ȯ�Ѵ�.
   4. ���� ������ �°� ���� ���п����� ������ ��ȯ�Ѵ�.
   5. �кλ��� ���� ��û�� �°� ���� ��ϱ� �ݾ��� ��ȯ�Ѵ�.
   6. ���п��� ����(�̸�, ��������, ��������, ��������, ��������, �Ҽӿ�����, ��������)�� ������ ���ڿ��� ��ȯ�Ѵ�.
   7. �Ҹ��ڸ� ����, �����Ҵ��� �޸𸮰� �ִٸ� �װ��� ������Ų��.

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
class GraduateStudent :public Student
{
private:
	char* labName; //�Ҽӿ�����
	char* courseName; //��������
	char* GstudentInfoStr; //���п��� ������ ��ȯ�� ���ڿ�

public:
	GraduateStudent(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA, const char* sLabName, const char* sCourseName);

	char* getLabName() const;

	char* getCourseName() const;

	virtual double getGPA() const;

	virtual int getTuition() const;

	virtual char* getStudentInfo();

	virtual ~GraduateStudent();


};

#endif