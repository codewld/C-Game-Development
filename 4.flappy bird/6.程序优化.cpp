#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


int high, width; // ��Ϸ�����С
int bird_x, bird_y; // С�������
int bar1_x, bar1_yTop, bar1_gap; // �ϰ��������
int score; // �÷�
int alive; // �Ƿ���

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
	bar1_x = width;  bar1_yTop = high/2;  bar1_gap = 5;
	score = 0;
	alive = 1;
}
void show(){  // ��ʾ����
	gotoxy(0,0);  // ����	
	int i, j;
	for (i = 0; i < high; i++){
		for (j = 0; j < width; j++){
			if ((i == bird_y) && (j == bird_x))  printf("@");  // ���С��
			else if (j == bar1_x){
				if (i <= bar1_yTop && bar1_yTop - i <= bar1_gap) printf(" ");
				else printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	printf("�÷֣�%d\n",score);
}
void updateWithoutInput(){  // ���û������޹صĸ���
	static int speed = 0;
	if(speed < 10) speed++;
	else{
		bar1_x --;  bird_y ++;
		speed = 0;
		if (bird_x == bar1_x){
			if ((bar1_yTop - bird_y <= bar1_gap)&&(bird_y <= bar1_yTop))  score++;
			else  alive = 0;  // С��ײǽ
	    }
	    if (bar1_x <= 0){  // ��������һ���ϰ���
		    bar1_x = width;
		    bar1_yTop = rand()%(int)(high*3/4);
			bar1_gap = rand()%(int)(high*1/4) + 2;
		}
	}

	
}
void updateWithInput(){  // ���û������йصĸ���
	char input;
	if(kbhit()){  // �ж��Ƿ�������
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == ' ')  bird_y = bird_y - 1;
	}
}
int main(){
	HideCursor();
	startup();  // ���ݳ�ʼ��	
	while (alive && score < 10){  //  ��Ϸѭ��ִ��
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();     // ���û������йصĸ���
	}
	if (alive) printf("You win!");
	else printf("You lose.");
}