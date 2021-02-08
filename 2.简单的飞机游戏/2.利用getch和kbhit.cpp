/*
getch()读取一个字符，且不需要返回值
kbhit()在用户输入时1，否则返回0；
利用 if (kbhit()),可以在无输入时使if语句“消失”，从而避免出现整个游戏画面都停下来等待输入的情况
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
		system("cls");   // 清屏函数
		// 输出小球上面的空行
		for(i=0;i<x;i++)
			printf("\n");
		// 输出小球左边的空格
		for (j=0;j<y;j++)
			printf(" ");
		printf("*");  // 输出小球o
		printf("\n"); 
		
		if(kbhit())  // 判断是否有输入
		{
			input = getch();  // 根据用户的不同输入来移动，不必输入回车
			if (input == 'a')   
				y--;  // 位置左移
			if (input == 'd')
				y++;  // 位置右移
			if (input == 'w')
				x--;  // 位置上移
			if (input == 's')
				x++;  // 位置下移
		}
	}	
}
