/*
getch()��ȡһ���ַ����Ҳ���Ҫ����ֵ
kbhit()���û�����ʱ1�����򷵻�0��
���� if (kbhit()),������������ʱʹif��䡰��ʧ�����Ӷ��������������Ϸ���涼ͣ�����ȴ���������
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
		
		if(kbhit())  // �ж��Ƿ�������
		{
			input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
			if (input == 'a')   
				y--;  // λ������
			if (input == 'd')
				y++;  // λ������
			if (input == 'w')
				x--;  // λ������
			if (input == 's')
				x++;  // λ������
		}
	}	
}
