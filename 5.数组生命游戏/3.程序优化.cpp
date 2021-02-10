#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define High 25  // 游戏画面尺寸
#define Width 50


// 全局变量
int cells[High][Width]; // 所有位置细胞生1或死0
int waittime;  // 控制游戏速度
int livablezone;  // 宜居带尺寸

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x,int y){  // 类似于清屏函数
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup(){  // 数据初始化
	int i, j;
	for (i = 0; i < High; i++) // 初始化
		for (j = 0; j < Width; j++)  cells[i][j] = 1;
    waittime = 50;
    livablezone =10;
}
void show(){  // 显示画面
	gotoxy(0,0);  // 清屏
	int i,j;
	for (i=1;i<=High-1;i++){
		for (j=1;j<=Width-1;j++){
			if (cells[i][j]==1)  printf("*");  //   输出活的细胞
			else  printf(" ");  //   输出空格			
		}
		printf("\n");
	}
    printf("\n输入W使速度加快，输入S使速度减缓\n输入A使宜居带左移，输入D使宜居带右移\n输入I暂停/继续游戏");
	Sleep(waittime);
}	
int Nei(int i, int j){
    int num = cells[i-1][j-1] + cells[i-1][j] + cells[i-1][j+1] + cells[i][j-1]
				+ cells[i][j+1] + cells[i+1][j-1] + cells[i+1][j] + cells[i+1][j+1];
    return num;
}
void updateWithoutInput(){  // 与用户输入无关的更新
	int NewCells[High][Width]; // 下一帧的细胞情况
	int NeibourNumber; //统计邻居的个数
	int i,j;
	for (i=1;i<=High-1;i++){
		for (j=livablezone;j<=Width-1;j++){
			NeibourNumber = Nei(i, j);
			if (NeibourNumber==3)  NewCells[i][j] = 1;  // 活
			else if (NeibourNumber==2)  NewCells[i][j] = cells[i][j];  // 不变
			else  NewCells[i][j] = 0;   //死
		}
	}
	for (i=1;i<=High-1;i++)   // 将数组数据腾过去
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
void updateWithInput(){  // 与用户输入有关的更新
	char input;
	if(kbhit()){  // 判断是否有输入
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
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
    HideCursor();  // 隐藏光标
	startup();  // 数据初始化	
	while (1){ //  游戏循环执行
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
}