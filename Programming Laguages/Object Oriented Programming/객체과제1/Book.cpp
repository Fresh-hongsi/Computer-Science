#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

/*
�Լ� �̸�: Book
���: Book Ŭ������ �����ڷν��� ����� �����Ѵ�. ���� ��ü ������ ���ÿ� å�� �뿩 ���θ� ��Ÿ���� ���� bookState���� true�� �ʱ�ȭ�Ѵ�.
�Ű�����: const char* bName -> ������ ����
         const char* bAuthor -> ������ �̸�
		 int bYear -> ������ ���� ����
		 int bPage -> ������ ������ ��

��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
Book::Book(const char* bName, const char* bAuthor, int bYear, int bPage)
{
	int nLen = strlen(bName) + 1;
	int aLen = strlen(bAuthor) + 1;
	
	bookName = new char[nLen];
	strcpy(bookName, bName);
		
	bookAuthor = new char[aLen];
	strcpy(bookAuthor, bAuthor);
		
	bookPage = bPage;
	bookYear = bYear;
	bookState = true; 

}



/*
�Լ� �̸�: getBookName
���: ������� bookName�� ���� ��ȯ�Ѵ�.
�Ű�����: ����
��ȯ��: ������ ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
char* Book::getBookName() const
{
	return bookName;
}



/*
�Լ� �̸�: getBookAuthor
���: ������� bookAuthor�� ���� ��ȯ�Ѵ�.
�Ű�����: ����
��ȯ��: ������ ���� �̸�

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
char* Book::getBookAuthor() const
{
	return bookAuthor;
}



/*
�Լ� �̸�: getBookYear
���: ������� bookYear�� ���� ��ȯ�Ѵ�.
�Ű�����: ����
��ȯ��: ������ ���� ���� ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
int Book::getBookYear() const
{
	return bookYear;
}



/*
�Լ� �̸�: getBookPage
���: ������� bookPage�� ���� ��ȯ�Ѵ�.
�Ű�����: ����
��ȯ��: ������ ������ �� ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
int Book::getBookPage() const
{
	return bookPage;
}



/*
�Լ� �̸�: getBookState
���: ������� bookState�� ���� ��ȯ�Ѵ�.
�Ű�����: ����
��ȯ��: ������ å �뿩 ���� �� -> true: ���� å�� �뿩 ������
                              false: ���� å �뿩�� �Ұ�����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
bool Book::getBookState()
{
	return bookState;
}


/*
�Լ� �̸�: changeBookState
���: ������� bookState�� ���� �����Ѵ�.
      å �뿩 ���� ���� true�̸� false�� ��ȯ�ϵ���, 
	  å �뿩 ���� ���� false�̸� true�� ��ȯ�ϵ��� �ϴ� ����� �����Ѵ�.
     
�Ű�����: ����
��ȯ��: ����� ������ å �뿩 ���� �� 

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
bool Book::changeBookState()
{
	if (bookState == true)
	{
		bookState = false;
		return bookState;
	}
		
	else
	{
		bookState = true;
		return bookState;
	}

}


/*
�Լ� �̸� ~Book
���: Book Ŭ������ �Ҹ��ڷμ��� ����� �����Ѵ�. �����ڿ��� �����Ҵ��� �޸𸮸� �Ҹ�����ش�.
�Ű�����: ����
��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
Book::~Book()
{
	delete[] bookAuthor; 
	delete[] bookName;
}
