#pragma once
#ifndef POST_H
#define POST_H

// token types for non one-char tokens
#define ID 257	//�ǿ�����(���� �̸�)
#define NUM 258	//�ǿ�����(����)
#define EQ 259	//==������
#define NE 260	//!=������
#define GE 261	//>=������
#define LE 262	//<=������
#define AND 263	//&&������
#define OR 264	//||������
#define UMINUS 265 //-u������
#define MAXLEN 80 //���ڿ��� �ִ� ����

struct Expression //���� ����ü
{
	Expression(char* s) : str(s), pos(0)	//������ ������, line������ �޾ƿͼ� line�������� �ʱ�ȭ
	{
		for (len = 0; str[len] != '\0'; len++); //line�� ��ĵ�ϸ鼭 ���ڿ��� ����ִ� ������ ������ count(�ι��ڴ� count���� ����)
	}

	char* str; //���� ���ڿ�
	int pos; //���� ���� �迭�� ������ �ε���
	int len; //���� ����
};
 
 
struct Token	//��ū ����ü
{
	bool operator==(char);	//��ū�� #���� �ƴ��� ���� -> token�� ���̰� 1�̰� #�̸� true��ȯ
	bool operator!=(char);	//��ū�� #�� �ٸ��� Ȯ�� -> token�� ���̰� 1�� �ƴϰ�, token�� ù��° ���ڰ� #�� �ƴϸ� true��ȯ
	
	Token(); //����Ʈ ��ū ������
	Token(char);// 1-char token: type equals the token itself -���� �ϳ�¥�� �������� �� ����ؼ� ��ū ����

	Token(char, char, int); // 2-char token(e.g. <=) & its type(e.g. LE) - ���� �ΰ�¥�� �������� �� ����ؼ� ��ū ����

	Token(char*, int, int);//operand with its length & type(defaulted to ID) - �ǿ�����(�����ų� ����)�� �� ����ؼ� ��ū ����
	
	bool IsOperand(); // true if the token type is ID(����) or NUM(����)

	int type; // ascii code for 1-char op; predefined for other tokens
	char* str; // token value
	int len; // length of str
	int ival; // used to store an integer for type NUM; init to 0 for ID
};


using namespace std;

ostream& operator<<(ostream& os, Token t); //��ū ����� ���� <<������ �����ε� �Լ�

Token NextToken(Expression&, bool); //������ ���ڷ� �޾ƿͼ� ��ū�� �ϳ��� �������� ���� // 2nd arg�� bool type���ڴ� infix ������ ��� true��

#endif