#include <stdio.h>
#include <conio.h>
#include <windows.h>

void HideCursor();

int main()
{
	int i,j;
	int x = 5, y = 10;  // 初始位置
	char input;
	int isFire = 0;
    int gun_site = y + 2;
	int ny = 5; // 一个靶子，放在第一行，ny列上
	int isKilled = 0;
	HideCursor();
	while (!isKilled)
	{
		system("cls");   // 清屏函数

		for (j=0;j<ny;j++)  printf(" ");  // 打印靶子
		printf("*\n");

		if (isFire==0) // 若未开火，输出空行
		{
			for(i=0;i<x;i++)  printf("\n");
		}
		else   // 若开火，输出激光竖线
		{
			for(i=0;i<x;i++)
			{
				for (j=0;j<y;j++)  printf(" ");
				printf("  |\n");
			}
			if (gun_site == ny)  isKilled = 1; // 击中靶子
			isFire = 0;
		}
		
		for (j=0;j<y;j++)  printf(" ");  // 下面输出一个复杂的飞机图案
		printf("  *\n");
		for (j=0;j<y;j++)  printf(" ");
		printf("*****\n");
		for (j=0;j<y;j++)  printf(" ");
		printf(" * * \n");

		if(kbhit())  // 判断是否有输入
		{
			input = getch();  // 根据用户的不同输入来移动，不必输入回车
			if (input == 'a'||input == 75)  y--;
			if (input == 'd'||input == 77)  y++;
			if (input == 'w'||input == 72)  x--;
			if (input == 's'||input == 80)  x++;
			if (input == ' ')  isFire = 1;
		}
        gun_site = y + 2;
	}
    printf("\n敌军飞机已被击落！\n");	
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}