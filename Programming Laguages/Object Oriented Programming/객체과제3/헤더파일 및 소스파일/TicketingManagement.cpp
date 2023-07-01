#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Client.h" //������� Client.h�� �ҷ��´�.
#include "TicketingManagement.h"

using namespace std;


/*
 Ŭ���� �̸�: TicketingManagement <Control Ŭ����>
 Ŭ���� ��� ����: clientList / clientNum / movieList / movieNum / systemLogInStatus / userID / userPW
 ���: TicketingManagement Ŭ������ �����ڷν��� ����� �����Ѵ�.
	  ������ ȣ���� ���� TicketingManagement�� ��� ���� clientList / clientNum / movieList / movieNum�� ���ڷ� ���޵� ����� �ʱ�ȭ�Ѵ�.
	  ���� ��ü ������ ���ÿ� �ý��� ���� �α��� ���θ� ��Ÿ���� ���� false��, ���α׷� ����ڿ��� �Է¹޾� ������ ID ���ڿ�, �н����� ���ڿ�, ��ȭ�̸� ���ڿ����� ���� NULL�� �ʱ�ȭ�Ѵ�. 

  �Ű����� : Client** cList -> ȸ������ ����Ʈ
            int cNum -> ȸ���� ��
			Movie** mList -> ��ȭ ����Ʈ
	        int mNum -> ��ȭ�� ��

�ۼ���¥: 2021/05/31
�ۼ���: �ڽ�ȫ
*/
TicketingManagement::TicketingManagement(Client** cList, int cNum, Movie** mList, int mNum)
{
	clientList = cList;
	clientNum = cNum;
	movieList = mList;
	movieNum = mNum; //���� ������ ��ȭ ����
	systemLogInStatus = false; //�ý��� ���� �� �α��� ���´� false, �α����� �Ϸ�Ǹ� �α��� ���� true
	userID = NULL;
	userPW = NULL;
	userMovieName = NULL;
	

}


