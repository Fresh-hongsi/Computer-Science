#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Client.h" //������� Client.h�� �ҷ��´�.

using namespace std;

/*
   �Լ��̸�: Ŭ���� Client�� ������
   ��� :  Client Ŭ������ �����ڷν��� ����� �����Ѵ�. 
          ������ ȣ���� ���� Client�� ��� ���� name / ID / PW / phoneNum�� ���ڷ� ���޵� ������ ���� �����Ҵ��Ͽ� �ʱ�ȭ�Ѵ�.
          ���� ��ü ������ ���ÿ� ȸ���� �α��� ���� ���θ� ��Ÿ���� ���� false, ȸ���� ������ ��ȭ ���� �ε��� ���� 0, ȸ���� ������ ��ȭ ����Ʈ�� myMovieList(��ü ������ �迭)�� NULL������ �ʱ�ȭ�Ѵ�.
		  

   �Ű����� : const char* cName -> ȸ���� �̸�
             const char* cID -> ȸ���� ID
			 const char* cPW -> ȸ���� �н�����
	         const char* cPhoneNum -> ȸ���� �޴��� ��ȣ
			 

   ��ȯ�� : ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
Client::Client(const char* cName, const char* cID, const char* cPW, const char* cPhoneNum)
{
	name = new char[strlen(cName) + 5];
	strcpy(name, cName);

	ID = new char[strlen(cID) + 5];
	strcpy(ID, cID);

	PW = new char[strlen(cPW) + 5];
	strcpy(PW, cPW);

	phoneNum = new char[strlen(cPhoneNum) + 5];
	strcpy(phoneNum, cPhoneNum);


	for (int i = 0; i < 10; i++)
	{
		myMovieList[i] = NULL;
	}

	myMovieIdx = 0;
	LogInStatus = false;

}


/*
   �Լ��̸�: getClientName
   ���: ������� name�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: name

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Client::getClientName()
{
	return name;
}


/*
   �Լ��̸�: getClientID
   ���: ������� ID�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ID

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Client::getClientID()
{
	return ID;
}


/*
   �Լ��̸�: getClientPW
   ���: ������� PW�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: PW

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Client::getClientPW()
{
	return PW;
}


/*
   �Լ��̸�: getClientPhoneNum
   ���: ������� phoneNum�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: phoneNum

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Client::getClientPhoneNum()
{
	return phoneNum;
}


/*
   �Լ� �̸�: getLogInStatus
   ���: ������� LogInStatus�� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ȸ���� �α��� ���� ���� �� -> true: ���� �α����� �Ϸ��
									 false: ���� �α����� ���� ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
bool Client::getLogInStatus()
{

	return LogInStatus;
}


/*
   �Լ� �̸�: changeLogInStatus
   ���: ������� LogInStatus�� ���� �����Ѵ�.
	  �α��� ���� ���� ���� true�̸� false�� ��ȯ�ϵ���,
	  �α��� ���� ���� ���� false�̸� true�� ��ȯ�ϵ��� �ϴ� ����� �����Ѵ�.

   �Ű�����: ����
   ��ȯ��: ����� ȸ���� �α��� ���� ���� ��

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void Client::changeLogInStatus()
{
	if (LogInStatus == false) //�α����� ���� �ʾҾ��ٸ�
	{
		this->LogInStatus = true; //�α��� ���¸� �α��� �Ϸ�� ���� (�α��� ����)

	}

	else //�α����� �Ǿ��־��ٸ�
	{
		this->LogInStatus = false; //�α��� ���¸� �α��� ���� �������� ���� (�α׾ƿ� ���)
	}
	

}


/*
   �Լ��̸�: getMyMovieIdx
   ���: ������� myMovieIdx�� ����� ���� ��ȯ�Ѵ�.      
   �Ű�����: ����
   ��ȯ��: myMovieIdx

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
int Client::getMyMovieIdx()
{
	return myMovieIdx;
}


/*
   �Լ��̸�: addMovie
   ���: ȸ���� ��ȭ ����Ʈ�� ȸ���� ������ ��ȭ�� �߰��Ѵ�.
        ��, Client ��ü�� ����� Movie* myMovieList[10]�� Movie��ü�� ��´�. Movie��ü�� myMovieList �迭�� ����Ǹ�, ��ȭ ���� �ε����� 1 �������� ���´�.
   �Ű�����: Movie* myMovie
   ��ȯ��: ����
  
   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void Client::addMovie(Movie* myMovie)
{
	myMovieList[myMovieIdx] = myMovie;
	myMovieIdx++;
}


/*
   �Լ��̸�: showMyMovieList
   ��� : myMovieList�� �ִ� ��ȭ���� ����(��ȭ �̸�, ��ȭ ����, ��ȭ �帣)�� ��� ���ڿ��� ��� ����Ѵ�.
   �Ű����� : ����
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void Client::showMyMovieList()
{
	for (int i = 0; i < myMovieIdx; i++)
	{
		cout << " -> " << myMovieList[i]->getMovieInfo();
		cout << endl;
	}
}


/*
   �Լ��̸�: Ŭ���� Client�� �Ҹ���
   ��� : Client ��ü�� �Ҹ�� �� ȣ��ȴ�.
		 �����Ҵ��� ȸ�� �̸�, ȸ���� ID, ȸ���� �н�����, ȸ���� �޴��� ��ȣ �޸𸮵��� ���������ش�.
   �Ű����� : ����
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
Client::~Client()
{
	delete[]name;
	delete[]PW;
	delete[]ID;
	delete[]phoneNum;
}