/*
�˶δ����Ŀ����ʹС���������ҵ���
*/
#include <stdio.h>
#include <stdlib.h>

void showball(int x,int y);

int main()
{
	int i,j;
	int x = 0,y = 5; //��ʼλ��
	int changex = 1; //С��ÿ��һ֡����x�ϱ仯����
	int changey = 1; //С��ÿ��һ֡����y�ϱ仯����
	int left = 0;    //�߽�
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
    system("cls");   //��������
	for(i=0;i<x;i++) printf("\n"); // ���С������Ŀ���
	for(i=0;i<y;i++) printf(" "); // ���С����ߵĿո�
	printf("o");  // ���С��o
    printf("\n");
}