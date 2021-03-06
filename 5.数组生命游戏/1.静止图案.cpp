#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define High 25  // 游戏画面尺寸
#define Width 50


// 全局变量
int cells[High][Width]; // 所有位置细胞生1或死0


void gotoxy(int x,int y)//类似于清屏函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void startup() // 数据初始化
{
	int i,j;
	for (i=0;i<High;i++) // 随机初始化
		for (j=0;j<Width;j++)
		{
			cells[i][j] = rand()%2;
		}
}

void show()  // 显示画面
{
	gotoxy(0,0);  // 清屏
	int i,j;
	for (i=0;i<=High;i++)
	{
		for (j=0;j<=Width;j++)
		{
			if (cells[i][j]==1)
				printf("*");  //   输出活的细胞
			else
				printf(" ");  //   输出空格			
		}
		printf("\n");
	}
	Sleep(50);
}	

void updateWithoutInput()  // 与用户输入无关的更新
{	

}

void updateWithInput()  // 与用户输入有关的更新
{

}

int main()
{
	startup();  // 数据初始化	
	while (1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
}