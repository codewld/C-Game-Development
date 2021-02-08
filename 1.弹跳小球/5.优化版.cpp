/*
在上一版的基础上，做了如下优化：
1.将边界变量改回宏定义常量
2.用sleep()使小球的弹跳更加流畅(通过宏定义常量sleep_time控制)
3.可以在小球撞墙时使系统发出声响(通过宏定义常量is_ring控制)
4.增加一行输出，显示小球共撞墙几次
5.当小球撞墙一定次数时，将自动停止程序(通过宏定义常量time_limit控制)
6.隐藏了光标
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define left 0
#define right 20
#define top 0
#define bottom 10
#define is_ring 0	  //1为响铃 0为不响铃
#define time_limit 10 //第time_limit次撞墙后，程序将停止
#define sleep_time 10 //用于控制小球的运行速度，数字越大，速度越慢

void ring();
void HideCursor();
void showball(int x, int y, int time);

int main()
{
	int i, j;
	int x = 0, y = 5;			  //初始位置
	int changex = 1, changey = 1; //小球每过一帧，在x,y上变化的量
	int time = 0;				  //用于计算触碰边界的次数
	HideCursor();
	while (time <= 10)
	{
		x = x + changex;
		y = y + changey;
		showball(x, y, time);
		if (x == top || x == bottom)
		{
			changex = -changex;
			time++;
			ring();
		}
		if (y == left || y == right)
		{
			changey = -changey;
			time++;
			ring();
		}
	}
	printf("\n已撞击%d次，程序结束\n", time_limit);
}

void showball(int x, int y, int time)
{
	int i;
	Sleep(sleep_time);
	system("cls"); //清屏函数
	printf("已经碰撞了%d次\n", time);
	for (i = 0; i < x; i++)
		printf("\n"); // 输出小球上面的空行
	for (i = 0; i < y; i++)
		printf(" "); // 输出小球左边的空格
	printf("o");	 // 输出小球o
	printf("\n");
}

void ring()
{
	if (is_ring)
		printf("\a");
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
