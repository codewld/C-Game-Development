/*
此段代码的目的是使小球弹跳
*/
#include <stdio.h>
#include <stdlib.h>

void showball(int x,int y);

int main()
{
	int i,j;
	int x = 5;
	int y = 10;
	int top=0;
	int bottom = 20;
	int change = 1;   //小球每过一帧所变化的量
	while (1)
	{
		x=x+change;
		showball(x,y);
		if(x==bottom||x==top) change=-change; //当小球触底/触顶，方向改变
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