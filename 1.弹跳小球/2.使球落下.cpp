/*
�˶δ����Ŀ����ʹС���������
*/
#include <stdio.h>
#include <stdlib.h>

void showball(int x, int y);

int main()
{
	int i, j;
	int x = 1;
	int y = 10;
	for (x = 1; x < 10; x++)
		showball(x, y);
}

void showball(int x, int y)
{
	int i;
	system("cls"); //��������
	for (i = 0; i < x; i++)
		printf("\n"); // ���С������Ŀ���
	for (i = 0; i < y; i++)
		printf(" "); // ���С����ߵĿո�
	printf("o");	 // ���С��o
	printf("\n");
}