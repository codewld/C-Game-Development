/*

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

		// 下面输出一个复杂的飞机图案
		for (j=0;j<y;j++)
			printf(" ");		
		printf("  *\n");
		for (j=0;j<y;j++)
			printf(" ");
		printf("*****\n");
		for (j=0;j<y;j++)
			printf(" ");
		printf(" * * \n");
 
		
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
