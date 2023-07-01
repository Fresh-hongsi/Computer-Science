//B735196 �ڽ�ȫ
#include <iostream>
#include "post.h"

using namespace std;

void Postfix(Expression);
int main()
{
	char line[MAXLEN]; //����(�ִ� �Է¹��� �� �ִ� ���� 80��)
	
	while (cin.getline(line, MAXLEN)) //Ű���忡 �Է¹��� ���� line�� ������
	{
		Expression e(line); //���� e����(lne ���۸� �̿��Ͽ� Expression�� ����) -> ���⼭ e�� ����ǥ���
		
		try 
		{
			Postfix(e); //����ǥ������� ��ȯ
		}

		catch (char const* msg) //����ó�� ��Ŀ����
		{
			cerr << "Exception: " << msg << endl; //���� �߻� ���
		}
	}
}