/*
����һ��Ļ����ϣ����������Ż���
1.���߽�����Ļغ궨�峣��
2.��sleep()ʹС��ĵ�����������(ͨ���궨�峣��sleep_time����)
3.������С��ײǽʱʹϵͳ��������(ͨ���궨�峣��is_ring����)
4.����һ���������ʾС��ײǽ����
5.��С��ײǽһ������ʱ�����Զ�ֹͣ����(ͨ���궨�峣��time_limit����)
6.�����˹��
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define left 0
#define right 20
#define top 0
#define bottom 10
#define is_ring 0	  //1Ϊ���� 0Ϊ������
#define time_limit 10 //��time_limit��ײǽ�󣬳���ֹͣ
#define sleep_time 10 //���ڿ���С��������ٶȣ�����Խ���ٶ�Խ��

void ring();
void HideCursor();
void showball(int x, int y, int time);

int main()
{
	int i, j;
	int x = 0, y = 5;			  //��ʼλ��
	int changex = 1, changey = 1; //С��ÿ��һ֡����x,y�ϱ仯����
	int time = 0;				  //���ڼ��㴥���߽�Ĵ���
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
	printf("\n��ײ��%d�Σ��������\n", time_limit);
}

void showball(int x, int y, int time)
{
	int i;
	Sleep(sleep_time);
	system("cls"); //��������
	printf("�Ѿ���ײ��%d��\n", time);
	for (i = 0; i < x; i++)
		printf("\n"); // ���С������Ŀ���
	for (i = 0; i < y; i++)
		printf(" "); // ���С����ߵĿո�
	printf("o");	 // ���С��o
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
