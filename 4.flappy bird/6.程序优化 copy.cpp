#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


// 全局变量
int high, width; // 游戏画面大小
int bird_x, bird_y; // 小鸟的坐标
int bar1_x, bar1_yDown, bar1_yTop; // 障碍物的坐标
int score; // 得分
int alive;

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x,int y){  //类似于清屏函数

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup(){  // 数据初始化
	high = 20;  width = 30;
	bird_x = 5;  bird_y = high/2;
	bar1_x = width;  bar1_yDown = high/3;  bar1_yTop = high/2;
	score = 0;
	alive = 1;
}
void show(){  // 显示画面
	gotoxy(0,0);  // 清屏	
	int i, j;
	for (i = 0; i < high; i++){
		for (j = 0; j < width; j++){
			if ((i==bird_y) && (j==bird_x))  printf("@");  // 输出小鸟
			else if ((j==bar1_x) && ((i<bar1_yDown)||(i>bar1_yTop)))  printf("*");  // 输出墙壁
			else  printf(" ");  // 输出空格
		}
		printf("\n");
	}
	printf("得分：%d\n",score);
}	
void updateWithoutInput(){  // 与用户输入无关的更新
	bar1_x --;  bird_y ++;
	if (bird_x==bar1_x){
		if ((bird_y >= bar1_yDown)&&(bird_y <= bar1_yTop))  score++;
		else  alive = 0;
	}
	if (bar1_x <= 0){  // 再新生成一个障碍物
		bar1_x = width;
		int temp = rand()%int(high*0.8);
		bar1_yDown = temp - high/10;
		bar1_yTop = temp + high/10;
	}
	Sleep(150);
}

void updateWithInput(){  // 与用户输入有关的更新
	char input;
	if(kbhit()){  // 判断是否有输入
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if (input == ' ')  bird_y = bird_y - 2;
	}
}

int main(){
	HideCursor();
	startup();  // 数据初始化	
	while (alive){  //  游戏循环执行
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();     // 与用户输入有关的更新
	}
}