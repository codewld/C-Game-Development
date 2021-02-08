#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// 全局变量
int high,width; // 游戏画面大小
int bird_x,bird_y; // 小鸟的坐标
int bar1_y,bar1_xDown,bar1_xTop; // 障碍物的相关坐标

void gotoxy(int x,int y)//类似于清屏函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void startup()  // 数据初始化
{
	high = 20;
	width = 50;
	bird_x = high/2;
	bird_y = 1;
	bar1_y = width/2;
	bar1_xDown = high/3;
	bar1_xTop = high/2;
}

void show()  // 显示画面
{
	gotoxy(0,0);  // 清屏	
	int i,j;
	
	for (i=0;i<high;i++)
	{
		for (j=0;j<width;j++)
		{
			if ((i==bird_x) && (j==bird_y))
				printf("@");  //   输出小鸟
			else if ((j==bar1_y) && ((i<bar1_xDown)||(i>bar1_xTop)) )
				printf("*");  //   输出墙壁
			else
				printf(" ");  //   输出空格
		}
		printf("\n");
	}

}	

void updateWithoutInput()  // 与用户输入无关的更新
{
	bird_x ++;
	bar1_y --;
	Sleep(150);
}

void updateWithInput()  // 与用户输入有关的更新
{	
	char input;
	if(kbhit())  // 判断是否有输入
	{
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if (input == ' ')  
		{
			bird_x = bird_x - 2;
		}

	}
}

int main()
{
	startup();  // 数据初始化	
	while (1)  //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();     // 与用户输入有关的更新
	}
}