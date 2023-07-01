#ifndef __TICKETINGMANAGEMENT_H__
#define __TICKETINGMANAGEMENT_H__
#include "Client.h"
#include "Movie.h"


/*
Ŭ���� �̸� : TicketingManagement <Control Ŭ����>
Ŭ���� ��� ����:  clientList / clientNum / movieList / movieNum / systemLogInStatus / userID / userPW / userMovieName


��� : ��ȭ ���ſ� ���� ������ ���� ����� ������

	< private ����Լ� >
	 1. void showMenu(): �޴� â�� ����Ѵ�.
	 2. int user_selectMenu(): ����ڿ��� ������ �޴� ��ȣ�� �Է¹ް�, �̸� ��ȯ�Ѵ�.
	 3. char* user_inputID(): ����ڿ��� ID�� �Է¹ް�, �̸� ��ȯ�Ѵ�.
	 4. char* user_inputPW(): ����ڿ��� �н����带 �Է¹ް�, �̸� ��ȯ�Ѵ�.
	 5. int user_selectMovie(): ����ڿ��� ������ ��ȭ�� ��ȣ�� �Է¹ް�, �̸� ��ȯ�Ѵ�.
	 6. char* user_inputMovieName(): ����ڿ��� ������ ��ȭ�� ������ �Է¹ް�, �̸� ��ȯ�Ѵ�.
	 7. bool checkSystemLogInStatus(): �ý��� �� �α����� �Ǿ��ִ� �� Ȯ���Ѵ�.
	 8. void stopLogIn(): �ý��ۻ� �α����� �Ǿ��ִٸ�, ���̻��� �α��� �õ��� �����Ѵ�.
	 9. void LogIn(): �α��� ����� �����Ѵ�.
	 10. void showListAndTicketing(): ��ȭ ��ü ��ȸ �� ���� ����� �����Ѵ�.
	 11. void searchAndTicketing(): ��ȭ �˻� �� ���� ����� �����Ѵ�.
	 12. void showAllTicketedMovie(): ���ŵ� ��ȭ ���� ��ȸ ����� �����Ѵ�.
	 13. void exit(): ���α׷� ���� ����� �����Ѵ�.

	< public ����Լ� >
	1. TicketingManagement(Client** cList, int cNum, Movie** mList, int mNum)
	  -> ȸ�� ����Ʈ, ȸ�� ��, ��ȭ ����Ʈ, ��ȭ �� ������ �޾� ��ü�� �����Ѵ�. 
	     �ý��� ���� �α��� ���� ���� ��, ����ڿ��� �Է¹޾� ������ ID ���ڿ�, ����ڿ��� �Է¹޾� ������ �н����� ���ڿ�, ����ڿ��� �Է¹޾� ������ ��ȭ���� ���ڿ��� ��ü ������ ���ÿ� ������ ������ �ʱ�ȭ�Ѵ�.

	2. void run()
	  -> ���α׷� ������ �α��� / ��ȭ ��ü ��ȸ �� ���� / ��ȭ �˻� �� ���� / ���� ��ȭ ��ȸ / �����ϱ� ����� �����Ѵ�. 

	3. ~TicketingManagement()
	  -> �Ҹ��ڸ� ���� �����Ҵ��� �޸𸮸� �����Ѵ�. 


�ۼ���¥ : 2021/05/31
�ۼ��� : �ڽ�ȫ
*/
class TicketingManagement
{
private:
	Client** clientList; // clientList�� client���� �ּҰ��� ���� �迭(client��ü ������ �迭)�� �ּҸ� ����.
	int clientNum; //ȸ���� ��
	Movie** movieList; // movieList�� movie���� �ּҰ��� ���� �迭(client��ü ������ �迭)�� �ּҸ� ����.
	int movieNum; //��ȭ�� ��

	bool systemLogInStatus; //�ý��� �� �α����� �������� Ȯ���ϱ� ���� ���� 
	char* userID; //���α׷� ����ڿ��� ���� �Է� ���� ȸ���� ID�� �����ϱ� ���� ����
	char* userPW; //���α׷� ����ڿ��� ���� �Է� ���� ȸ���� �н����带 �����ϱ� ���� ����
	char* userMovieName; //���α׷� ����ڰ� ��ȭ �˻��� �� �Է��� ��ȭ ������ �����ϱ� ���� ���ڿ�

	void showMenu();

	int user_selectMenu();

	char* user_inputID();

	char* user_inputPW();

	int user_selectMovie();

	char* user_inputMovieName();

	bool checkSystemLogInStatus();

	void stopLogIn();

	
	void LogIn();

	void showListAndTicketing();

	void searchAndTicketing();

	void showAllTicketedMovie();

	void exit();
	

public:


	TicketingManagement(Client** cList, int cNum, Movie** mList, int mNum);

	void run();

	~TicketingManagement();



};
#endif