#include <stdio.h>
#include <conio.h>
#include <windows.h>

void HideCursor();

int main()
{
	int i,j;
	int x = 5, y = 10;  // ��ʼλ��
	char input;
	int isFire = 0;
    int gun_site = y + 2;
	int ny = 5; // һ�����ӣ����ڵ�һ�У�ny����
	int isKilled = 0;
	HideCursor();
	while (!isKilled)
	{
		system("cls");   // ��������

		for (j=0;j<ny;j++)  printf(" ");  // ��ӡ����
		printf("*\n");

		if (isFire==0) // ��δ�����������
		{
			for(i=0;i<x;i++)  printf("\n");
		}
		else   // �����������������
		{
			for(i=0;i<x;i++)
			{
				for (j=0;j<y;j++)  printf(" ");
				printf("  |\n");
			}
			if (gun_site == ny)  isKilled = 1; // ���а���
			isFire = 0;
		}
		
		for (j=0;j<y;j++)  printf(" ");  // �������һ�����ӵķɻ�ͼ��
		printf("  *\n");
		for (j=0;j<y;j++)  printf(" ");
		printf("*****\n");
		for (j=0;j<y;j++)  printf(" ");
		printf(" * * \n");

		if(kbhit())  // �ж��Ƿ�������
		{
			input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
			if (input == 'a'||input == 75)  y--;
			if (input == 'd'||input == 77)  y++;
			if (input == 'w'||input == 72)  x--;
			if (input == 's'||input == 80)  x++;
			if (input == ' ')  isFire = 1;
		}
        gun_site = y + 2;
	}
    printf("\n�о��ɻ��ѱ����䣡\n");	
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}