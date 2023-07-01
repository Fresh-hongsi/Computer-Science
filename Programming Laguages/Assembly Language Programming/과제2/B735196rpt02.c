#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[5] = { NULL, };
	int i = 0;
	int a = 4;
	scanf("%s", str);

	while(i<4)
	{
		printf("%dth ¹®ÀÚ: %c\n", a, str[3-i]);
		i++;
		a--;
	}
	return 0;
}