/*
   �Լ��̸�: showMenu
   ���: ���α׷� ���� �޴��� ����ϴ� ����� �����Ѵ�.
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::showMenu()
{

	cout << "�޴�: " << endl;
	cout << "1. �α���" << endl;
	cout << "2. ��ȭ ��ü ��ȸ �� ����" << endl;
	cout << "3. ��ȭ �˻� �� ����" << endl;
	cout << "4. ���� ��ȭ ��ȸ " << endl;
	cout << "5. �����ϱ�" << endl;

}



/*
   �Լ��̸�: user_selectMenu
   ���: ���α׷� ����ڿ��� �޴� ���� ��ȣ�� �Է¹ް�, �� ��ȣ ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ������� �޴� ���� ��ȣ

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
int TicketingManagement::user_selectMenu() 
{
	int choice;

	cin >> choice;

	return choice;
}



/*
   �Լ��̸�: user_inputID
   ���: ���α׷� ����ڿ��� ID�� �Է¹޾� �̸� �ɹ����� userID�� ������ ��, userID�� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ������� ID �Է°� =  userID

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* TicketingManagement::user_inputID()
{
	char Istr[100] = { 0, };
	
	cin >> Istr;
	userID = new char[strlen(Istr) + 5];
	strcpy(userID, Istr);
	
	return userID;
	
}



/*
   �Լ��̸�: user_inputPW
   ���: ���α׷� ����ڿ��� �н����带 �Է¹޾� �̸� �ɹ����� userPW�� ������ ��, userPW�� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ������� �н����� �Է°� =  userPW

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* TicketingManagement::user_inputPW()
{

	char Pstr[100] = { 0, };

	cin >> Pstr;
	userPW = new char[strlen(Pstr) + 5];
	strcpy(userPW, Pstr);

	return userPW;

}



/*
   �Լ��̸�: user_selectMovie
   ���: ���α׷� ����ڿ��� ������ ��ȭ��ȣ�� �Է¹ް�, �� ��ȣ ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ������� ��ȭ ���� ��ȣ

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
int TicketingManagement::user_selectMovie() 
{
	int movieChoice;

	cin >> movieChoice;

	return movieChoice;
}



/*
   �Լ��̸�: user_inputMovieName
   ���: ���α׷� ����ڿ��� ��ȭ ������ �Է¹޾� �̸� �ɹ����� userMovieName�� ������ ��, userMovieName�� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ������� ��ȭ ���� �Է°� =  userMovieName

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* TicketingManagement::user_inputMovieName() 
{
	char Mstr[20] = { 0, };

	cin >> Mstr;
	userMovieName = new char[strlen(Mstr) + 5];
	strcpy(userMovieName, Mstr);
	return userMovieName;
}



/*
   �Լ��̸�: checkSystemLogInStatus
   ���: ������� systemLogInStatus �� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: �ý��� ���� �α��� ���� ���� �� -> true: ���� �ý��� �� �α����� �� ����
									     false: ���� �ý��� �� �α����� ���� ���� ����
									
   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
bool TicketingManagement::checkSystemLogInStatus() 
{
	return systemLogInStatus;
}



/*
   �Լ��̸�: stopLogIn
   ���: ������� systemLogInStatus�� ���� true�� �����Ѵ�.
   �Ű�����: ����
   ��ȯ��: ����� �ý��� ���� �α��� ���� ���� ��

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::stopLogIn()
{
	systemLogInStatus = true;
}



/*
   �Լ� �̸�: run
   ���: ����ڿ��� ���α׷� ���� �޴� �������̽��� �����ְ�, ����ڰ� �Է��ϴ� ��ȣ�� ���� ������ ���� ����� �����Ѵ�.

		(case 1) �α��� ��� ����
		(case 2) ��ȭ ��ü ��ȸ �� ���� ��� ���� 
		(case 3) ��ȭ �˻� �� ���� ��� ����
		(case 4) ���� ��ȭ ��ȸ ��� ����
		(case 5) ���α׷� ���� ��� ���� 

   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::run()
{
	int userSelectionMenu;
	bool loopStop = false;

	while (1)
	{

		this->showMenu();
		cout << "* ������ �Է��Ͻÿ�: ";

		userSelectionMenu = this->user_selectMenu(); //����ڷκ��� �޴����� ��ȣ�� �Է¹���



		switch (userSelectionMenu)
		{
		case 1: //�α��� ��� ����
		{
			this->LogIn();
			break;
		}
		case 2: //��ȭ ��ü ��ȸ �� ���� ��� ����
		{
			this->showListAndTicketing();
			break;
		}
		case 3: //��ȭ �˻� �� ���� ��� ����
		{
			this->searchAndTicketing();
			break;
		}
		case 4: //���� ��ȭ ��ȸ ��� ����
		{
			this->showAllTicketedMovie();
			break;
		}
		case 5: //���α׷� ���� ��� ����
		{
			this->exit();
			loopStop = true;
			break;
		}

		default:
			cout << "Illegal selection..." << endl<<endl<<endl;
		}

		if (loopStop == true)
			break;


	}
}



/*
   �Լ��̸�: LogIn
   ���: ����ڿ��� ID, �н����带 �Է¹޾� �α����ϴ� ����� �����Ѵ�.
        <�� ���>
		1. ����ڿ��� ID, �н����带 �Է¹ް�, �� �Է°��鿡 ��ġ�Ǵ� ȸ��(Client) ��ü�� ã�´�.
		2. ȸ�� ������ ��ġ�ϴ� ��ü�� �ִٸ�, �ش� ��ü�� �α��� ���¸� true�� �ٲ������ν� �α��� ������ ��, �α��� ���� �޼����� ����Ѵ�.
		   ���� �ý��� �� �α����� ���������Ƿ� �ý��� ���� �α��� ���µ� true�� �ٲپ������ν� ���̻��� �α����� �����ϵ��� �Ѵ�.

		2 - <Alternatives> ���� ȸ�� ������ ��ġ�ϴ� ��ü�� ���ٸ�, �α��� ���� �޼����� ����Ѵ�.
   
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::LogIn()
{

	if (this->checkSystemLogInStatus() == false) //�ý��� �� �α����� �ѹ��� �������� �ʾ��� ��쿡 ����
	{
		char IDstr[100] = { 0, }; //�Է¹��� ID�� ������ ���ڹ迭 ����
		char PWstr[100] = { 0, }; //�Է¹��� �н����带 ������ ���ڹ迭 ���� 

		cout << " - ID �Է��Ͻÿ�: ";
		strcpy(IDstr, this->user_inputID()); //����ڷκ��� ID�� �Է¹޾� IDstr�� ����

		cout << " - �н����� �Է��Ͻÿ�: ";
		strcpy(PWstr, this->user_inputPW()); //����ڷκ��� �н����带 �Է¹޾� PWstr�� ����


		for (int i = 0; i < clientNum; i++)
		{
			if ((strcmp(IDstr, clientList[i]->getClientID()) == 0) && (strcmp(PWstr, clientList[i]->getClientPW()) == 0)) //�Է¹��� ID, PW ���ڿ��� �� �� ��ġ�ϴ� ȸ�� ��ü�� �ִٸ�
			{
				clientList[i]->changeLogInStatus(); //ID, �н����� ���� ��ġ�ϴ� ȸ�� ��ü�� �α��� ������ ���
				cout << " -> �α��ο� �����߽��ϴ�.";
				cout << endl << endl << endl;

				this->stopLogIn(); //�ý��� �� �ѹ� �α����� �����Ǿ����Ƿ�, �߰����� �α����� ���� ���ϵ��� �����ϰ� �ϱ� ����

				return;
			}

		}

		for (int i = 0; i < clientNum; i++)
		{
			if ((strcmp(IDstr, clientList[i]->getClientID()) != 0) || (strcmp(PWstr, clientList[i]->getClientPW()) != 0)) //�Է¹��� ID, PW ���ڿ��� �� �� ��ġ�ϴ� ȸ�� ��ü�� ���ٸ�
			{
				cout << " -> �α��ο� �����߽��ϴ�.";
				cout << endl << endl << endl;

				return;
			}
		}
	}

	if (this->checkSystemLogInStatus() == true) //�ý��� �� �α����� �ѹ��̶� �������� ��� ����
	{
		cout << "�̹� �α��� �Ǿ��ֽ��ϴ�." << endl << endl << endl; 
		return;
	}


}



/*
   �Լ��̸�: showListAndTicketing
   ���: ����ڿ��� ��ȭ ��ü ����� �����ְ�, �� �߿��� ������ ��ȭ�� ��ȣ�� �Է¹޾� �ش� ��ȭ�� ���Ÿ� �����Ѵ�. ���� ���ŵ� ��ȭ�� ȸ���� ���� ����Ʈ�� �߰���Ų��.
		<�� ���>
		1. �α����� ���� ���� ���¿��� �� ����� ������ �� ����.
		2. �α��� ���ε� ȸ�� ��ü�� ã�� ��ȭ ��ü ����� �����ش�.
		3. ����ڴ� consoleâ�� ��µ� ��ȭ ��ü ��� �� ������ ��ȭ ��ȣ�� �Է��Ѵ�.
		4. �Է¹��� ��ȭ ��ȣ�� �����ϴٸ�, �α��� ���ε� ȸ�� ��ü�� ���� ����Ʈ�� �ش� ��ȣ�� ��ȭ�� �߰��Ѵ�. �׸��� ��ȭ �̸��� ������ ���� �Ϸ� �޼����� ����Ѵ�.
		4 - <Alternatives> ���� �Է¹��� ��ȭ ��ȣ�� �������� �ʴٸ� ���� ���� �޼����� ����Ѵ�.
		
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::showListAndTicketing()
{
	int userMovieSelectionNum = 0; //��ȭ ��ȣ�� �Է¹��� �� �ִ� ���� ����
	

	if (this->checkSystemLogInStatus() == false) //���� �ý��ۻ� �α����� ���� ���� ���¶��
	{
		cout << "�α��� �� �̿� ������ �����Դϴ�";
		cout << endl << endl << endl;
	}



	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true) //�α��� ���ε� ������ ã��
		{
			while (1)
			{
				for (int j = 0; j < movieNum; j++)
				{
					cout << ' ' << j + 1 << ") ";
					cout << movieList[j]->getMovieInfo(); //��ȭ ��ü���� ��ȭ �������� ��ȯ�޾� ����Ѵ�.  
					cout << endl; 
				}

				cout << "* ������ ��ȭ�� �����Ͻÿ� : ";

				userMovieSelectionNum = this->user_selectMovie(); //����ڷκ��� ������ ��ȭ ��ȣ�� �Է¹���

				if (userMovieSelectionNum > 0 && userMovieSelectionNum < movieNum + 1) //�Է� ���� ��ȭ ��ȣ�� ������ ���
				{

					clientList[i]->addMovie(movieList[userMovieSelectionNum - 1]); //���� ������ ��ȭ ��ü�� movieList[userSelectionNum-1]�� ����Ǿ������Ƿ�, ���⿡ ������ �ش� ��ȭ�� �α��ε� ȸ���� ���� ����Ʈ�� �߰��Ѵ�. 
					cout << " -> ��ȭ " << '"' << movieList[userMovieSelectionNum - 1]->getMovieName() << '"' << " ���ŵǾ����ϴ�.";
					cout << endl << endl << endl;

					break;
				}
				else
				{
					cout << "��ȭ ��ȣ�� �ùٸ��� �����Ͻʽÿ�.";
					cout << endl << endl << endl;
	
				}
			}
			
		}

	}
}




/*
   �Լ��̸�: searchAndTicketing
   ���: ������ ��ȭ�� ������ ����ڷκ��� �Է¹޾� ����� ��ġ�ϴ� ��ȭ�� ��ȸ�ؼ� ����Ѵ�. 
        �� �� �˻������ ������ ��ȭ�� �� ������ ��ȭ�� ��ȣ�� �Է¹޾� �ش� ��ȭ�� ���Ÿ� �����Ѵ�. ���� ���ŵ� ��ȭ�� ȸ���� ���� ����Ʈ�� �߰���Ų��.
  
		<�� ���>
		1. �α����� ���� ���� ���¿��� �� ����� ������ �� ����.
		2. �α��� ���ε� ȸ�� ��ü�� ã�� ��ȭ ������ �Է��� �� �ִ� �ʵ带 ����Ѵ�.
		3. ����ڴ� consoleâ�� ������ ��ȭ ������ �Է��Ѵ�.
		4. �Է¹��� ��ȭ ������ ������� movieList�� �ִ� ��ȭ������ ��ġ�ϴ� �� Ȯ���Ѵ�.
		5. ��ġ�ϴ� ��ȭ�� ���� ��� �ش� ��ȭ ������ ����Ѵ�.
		6. ��ġ�ϴ� ��ȭ�� �ִٸ� ��ġ�ϴ� ��ȭ�� �������� consoleâ�� ����ϰ�, ��ġ�� ��ȭ���� tempArr[4]�迭�� ��� �ε��� ���� �պκк��� ���������� ��ġ�ϴ� ��ȭ ��ü�� �ڸ��ϵ��� �����Ͽ���.
		7. ����ڴ� consoleâ�� ��µ� �˻� ��� �� ������ ��ȭ ��ȣ�� �Է��Ѵ�.
		8. �Է¹��� ��ȭ ��ȣ�� �����ϴٸ�, �α��� ���ε� ȸ�� ��ü�� ���� ����Ʈ�� �ش� ��ȣ�� ��ȭ�� �߰��Ѵ�. �׸��� ��ȭ �̸��� ������ ���� �Ϸ� �޼����� ����Ѵ�.
		8 - <Alternatives> ���� �Է¹��� ��ȭ ��ȣ�� �������� �ʴٸ� ���� ���� �޼����� ����Ѵ�.

   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::searchAndTicketing()
{
	char movieSearchArr[20] = { 0, }; //�Է¹��� ��ȭ������ ������ ���ڹ迭 ����
	int searchIdx = 0; //�Է¹��� ��ȭ ����� ��ġ�ϴ� ��ȭ�� �ִ� �� Ȯ���ϱ� ���� �ε��� ��ȣ -> searchIdx�� movieNum(��ȭ ����)�� ���ٸ� ��ġ�ϴ� ��ȭ ����
	int movieIdx = 0; //��ȭ ���� ��ġ�ϸ� ��ȣ�� ��µ� idx
	int userMovieSelectionNum = 0; //��ȭ ��ȣ�� �Է¹��� �� �ִ� ���� ����
	Movie* tempArr[4]; //�ӽ÷� ���� ��ȭ ��ü ������ �迭


	for (int i = 0; i < 4; i++)
	{
		tempArr[i] = NULL; //�ӽ÷� ���� ��ȭ ��ü ������ �迭 ��ҵ��� NULL�� �ʱ�ȭ
	}

	if (this->checkSystemLogInStatus() == false) //���� �ý��ۻ� �α����� ���� ���� ���¶��
	{
		cout << "�α��� �� �̿� ������ �����Դϴ�";
		cout << endl << endl << endl;
	}

	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true) //�α��� ���ε� ������ ã��
		{
			cout << "* �˻��� ������ �Է��Ͻÿ�: ";

			strcpy(movieSearchArr, user_inputMovieName()); //����ڷκ��� ������ ��ȭ ������ �Է¹޾� movieSearchArr�� ����

			for (int j = 0; j < movieNum; j++)
			{
				if (strcmp(movieSearchArr, movieList[j]->getMovieName()) != 0) //�Է¹��� ��ȭ ������ ����Ʈ�� �ִ� ��ȭ �������� ����, Ʋ���ٸ� ���� �ε��� ��ȭ�̸��� ��
				{
					searchIdx++; // �Է¹��� ��ȭ ����� ��ġ�ϴ� ��ȭ�� ���ٸ� 1�� ������Ŵ���ν� searchIdx�� movieNum(��ȭ ����)�� �������� ��ġ�ϴ� ��ȭ�� ����Ʈ�� ���ٴ� ����
				}

			}

			if (searchIdx == movieNum) //����Ʈ ������ �����ߴµ� ��ȭ ������ ��ġ�ϴ� �� ���ٸ� �ش� ��ȭ ���� ���
			{
				cout << " -> �ش� ��ȭ�� �����ϴ�.";
				cout << endl << endl << endl;
				return;
			}

			for (int j = 0; j < movieNum; j++)
			{
				if ((strcmp(movieSearchArr, movieList[j]->getMovieName()) == 0)) //�Է¹��� ��ȭ ����� ��ġ�ϴ� ��ȭ�� �ִٸ�
				{
					cout << ' ' << movieIdx + 1 << ") ";
					cout << movieList[j]->getMovieInfo() << endl; //��ġ�ϴ� ��ȭ�� ������ �ʵ忡 ���

					tempArr[j] = movieList[j]; //��ġ�ϴ� ��ȭ���� tempArr�� ����
					movieIdx++;  //�ᱹ movieIdx�� ��ġ�ϴ� ��ȭ�� ������
				}

			}

			for (int i = 0; i < movieNum - 1; i++) //tempArr �迭�� �ִ� ��ȭ ����Ʈ�� ���� -> �迭�� ����ִ� �迭 ��Ұ� NULL�̸� SWAP�� ���������ν� �ε��� ���� �պκк��� ���������� ��ġ�ϴ� ��ȭ ��ü�� �ڸ��ϵ��� �����Ͽ���
			{
				for (int j = 0; j < movieNum - 1; j++)
				{
					if (tempArr[j] == NULL)
					{
						Movie* tempMovie = tempArr[j];
						tempArr[j] = tempArr[j + 1];
						tempArr[j + 1] = tempMovie;
					}

				}
			}

			cout << "* ������ ��ȭ�� �����Ͻÿ�: ";
			
			userMovieSelectionNum = this->user_selectMovie(); //����ڷκ��� ������ ��ȭ ��ȣ�� �Է¹���

			if (userMovieSelectionNum > 0 && userMovieSelectionNum < movieIdx + 1) //�Է� ���� ��ȭ ��ȣ�� ������ ���
			{
				clientList[i]->addMovie(tempArr[userMovieSelectionNum - 1]); //���� ������ ��ȭ ��ü�� tempArr[userSelectionNum-1]�� ����Ǿ������Ƿ�, ���⿡ ������ �ش� ��ȭ�� �α��ε� ȸ���� ���� ����Ʈ�� �߰��Ѵ�.
				cout << " -> ��ȭ " << '"' << tempArr[userMovieSelectionNum - 1]->getMovieName() << '"' << " ���ŵǾ����ϴ�.";
				cout << endl << endl << endl;
			}

			else
			{
				cout << "��ȭ ��ȣ�� �ùٸ��� �����Ͻʽÿ�.";
				cout << endl << endl << endl;

			}
		}
	}
}




/*
   �Լ��̸�: showAllTicketedMovie
   ���: ����ڿ��� ���� ��ȭ ��ȸ ���񽺸� �����ϴ� ����� �����Ѵ�.
		<�� ���>
		1. �α����� ���� ���� ���¿��� �� ����� ������ �� ����.
		2. �α��� ���ε� ȸ�� ��ü�� ã�� �ش� ȸ���� ���� ������ ����Ѵ�.
		
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::showAllTicketedMovie()
{
	if (this->checkSystemLogInStatus() == false) //���� �ý��ۻ� �α����� ���� ���� ���¶��
	{
		cout << "�α��� �� �̿� ������ �����Դϴ�";
		cout << endl << endl << endl;
	}

	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true) //�α��� ���ε� ������ ã��
		{

			clientList[i]->showMyMovieList(); //�α��� ���ε� ȸ���� ��ȭ ���� ����Ʈ�� ����Ѵ�.
			cout << endl << endl << endl;
		}
	}
}



/*
   �Լ��̸�: exit
   ���: ���α׷� ���� ����� �����Ѵ�.
		<�� ���>
		1. �α��� �Ǿ��ִ� ȸ�� ��ü�� ã�� �α׾ƿ���Ų��.
		2. ���α׷� ���� �޼����� ����Ѵ�.

   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
void TicketingManagement::exit()
{
	for (int i = 0; i < clientNum; i++)
	{

		if (clientList[i]->getLogInStatus() == true)
		{

			clientList[i]->changeLogInStatus();
			
		}
	}
	cout << " -> �����մϴ�." << endl;
}



/*
   �Լ��̸�: Ŭ���� TicketingManagement�� �Ҹ���
   ��� : TicketingManagement ��ü�� �Ҹ�� �� ȣ��ȴ�.
		 �����Ҵ��� userID, userPW, userMovieName �޸𸮵��� ���������ش�.
   �Ű����� : ����
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
TicketingManagement::~TicketingManagement()
{
	delete[]userID;
	delete[] userPW;
	delete[] userMovieName;
}
