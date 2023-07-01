#ifndef __BOOK_H__
#define __BOOK_H__

/*
Ŭ���� �̸� : Book
��� : ������ ���� ������ ���� ����� ������

     1. ������ ����, ���� �̸�, ���� ����, ������ �� ������ �޾� ��ü�� �����Ѵ�. ���� ���� �뿩 ���θ� ��Ÿ���� ���� ��ü ������ ���ÿ� �ʱ�ȭ�Ѵ�. 
     2. ������ ������ ��ȯ�Ѵ�.
     3. ������ ���� �̸��� ��ȯ�Ѵ�.
	 4. ������ ���� ������ ��ȯ�Ѵ�.
	 5. ������ ������ �� ������ ��ȯ�Ѵ�.
	 6. ������ �뿩 ���� ���� ��ȯ�Ѵ�.
	 7. ������ �뿩 ���� ���� �����Ѵ�.

�ۼ���¥ : 2021/04/11
�ۼ��� : �ڽ�ȫ
*/


class Book
{
private:
	char* bookName; //å ����
	char* bookAuthor; //å �����̸�
	int bookYear; //å ���ǿ���
	int bookPage; //å ������ ��
	bool bookState; //å �뿩���θ� ��Ÿ���� ��


public:
	Book(const char* bName, const char* bAuthor, int bYear, int bPage);

	char* getBookName() const;
	
	char* getBookAuthor() const;
	
	int getBookYear() const;

	int getBookPage() const;
	
	bool getBookState();

	bool changeBookState();
	
	~Book();
	
};

#endif