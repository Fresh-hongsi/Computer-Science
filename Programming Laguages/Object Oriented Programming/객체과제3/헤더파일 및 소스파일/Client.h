#ifndef __CLIENT_H__
#define __CLIENT_H__
#include "Movie.h"


/*
Ŭ���� �̸� : Client <Entity Ŭ����>
Ŭ���� ��� ����:  name / ID / PW / phoneNum / LogInStatus / myMovieIdx / myMovieList 

��� : ȸ���� ���� ������ ���� ����� ������

	< private ����Լ� >
	 1. char* getClientName(): ȸ���� �̸��� ��ȯ�Ѵ�.
	 2. char* getClientPhoneNum(): ȸ���� �޴��� ��ȣ�� ��ȯ�Ѵ�.
	 3. int getMyMovieIdx(): ȸ���� ������ ��ȭ ���� �ε��� ���� ��ȯ�Ѵ�.
	
	< public ����Լ� >
	 1. Client(const char* cName, const char* cID, 	const char* cPW, const char* cPhoneNum)
	   -> ȸ���� �̸�, ID, �н�����, �޴�����ȣ ������ �޾� ��ü�� �����Ѵ�. ȸ���� �α��� ���� ���θ� ��Ÿ���� ��, ȸ���� ������ ��ȭ ���� �ε��� ��, ȸ���� ������ ��ȭ ����Ʈ�� ��ü ������ ���ÿ� ������ ������ �ʱ�ȭ�Ѵ�.
	 
	 2. char* getClientID()
	   -> ȸ���� ID ������ ��ȯ�Ѵ�.
	
	 3. char* getClientPW()
	   ->ȸ���� �н����� ������ ��ȯ�Ѵ�.
	 
	 4. void changeLogInStatus()
	   -> ȸ���� �α��� ���� ���� ���� ��ȯ�Ѵ�. false -> �α����� ���� ���� / true -> �α����� �Ϸ�

	 5. void changeLogInStatus()
	   -> ȸ���� �α��� ���� ���� ���� �ٲ��ش�.

	 6. void addMovie(Movie* myMovie)
	   -> ������ ��ȭ�� ������ ȸ���� ���� ������ �߰��Ѵ�

	 7. void showMyMovieList()
	   -> ȸ���� ��ȭ ���� ������ �ִ� ��ȭ���� ������ ����Ѵ�.

	 8. ~Client()
	  -> �Ҹ��ڸ� ���� �����Ҵ��� �޸𸮸� �����Ѵ�. 
	

�ۼ���¥ : 2021/05/31
�ۼ��� : �ڽ�ȫ
*/

class Client
{
private:
	char* name; //ȸ���� �̸�
	char* ID; //ȸ���� ID
	char* PW; //ȸ���� �н�����
	char* phoneNum; //ȸ���� �޴��� ��ȣ
	bool LogInStatus; //ȸ���� �α��� ����
	int myMovieIdx; //ȸ���� ������ ��ȭ ���� �ε���
	Movie* myMovieList[10]; //ȸ���� ������ ��ȭ ����Ʈ
	
	char* getClientName();

	char* getClientPhoneNum();

	int getMyMovieIdx();
	
public:

	Client(const char* cName, const char* cID, 	const char* cPW, const char* cPhoneNum);

	char* getClientID();

	char* getClientPW();

	bool getLogInStatus();

	void changeLogInStatus();

	void addMovie(Movie* myMovie);

	void showMyMovieList();

	~Client();
};
#endif