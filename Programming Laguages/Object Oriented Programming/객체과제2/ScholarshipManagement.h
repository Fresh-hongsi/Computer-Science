#ifndef __SCHOLARSHIPMANAGEMENT_H__
#define __SCHOLARSHIPMANAGEMENT_H__
#include "Student.h" //������� Student.h�� �ҷ��´�.


/*
 Ŭ���� �̸�: ScholarshipManagement
 Ŭ���� ��� ����: studentList / num_of_students
 ���:

 1. �����ڸ� ���� Student��ü ������ �迭�� �Ű������� �޾� Student**�� ������� studentList�� �ʱ�ȭ�ϰ�, �л� ���� �Ű������� �޾� num_of_students�� �ʱ�ȭ�Ѵ�.
 2. run�Լ� �������� ������ ���� ����� �����Ѵ�.
    (case 1) ���б� ���� : �����ϴ� �л� ���� �������� ��ȣ�� �������� �Է¹޾� ���б��� ��û�Ѵ�.
	(case 2) ���б� ������ ���� : ���б� ��û�� �Ϸ�� �����ڵ��� ����(�⺻���� + ����, ��ϱ�)�� ����Ѵ�.  
	(case 3) ���л� ���� : ������ ���� ���� �л� 2���� �����ϰ�, ������ �л����� ����(�⺻���� + ����, ��ϱ�)�� ����Ѵ�. ��, 2�� �̸� ������ ��쿡�� ��� �����ϰ�, ������ ����Ѵ�. 
	(case 4) �����ϱ� : �޽��� ��� �� ���α׷��� �����ϴ� ����� �����Ѵ�.

�ۼ���¥: 2021/05/17
�ۼ���: �ڽ�ȫ
*/
class ScholarshipManagement
{
private:
	Student** studentList;// studentList�� student���� �ּҰ��� ���� �迭(Student��ü ������ �迭)�� �ּҸ� ����.
	int num_of_students; //�л��� ��

public:
	ScholarshipManagement(Student** list, int studentNum);

	void run();

	

};

#endif