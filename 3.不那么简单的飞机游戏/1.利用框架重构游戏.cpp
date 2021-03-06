#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int position_x,position_y; // 飞机位置
int high,width; //  游戏画面尺寸

void startup(){  // 数据初始化
    high = 20;
	width = 30;
	position_x = high/2;
	position_y = width/2;
}
void show(){  //显示画面
    system("cls");   // 清屏
	int i,j;
	for (i = 0; i < high; i++){
		for (j = 0; j < width; j++){
			if ((i == position_x) && (j == position_y))
				printf("*");  //   输出飞机*
			else
				printf(" ");  //   输出空格
		}
		printf("\n");
	}

}
void updateWithoutInput(){

}
void updateWithInput(){
    char input;
	if (kbhit()){  // 判断是否有输入
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if (input == 'a')  position_y--;  // 位置左移
		if (input == 'd')  position_y++;  // 位置右移
		if (input == 'w')  position_x--;  // 位置上移
		if (input == 's')  position_x++;  // 位置下移
	}
}

int main(){
   startup();    // 数据初始化
   while(1){  //  游戏循环执行
        show();   // 显示画面
        updateWithoutInput();  // 与用户输入无关的更新
        updateWithInput();    // 与用户输入有关的更新
    }
}