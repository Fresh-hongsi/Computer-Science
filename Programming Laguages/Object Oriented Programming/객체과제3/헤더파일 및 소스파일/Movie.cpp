#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Movie.h" //������� Movie.h�� �ҷ��´�.

using namespace std;


/*
   �Լ��̸�: Ŭ���� Movie�� ������
   ��� :  Movie Ŭ������ �����ڷν��� ����� �����Ѵ�.
          ������ ȣ���� ���� Movie�� ��� ���� movieName / movieDirector / movieGenre�� ���ڷ� ���޵� ������ ���� �����Ҵ��Ͽ� �ʱ�ȭ�Ѵ�.
		  ���� ��ü ������ ���ÿ� ��ȭ ������ ��ȯ�� ���ڿ��� movieInfoStr�� NULL������ �ʱ�ȭ�Ѵ�.


   �Ű����� : const char* mName -> ��ȭ�� ����
			 const char* mDirector -> ��ȭ ���� �̸�
			 const char* mGenre -> ��ȭ�� �帣
			 
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
Movie::Movie(const char* mName, const char* mDirector, const char* mGenre)
{
	movieName = new char[strlen(mName) + 5];
	strcpy(movieName, mName);

	movieDirector = new char[strlen(mDirector) + 5];
	strcpy(movieDirector, mDirector);

	movieGenre = new char[strlen(mGenre) + 5];
	strcpy(movieGenre, mGenre);

	movieInfoStr = NULL;
}



/*
   �Լ��̸�: getMovieName
   ���: ������� movieName�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: movieName

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Movie::getMovieName()
{
	return movieName;
}


/*
   �Լ��̸�: getMovieDirector
   ���: ������� movieDirector�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: movieDirector

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Movie::getMovieDirector()
{
	return movieDirector;
}


/*
   �Լ��̸�: getMovieGenre
   ���: ������� movieGenre�� ����� ���� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: movieGenre

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Movie::getMovieGenre()
{
	return movieGenre;
}


/*
   �Լ��̸�: getMovieInfo
   ���: ��� ���� movieInfoStr�� ��ȭ ����, ��ȭ ����, ��ȭ �帣 ������ ������ ���ڿ��� �����ϰ�, �̸� ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: movieInfoStr

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
char* Movie::getMovieInfo()
{
	char movieInfoArr[50] = { 0, };

	sprintf(movieInfoArr, "%s, %s, %s", this->getMovieName(), this->getMovieDirector(), this->getMovieGenre());

	movieInfoStr = new char[strlen(movieInfoArr) + 5];

	strcpy(movieInfoStr, movieInfoArr);

	return movieInfoStr;
}



/*
   �Լ��̸�: Ŭ���� Movie�� �Ҹ���
   ��� : Movie ��ü�� �Ҹ�� �� ȣ��ȴ�.
		 �����Ҵ��� ��ȭ ����, ��ȭ ����, ��ȭ �帣, ��ȭ ���� ���ڿ� �޸𸮵��� ���������ش�.
   �Ű����� : ����
   ��ȯ�� : ����

   �ۼ���¥: 2021/05/31
   �ۼ���: �ڽ�ȫ
*/
Movie::~Movie()
{
	delete[]movieName;
	delete[]movieDirector;
	delete[]movieGenre;
	delete[]movieInfoStr;
}