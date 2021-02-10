#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define High 25  // ��Ϸ����ߴ�
#define Width 50


// ȫ�ֱ���
int cells[High][Width]; // ����λ��ϸ����1����0
int waittime;  // ������Ϸ�ٶ�
int livablezone;  // �˾Ӵ��ߴ�

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x,int y){  // ��������������
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup(){  // ���ݳ�ʼ��
	int i, j;
	for (i = 0; i < High; i++) // ��ʼ��
		for (j = 0; j < Width; j++)  cells[i][j] = 1;
    waittime = 50;
    livablezone =10;
}
void show(){  // ��ʾ����
	gotoxy(0,0);  // ����
	int i,j;
	for (i=1;i<=High-1;i++){
		for (j=1;j<=Width-1;j++){
			if (cells[i][j]==1)  printf("*");  //   ������ϸ��
			else  printf(" ");  //   ����ո�			
		}
		printf("\n");
	}
    printf("\n����Wʹ�ٶȼӿ죬����Sʹ�ٶȼ���\n����Aʹ�˾Ӵ����ƣ�����Dʹ�˾Ӵ�����\n����I��ͣ/������Ϸ");
	Sleep(waittime);
}	
int Nei(int i, int j){
    int num = cells[i-1][j-1] + cells[i-1][j] + cells[i-1][j+1] + cells[i][j-1]
				+ cells[i][j+1] + cells[i+1][j-1] + cells[i+1][j] + cells[i+1][j+1];
    return num;
}
void updateWithoutInput(){  // ���û������޹صĸ���
	int NewCells[High][Width]; // ��һ֡��ϸ�����
	int NeibourNumber; //ͳ���ھӵĸ���
	int i,j;
	for (i=1;i<=High-1;i++){
		for (j=livablezone;j<=Width-1;j++){
			NeibourNumber = Nei(i, j);
			if (NeibourNumber==3)  NewCells[i][j] = 1;  // ��
			else if (NeibourNumber==2)  NewCells[i][j] = cells[i][j];  // ����
			else  NewCells[i][j] = 0;   //��
		}
	}
	for (i=1;i<=High-1;i++)   // �����������ڹ�ȥ
		for (j=livablezone;j<=Width-1;j++)  cells[i][j] = NewCells[i][j];
    for (i=1;i<=High-1;i++)
        for (j=1;j<=livablezone;j++){
            if (cells[i][j] == 0){
                int num = rand()%30;
                if(num == 1) cells[i][j] = 1;
            }
            else{
                int num = rand()%100;
                if(num == 2) cells[i][j] = 0;
            }
        }
}
void updateWithInput(){  // ���û������йصĸ���
	char input;
	if(kbhit()){  // �ж��Ƿ�������
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
        if (input == 'a' || input == 'A' || input == 75)   livablezone--;
		if (input == 'd' || input == 'D' || input == 77)   livablezone++;
		if (input == 'w' || input == 'W' || input == 72)   waittime = 50; 
		if (input == 's' || input == 'S' || input == 80)   waittime = 500;
        if (input == 'I' || input == 'i'){
            while(1){
                int i = getch();
                if(i == 'I' || i == 'i') break;
            }
        }
    }
    
}
int main(){
    HideCursor();  // ���ع��
	startup();  // ���ݳ�ʼ��	
	while (1){ //  ��Ϸѭ��ִ��
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();  // ���û������йصĸ���
	}
}