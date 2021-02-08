/*
此段代码的目的是使小球从上落下
*/
#include <stdio.h>
#include <stdlib.h>

void showball(int x, int y);

int main()
{
	int i, j;
	int x = 1;
	int y = 10;
	for (x = 1; x < 10; x++)
		showball(x, y);
}

void showball(int x, int y)
{
	int i;
	system("cls"); //清屏函数
	for (i = 0; i < x; i++)
		printf("\n"); // 输出小球上面的空行
	for (i = 0; i < y; i++)
		printf(" "); // 输出小球左边的空格
	printf("o");	 // 输出小球o
	printf("\n");
}