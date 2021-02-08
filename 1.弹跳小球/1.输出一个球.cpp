/*
此段代码的目的是在坐标（x,y）处输出一个 o ，用于代表小球
*/
#include <stdio.h>

int main()
{
	int i,j;
	int x = 5;
	int y = 10;	
	for(i=0;i<x;i++) printf("\n"); // 输出小球上面的空行
	for(j=0;j<y;j++) printf(" "); // 输出小球左边的空格
	printf("o");  // 输出小球o
	printf("\n");
    return 0;
}