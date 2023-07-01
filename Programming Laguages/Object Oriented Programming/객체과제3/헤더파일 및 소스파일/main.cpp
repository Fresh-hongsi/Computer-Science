#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Client.h" //������� Client.h�� �ҷ��´�.
#include "Movie.h" //������� Movie.h�� �ҷ��´�.
#include "TicketingManagement.h" //������� TicketingManagement.h�� �ҷ��´�.
#include <cstring>

using namespace std;


/* �Լ��̸�: main
   ���: ��ȭ ���� �ý����� �����ϴ� ����� �����Ѵ�.
	  <�󼼱��>
	   - clientArr�� Client ��ü���� ��� �ִ�.
	   - movieArr�� Movie ��ü���� ��� �ִ�. 
	   - ȸ�� ��ü ������ �迭, ȸ���� ��, ��ȭ ��ü ������ �迭, ��ȭ�� ���� �Ű������� �����ϸ� TicketingManagement ��ü 1�� ������ ��, ������ ��ü�� ����Լ� run�� ȣ�������ν� ���� �ý����� �۵��ǵ��� ����Ѵ�.
   
   �Ű�����: ����
   ��ȯ��: 0�̸� ���� ����, �� ���� ���� ��ȯ�Ǹ� ������ ����ȴ�.

   �ۼ���¥ : 2021/05/31
   �ۼ��� : �ڽ�ȫ
*/
int main(void)
{

	Client* clientArr[2];  //ũ�Ⱑ 2�� Client ��ü�� ������ �迭 clienArr ����
	Movie* movieArr[4]; //ũ�Ⱑ 4�� Movie ��ü�� ������ �迭 movieArr ����

	for (int i = 0; i < 2; i++)
	{
		clientArr[i] = NULL; //ȸ�� ��ü ������ �迭�� ��ҵ��� NULL�� �ʱ�ȭ
	}

	for (int i = 0; i < 4; i++)
	{
		movieArr[i] = NULL; //��ȭ ��ü ������ �迭�� ��ҵ��� NULL�� �ʱ�ȭ
	}


	/*
	 ȸ�� ���� �Է�(�ϵ��ڵ�)
	*/
	clientArr[0] = new Client("Kim", "ID_Kim", "PW_Kim", "010-1234-5678");
	clientArr[1] = new Client("Lee", "ID_Lee", "PW_Lee", "010-9876-5432");

	/*
	 ��ȭ ���� �Է�(�ϵ��ڵ�)
	*/
	movieArr[0] = new Movie("Show", "Park", "Drama");
	movieArr[1] = new Movie("Brother", "Hong", "Action");
	movieArr[2] = new Movie("WayOut", "Kang", "Mystery");
	movieArr[3] = new Movie("Call", "Ryu", "History");

	TicketingManagement ticketManager(clientArr, 2, movieArr, 4); //ȸ�� ��ü ������ �迭, ȸ���� ��, ��ȭ ��ü ������ �迭, ��ȭ�� ���� �Ű������� �����ϸ� TicketingManagement ��ü ����
	
	ticketManager.run(); //ticketManager�� ����Լ� run ����
	
	for (int i = 0; i < 2; i++) //�����Ҵ��� ȸ�� ��ü �޸𸮵��� ������Ų��.
	{
		delete clientArr[i];
	}

	for (int i = 0; i < 4; i++) //�����Ҵ��� ��ȭ ��ü �޸𸮵��� ������Ų��.
	{
		delete movieArr[i];
	}

	return 0;

}