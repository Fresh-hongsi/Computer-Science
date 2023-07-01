#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Library.h"

using namespace std;

/*
�Լ� �̸�: Library
���: Library Ŭ������ �����ڷμ��� ����� �����Ѵ�. 
     ��ü ���� �ÿ� �������� �̸�, ���� ��ü �迭, ���� �߰� ������ �ε��� ���� �ʱ�ȭ�Ѵ�.
�Ű�����: char* lName -> ������ �̸�
��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
Library::Library(const char* lName) :bookNum(0)
{

	int lLen = strlen(lName + 1);
	strcpy(libraryName, lName);

	for (int i = 0; i < 10; i++)
	{
		bArr[i] = NULL;
	}
}
	

/*
�Լ� �̸�: bookRegister (���� ��� �Լ�)
���: ������ ����, ���� �̸�, ���� ����, �������� ������ �޾� Book ��ü�� �������� �Ҵ��Ͽ� �ʱ�ȭ�� ��, Book ��ü ������ �迭�� ���������� Book��ü�� �ּҰ��� �����Ѵ�.
     ���� Book ��ü�� �迭�� ����� ������ ���� �߰� ������ �ε��� ���� 1�� ������Ų��.

�Ű�����: const char* title -> ������ ����
		 const char* name -> ������ �̸�
		 int year -> ������ ���� ����
		 int page -> ������ ������ ��
��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
void Library::bookRegister(const char* title, const char* name, int year, int page) 
{
	bArr[bookNum] = new Book(title, name, year, page);
	bookNum++; //������ �ѱ� ��ϵǾ����Ƿ� ���� �߰� ������ �ε��� ��ȣ�� �̸� 1 �������ѳ��´�.
}


/*
�Լ� �̸�: bookRental_Possible (�뿩 ������ ���� ��� ��� �Լ�)
���: Book ��ü ������ �迭�� ����� Book ��ü���� �뿩 ������ ���¶��, ���� ����, ���� �̸�, ���� ����, ������ �� �������� get�Լ��� ��ȯ������ ����Ѵ�.
     
�Ű�����: ����
��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
void Library::bookRental_Possible() 
{

	for (int i = 0; i < bookNum; i++)
	{

		if (bArr[i]->getBookState() == true) //�ش� ������ �뿩 ������ �������� Ȯ���Ѵ�. �뿩 ����(true)�ϸ� �ش� ������ ������ ����Ѵ�. 
		{
			cout << ' ' << i + 1 << ')';
			cout << bArr[i]->getBookName() << ", ";
			cout << bArr[i]->getBookAuthor() << ", ";
			cout << bArr[i]->getBookYear() << ", ";
			cout << bArr[i]->getBookPage();
			cout << endl;


		}

	}
}



/*
�Լ� �̸�: bookRental (���� �뿩 �Լ�)
���: 

     1. ����ڿ��� �뿩 ��û�� ������ ��ȣ�� �Է¹޾� ���� �뿩�� �����Ѵ�. ���� �뿩 ��û�� ������ ������ ����Ѵ�.
     2. �뿩 �Ϸ�� ������ ���� �뿩 ���� ���� (true ���� false��) �������ش�.
	 3. ���� ������ ��ü �迭���� ������ �뿩 ���ο� ���� ������ ���ش�.
		- ���� �ε��� ��(bookNum)�� �������� �ε��� ���� ���� �뿩 ������ ����, �ε������ʹ� �뿩 �Ϸ�� ������ �迭�� �ڸ��ϵ��� Book�� �����ͷ� Swap�����
		  ��������ν� �����Ͽ���. 

�Ű�����: ����
��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
void Library::bookRental(void) 
{
	int n;

	cout << "* �뿩�� ���� ��ȣ�� �Է��Ͻÿ�: ";
	cin >> n;

	if (bArr[n-1]->getBookState() == false)
	{
		cout << "�߸��� ��ȣ �Է�! " << endl << endl;
		return;
	}

	cout << "- ";
	cout << bArr[n - 1]->getBookName();
	cout << ", ";
	cout << bArr[n - 1]->getBookAuthor();
	cout << ", ";
	cout << bArr[n - 1]->getBookYear();
	cout << ", ";
	cout << bArr[n - 1]->getBookPage();
	cout << endl;

	bArr[n - 1]->changeBookState(); //å�� �뿩 �Ϸ�Ǿ����Ƿ� å�� �뿩(����) ���� ���� false�� �ȴ�.

	for (int i = n - 1; i < bookNum - 1; i++) //Swap�� ����Ͽ� �뿩 ���� ������ �뿩 �Ұ����� ������ �ε��� ���� �������� ������ �����Ѵ�.
	{
		Book* temp = bArr[i]; 
		bArr[i] = bArr[i + 1]; 
		bArr[i + 1] = temp;
	}
	bookNum--; //������ �뿩�Ǿ����Ƿ� ���� �ε��� ���� 1��ŭ �پ���.

}


/*
�Լ� �̸�: bookRental_Statistics (�뿩�� ���� ��� ��� �Լ�)
���:

	 1. ��ü �������� �뿩�� ������ ���� �뿩�� ������ ������ �� ���� ����Ѵ�.
	  - �뿩�� ������ �뿩���� ���� ������ getBookState �Լ��κ��� ��ȯ���� �뿩���� ���� �������� �����Ѵ�. 
	  - ���� �뿩 ���ΰ� false�̸�, �뿩�� ������ ���� �뿩�� ������ ���� �� ����� �����Ѵ�.

�Ű�����: ����
��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
void Library:: bookRental_Statistics(void)
{
	int rented_book = 0; //������� �뿩�� ������ ��
	int rented_pageSum = 0; //������� �뿩�� ������ ������ �� ��

	for (int i = 0; i < 3; i++)
	{
		if (bArr[i]->getBookState() == false)
		{
			rented_book++;
			rented_pageSum += bArr[i]->getBookPage();
		}

	}
	cout << " - ���� �뿩 �� : " << rented_book << endl;
	cout << " - �뿩 ���� ������ �� �� : " << rented_pageSum;
	

}


/*
�Լ� �̸� ~Library
���: Library Ŭ������ �Ҹ��ڷμ��� ����� �����Ѵ�. �����ڿ��� �����Ҵ��� �޸𸮸� �Ҹ�����ش�.
�Ű�����: ����
��ȯ��: ����

�ۼ���¥: 2021/04/11
�ۼ���: �ڽ�ȫ
*/
Library::~Library()
{
	for (int i = 0; i < 3; i++)
	{
		delete bArr[i];
	}
	
}



