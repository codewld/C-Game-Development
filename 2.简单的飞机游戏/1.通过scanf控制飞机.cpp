#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j;
	int x = 5; 
	int y = 10;
	char input;

	while (1)
	{
		system("cls");   // ��������
		// ���С������Ŀ���
		for(i=0;i<x;i++)
			printf("\n");
		// ���С����ߵĿո�
		for (j=0;j<y;j++)
			printf(" ");
		printf("*");  // ���С��o
		printf("\n"); 

		scanf("%c",&input);  // �����û��Ĳ�ͬ�������ƶ�
		if (input == 'a')
			y--;
		if (input == 'd')
			y++;
		if (input == 'w')
			x--;
		if (input == 's')
			x++;
	}	
}