/*
�˶δ����Ŀ����ʹС����
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
	int change = 1;   //С��ÿ��һ֡���仯����
	while (1)
	{
		x=x+change;
		showball(x,y);
		if(x==bottom||x==top) change=-change; //��С�򴥵�/����������ı�
	}
}

void showball(int x,int y){
    int i;
    system("cls");   //��������
	for(i=0;i<x;i++) printf("\n"); // ���С������Ŀ���
	for(i=0;i<y;i++) printf(" "); // ���С����ߵĿո�
	printf("o");  // ���С��o
    printf("\n");
}