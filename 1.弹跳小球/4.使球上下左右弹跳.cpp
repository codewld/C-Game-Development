/*
此段代码的目的是使小球上下左右弹跳
*/
#include <stdio.h>
#include <stdlib.h>

void showball(int x,int y);

int main()
{
	int i,j;
	int x = 0,y = 5; //初始位置
	int changex = 1; //小球每过一帧，在x上变化的量
	int changey = 1; //小球每过一帧，在y上变化的量
	int left = 0;    //边界
	int right = 20;
	int top = 0;
	int bottom = 10;
	while (1)
	{
		x = x+changex;
		y = y+changey;
		showball(x,y);
		if((x==top)||(x==bottom)) changex = -changex;
		if((y==left)||(y==right)) changey = -changey;		
	}	
}

void showball(int x,int y){
    int i;
    system("cls");   //清屏函数
	for(i=0;i<x;i++) printf("\n"); // 输出小球上面的空行
	for(i=0;i<y;i++) printf(" "); // 输出小球左边的空格
	printf("o");  // 输出小球o
    printf("\n");
}