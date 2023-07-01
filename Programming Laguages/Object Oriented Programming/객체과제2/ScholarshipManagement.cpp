#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h" //������� Student.h�� �ҷ��´�.
#include "ScholarshipManagement.h" //������� ScholarshipManagement.h�� �ҷ��´�.

using namespace std;


/*
   �Լ��̸�: Ŭ���� ScholarshipManagement�� ������
   ��� : ��ü ���� �� Ŭ���� ScholarshipManagement�� ������� studentList�� �Ű������� Student** list(Student ��ü ������ �迭)�� �ʱ�ȭ�ϰ�,
         num_of_students(�л� ��)�� �̴ϼȶ������� ���� �Ű����� studentNum���� �ʱ�ȭ�Ѵ�.
   �Ű����� : ����
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
ScholarshipManagement::ScholarshipManagement(Student** list, int studentNum):num_of_students(studentNum)
{
	studentList= list;
}



/*
   �Լ� �̸�: run
   ���: run�Լ� �������� ������ ���� ����� �����Ѵ�. 

        (case 1) ���б� ���� : �����ϴ� �л� ���� �������� ��ȣ�� �������� �Է¹޾� ���б��� ��û�Ѵ�.
		        <�� ���>
				- ���б� ��û�� �л��� ���� applyNum ������ �Է¹޴´�.
				- ���б� ��û�� �л����� ����ŭ �л����� ��ȣ�� ���� ����ڷκ��� �Է¹ޱ� ���� studentArray[10]�� �����Ͽ���.
				- ����ڷκ��� �Է¹��� studentArray�迭�� ��ҵ��� ���� ���� �л����� ������ ����� �迭�� �ε���+1�� ���� ���ϹǷ�, �̿� ���߾� ���� �л����� ���� �ε��� ���� �����Ͽ� �л��� ���б� ��û ���¸� true�� �ٲپ��ش�.

	    (case 2) ���б� ������ ���� : ���б� ��û�� �Ϸ�� �����ڵ��� ����(�⺻���� + ����, ��ϱ�)�� ����Ѵ�.  
		        <�� ���>
				- ���б� ��û�� �Ϸ�� �л����� ���б� ��û ���� ���� true�̹Ƿ�, ���б� ��û ���� ���� true�� �л����� �⺻ ���� + ���� ���� + ��ϱ� ������ ���� ��ȯ�޾� ����Ѵ�. 

	    (case 3) ���л� ���� : ������ ���� ���� �л� 2���� �����ϰ�, ������ �л����� ����(�⺻���� + ����, ��ϱ�)�� ����Ѵ�. ��, 2�� �̸� ������ ��쿡�� ��� �����ϰ�, ������ ����Ѵ�.
		        <�� ���>
				- ���б� ������ �л��� ���� ����� ���� appliedNum ������ �����Ѵ�.
				
				- ���б� ������ ���� 2�� ������ ���: ���б� ��û ���θ� Ȯ���� ��, ���� ���°� true�� ������� ��� ���л����� �����ϰ�, ������ �л����� �⺻���� + ���� ���� + ��ϱ� ������ ����Ѵ�.
				
				- ���б� ������ ���� 3�� �̻��� ���: ���б� ��û ���θ� Ȯ���� ��, ��û�� �л����� GPA���� ���� �� �ִ� scoreArr[10] �迭�� �����ϰ�, ��û�� �л����� GPA���� ���� scoreArr�迭�� ��� GPA���� ���� ������� �����Ͽ���.
				                                  select1, select2�� ���б����� ������ GPA���� ���ϴ� ������,  select1�� ���� ���� GPA ��(scoreArr[0])����, select2�� �ι�°�� ���� GPA ��(scoreArr[1])���� �ʱ�ȭ�Ͽ���.
												  �� ��, ���л����� ������ GPA��(select1, select2)�� ���ϴ� �л��� ã�� �ش��ϴ� �л��� �⺻ ���� + ���� ���� + ��ϱ� ������ ���� ��ȯ�޾� ����Ѵ�.

	    (case 4) �����ϱ� : �޽��� ��� �� ���α׷��� �����ϴ� ����� �����Ѵ�.
   
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/17
   �ۼ���: �ڽ�ȫ
*/
void ScholarshipManagement::run()
{
	int menuSelect; //�޴� ��ȣ�� �Է¹��� �� �ִ� ���� ����
	bool loopStop = false; //while ������ ���������� ���� ���� ����. loopStop -> false : ��� while�� ����, loopStop -> true : while�� Ż��


	while (1)
	{
		cout << "�޴�: " << endl;
		cout << "1. ���б� ����" << endl;
		cout << "2. ���б� ������ ����" << endl;
		cout << "3. ���л� ����" << endl;
		cout << "4. �����ϱ�" << endl;
		cout << "* ������ �Է��Ͻʽÿ�: ";

		cin >> menuSelect; //����ڷκ��� �޴� ��ȣ�� �Է¹���

		switch (menuSelect) //�Է¹��� �޴� ��ȣ�� ��������, ��ȣ�� �ش��ϴ� �޴��� ����� �����ϵ��� switch ���� ������.
		{



		case 1: //���б� ���� ��� ����
		{

			int applyNum = 0; //���б��� ��û�� �л��� ���� ����ڷκ��� �Է¹ޱ� ���� ���� ����
			int studentArray[10] = { 0, }; //���б� ��û�� �л����� �ε��� ��ȣ�� �Է¹ޱ� ���� ���ǵ� �迭�̴�.

			for (int i = 0; i < num_of_students; i++) //�迭�� ���� �Ѿ�� �л����� �⺻ ������ ������� ����Ѵ�.
			{
				cout << (i + 1) << ") ";
				cout << studentList[i]->getStudentInfo();
				cout << endl;
			}

			cout << "*���� ��� �л����� ���� ������ ��ȣ�� �����ؼ� �Է��Ͻÿ�: ";

			cin >> applyNum; //���б� ��û�� �л��� ���� ����ڷκ��� �Է¹޴´�.

			for (int i = 0; i < applyNum; i++) //���б� ��û�� �л��� ����ŭ �л��� ��ȣ�� studentArray�迭�� ���������� ���� �Է¹޴´�.
			{
				cin >> studentArray[i];
			}

			for (int i = 0; i < applyNum; i++) //���� �л��� ������ studentList[studentArray[i]-1]�� ����Ǿ������Ƿ�, ���⿡ ������ ���б� ��û�� �л����� ���б� ��û ���¸� false���� true�� �ٲ��ش�. 
			{
				studentList[studentArray[i] - 1]->changeApplicationStatus();
			}

			cout << endl << endl << endl;

			break;
		}




		case 2: //���б� ������ ���� ��� ��� ����
		{
			for (int i = 0; i < num_of_students; i++)
			{
				if (studentList[i]->getApplicationStatus() == true) //���б� ���� ���°� true���� Ȯ��
				{
					cout << "- ";
					cout << studentList[i]->getStudentInfo(); //���б� ���� ���°� true�� �л����� �⺻ ������ ��ȯ�޾� �̸� ����Ѵ�.
					printf(" %.2f ", studentList[i]->getGPA()); //���б� ���� ���°� true�� �л����� ������ ��ȯ�޾� �̸� ����Ѵ�.
					cout << studentList[i]->getTuition() << "����" << endl; //���б� ���� ���°� true�� �л����� ��ϱ� ������ ��ȯ�޾� �̸� ����Ѵ�.
				}
			}
			cout << endl << endl << endl;
			break;
		}




		case 3: //���л� ���� ��� ����
		{
			int appliedNum = 0; //���б� ������ �� 

			for (int i = 0; i < num_of_students; i++)
			{
				if (studentList[i]->getApplicationStatus() == true) //���б� ���� ���°� true���� Ȯ��
				{
					appliedNum++; //���б� ������ �� ���
				}
			}

			if (appliedNum <= 2) //���б� ��û�� �л��� �� ���϶��,
			{
				for (int i = 0; i < num_of_students; i++)
				{
					if (studentList[i]->getApplicationStatus() == true) //���б� ��û�� �л�����

					{
						cout << "- ";
						cout << studentList[i]->getStudentInfo(); //�⺻ ������ ��ȯ�޾� ����Ѵ�.
						printf(" %.2f ", studentList[i]->getGPA()); //���� ������ ��ȯ�޾� ����Ѵ�.
						cout << studentList[i]->getTuition() << "����" << endl; //��ϱ� ������ ��ȯ�޾� ����Ѵ�.

					}
				}
			}

			if (appliedNum > 2) //���б� ��û�� �л��� 3�� �̻��̶��
			{

				double scoreArr[10] = { 0.0, }; // GPA�� ���� ������� �������� �迭 ����
				double select1 = 0.0; //���� ���� GPA���� ���� ���� ����
				double select2 = 0.0; //�ι�°�� ���� GPA���� ���� ���� ����


				for (int i = 0; i < num_of_students; i++)
				{
					if (studentList[i]->getApplicationStatus() == true) 
					{
						scoreArr[i] = studentList[i]->getGPA(); //scoreArr�� 1�������� ���б� ��û�� �л����� GPA������ ��� �迭�̴�.
						                                        
					}
				}


				for (int i = 0; i < num_of_students - 1; i++) //scoreArr�迭�� GPA���� ���� ������� �������ش�.
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


				select1 = scoreArr[0]; //���� ���� GPA������ select1 �ʱ�ȭ
				select2 = scoreArr[1]; //�ι� ���� ���� GPA������ select2 �ʱ�ȭ


				for (int i = 0; i < num_of_students; i++)
				{
					if (studentList[i]->getApplicationStatus() == true)
					{
						if (studentList[i]->getGPA() == select1 || studentList[i]->getGPA() == select2) //���� ���� GPA���� ���� �л��� �ι����� ���� GPA���� ���� �л��� �������
						{
							cout << "- ";
							cout << studentList[i]->getStudentInfo(); //�⺻ ������ ��ȯ�޾� ����Ѵ�.
							printf(" %.2f ", studentList[i]->getGPA()); //���� ������ ��ȯ�޾� ����Ѵ�.
							cout << studentList[i]->getTuition() << "����" << endl; //��ϱ� ������ ��ȯ�޾� ����Ѵ�.
						}
					}
				}
			}
				cout << endl << endl << endl;
				break;
		}

		



		case 4: //�����ϱ�
		{
			cout << " - �����մϴ�." << endl;
			loopStop = true;  //����ڰ� 4���� ���� loopStop ������ true�� �ǰ�, �̸� ���� while���� �������´�.
			break;
		}

		}

		if (loopStop == true) //while�� Ż��
			break;
	};

}





