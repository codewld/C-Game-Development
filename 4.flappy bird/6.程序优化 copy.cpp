#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


// ȫ�ֱ���
int high, width; // ��Ϸ�����С
int bird_x, bird_y; // С�������
int bar1_x, bar1_yDown, bar1_yTop; // �ϰ��������
int score; // �÷�
int alive;

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x,int y){  //��������������

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup(){  // ���ݳ�ʼ��
	high = 20;  width = 30;
	bird_x = 5;  bird_y = high/2;
	bar1_x = width;  bar1_yDown = high/3;  bar1_yTop = high/2;
	score = 0;
	alive = 1;
}
void show(){  // ��ʾ����
	gotoxy(0,0);  // ����	
	int i, j;
	for (i = 0; i < high; i++){
		for (j = 0; j < width; j++){
			if ((i==bird_y) && (j==bird_x))  printf("@");  // ���С��
			else if ((j==bar1_x) && ((i<bar1_yDown)||(i>bar1_yTop)))  printf("*");  // ���ǽ��
			else  printf(" ");  // ����ո�
		}
		printf("\n");
	}
	printf("�÷֣�%d\n",score);
}	
void updateWithoutInput(){  // ���û������޹صĸ���
	bar1_x --;  bird_y ++;
	if (bird_x==bar1_x){
		if ((bird_y >= bar1_yDown)&&(bird_y <= bar1_yTop))  score++;
		else  alive = 0;
	}
	if (bar1_x <= 0){  // ��������һ���ϰ���
		bar1_x = width;
		int temp = rand()%int(high*0.8);
		bar1_yDown = temp - high/10;
		bar1_yTop = temp + high/10;
	}
	Sleep(150);
}

void updateWithInput(){  // ���û������йصĸ���
	char input;
	if(kbhit()){  // �ж��Ƿ�������
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == ' ')  bird_y = bird_y - 2;
	}
}

int main(){
	HideCursor();
	startup();  // ���ݳ�ʼ��	
	while (alive){  //  ��Ϸѭ��ִ��
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();     // ���û������йصĸ���
	}
}