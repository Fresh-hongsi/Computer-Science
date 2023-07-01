#include "Book.h"
#include "Library.h"
#include <iostream>

using namespace std;



/*
�Լ� �̸�: main
���: Library ��ü�� 10���� Book ��ü�� �����ϰ� �����Ѵ�.
�Ű�����: ����
��ȯ��: int -> 0 �̸� ���α׷��� ����ȴ�.

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
int main(void)
{
	Library lib("Hongik Library"); //Library ��ü ����, �Ű������� Hongik Library�� �޾� lib ��ü�� ������ ���ÿ� �ʱ�ȭ�� ������.


	int menuSelect;       //�޴��� ��ȣ�� �����ϴ� ���� ����
	bool loopStop = false;  //while ������ ���������� ���� ���� ����. loopStop -> true : ��� while�� ����, loopStop -> false : while�� Ż��
	                                                              

	lib.bookRegister("Bird", "Kim", 2010, 234);    // ���� ����� ������, ������ ������ �޾� bookRegister�Լ��� ���� ���� ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�.
	lib.bookRegister("Dog", "Lee", 2011, 342);     // ���� ����� ������, ������ ������ �޾� bookRegister�Լ��� ���� ���� ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�.
  	lib.bookRegister("Hippo", "Park", 2015, 112);  // ���� ����� ������, ������ ������ �޾� bookRegister�Լ��� ���� ���� ��ü�� �����ϰ� �ʱ�ȭ�Ѵ�. 



	while (1)
	{
		cout << "�޴�: " << endl;
		cout << "1. ���� �뿩" << endl;
		cout << "2. ���� �뿩 ���" << endl;
		cout << "3. �����ϱ�" << endl;
		cout << "* ������ �Է��Ͻʽÿ�: ";
		
		cin >> menuSelect;

		switch (menuSelect) //�Է¹��� �޴� ��ȣ�� ��������, ��ȣ�� �ش��ϴ� �޴��� ����� �����ϵ��� switch ���� ������.
		{
			case 1:
			{

				lib.bookRental_Possible(); //bookRental_Possible �Լ��� bookRental �Լ��� ���������� ȣ�������ν� ���� �뿩 ����� ������.
				lib.bookRental();

				cout << endl << endl;
				break;

			}
			case 2:
			{
				lib.bookRental_Statistics();  //bookRental_Statistics �Լ��� ȣ�������ν� ���� �뿩 ��� ��� ����� ������.
				
				cout << endl << endl;
				break;
			}
			case 3:
			{
				cout << " - �����մϴ�." << endl;
				loopStop = true;  //����ڰ� 3���� ���� loopStop ������ true�� �ǰ�, �̸� ���� while���� �������´�.
				break;
			}

		}
		if (loopStop == true) //while�� Ż��
			break;
	}
	return 0;


}
