//B735196 �ڽ�ȫ

#include <iostream>
#include "post.h"

using namespace std;

void Eval(Expression); 

int main(void)
{
	char line[MAXLEN]; //����(�ִ� �Է¹��� �� �ִ� ���� 80��)

	while (cin.getline(line, MAXLEN)) //Ű���忡 �Է¹��� ���� line�� ������
	{
		Expression e(line); // Assume postfix notation // ���� e����(lne ���۸� �̿��Ͽ� Expression�� ����) -> ���⼭ e�� ����ǥ���

		try
		{
			Eval(e); //���� ���
		}

		catch (char const* msg) //���� �߻� ���
		{
			cerr << "Exception: " << msg << endl;
		}
	}
}