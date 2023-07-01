#ifndef __STUDENT_H__
#define __STUDENT_H__

/*
Ŭ���� �̸� : Student(�߻� Ŭ����)
Ŭ���� ��� ����:  name / majorCredits / culturalCredits / majorGPA / culturalGPA / applicationStatus
��� : �л��� ���� ������ ���� ����� ������

	 1. �л��� �̸�, �̼���������, �̼���������, ��������, �������� ������ �޾� ��ü�� �����Ѵ�. ���� ���� �뿩 ���θ� ��Ÿ���� ���� ��ü ������ ���ÿ� �ʱ�ȭ�Ѵ�.
	 2. �л��� �̸��� ��ȯ�Ѵ�.
	 3. �л��� �̼� ���������� ��ȯ�Ѵ�.
	 4. �л��� �̼� ���������� ��ȯ�Ѵ�.
	 5. �л��� ���������� ��ȯ�Ѵ�.
	 6. �л��� ���������� ��ȯ�Ѵ�.
	 7. ���б� ��û ���� ���� ��ȯ�Ѵ�.
	 8. ���б� ��û ���� ���� �ٲ��ش�.
	 9. ���������Լ� ������ ���� ��ü���� ������ �������̵��� getStudentInfo �Լ��� ȣ���� �� �ֵ��� ��.
	 10. ���������Լ� ������ ���� ��ü���� ������ �������̵��� getGPA �Լ��� ȣ���� �� �ֵ��� ��.
	 11. ���������Լ� ������ ���� ��ü���� ������ �������̵��� getTuition �Լ��� ȣ���� �� �ֵ��� ��.
	 12. �Ҹ��ڸ� ���� �����Ҵ��� �޸𸮸� �����Ѵ�. ���� �Ҹ��ڸ� ������ ���� ������ ������ �ڷ����� ������� ��Ӱ����� ���� �Ʒ��� �ִ� ���� Ŭ�������� ���������� �Ҹ��ڰ� ȣ��ǵ��� ��.

�ۼ���¥ : 2021/05/17
�ۼ��� : �ڽ�ȫ
*/

class Student
{
private:
	char* name; //�л� �̸�
	int majorCredits; //�̼� ��������
	int culturalCredits; //�̼� ��������
	double majorGPA; //��������
	double culturalGPA; //��������
	bool applicationStatus; //���б� ��û ���� ��

public:
	Student(const char* sName, int sMajorCredits, int sCulturalCredits, double sMajorGPA, double sCulturalGPA);

	char* getStudentName() const;

	int getMajorCredits() const;

	int getCulturalCredits() const;

	double getMajorGPA() const;

	double getCulturalGPA() const;

	bool getApplicationStatus() const;

	void changeApplicationStatus();

	virtual char* getStudentInfo() = 0; //�л� ���� ���ڿ� ��ȯ

	virtual double getGPA() const = 0 ; //�л� ���� ���� ��ȯ

	virtual int getTuition() const = 0; //�л� ��ϱ� ���� ��ȯ

	virtual ~Student();

};
#endif