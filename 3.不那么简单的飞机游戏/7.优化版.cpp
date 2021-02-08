#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// 全局变量
int position_x, position_y; // 飞机位置
int bullet_x, bullet_y; // 子弹位置
int enemy_x, enemy_y; // 敌机位置
int high, width; //  游戏画面尺寸
int score; // 得分

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x,int y){  //类似于清屏函数，光标移动到原点位置进行重画
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void Loading(){
	int i;
	system("cls");   // 清屏函数
    printf("请拦截敌方导弹\n");
	printf("WASD或上下左右控制移动\n");
	printf("空格键控制开火\n\n");
    for (i = 10; i > 0; i--){
	    printf("%d\n",i);
	    Sleep(100);
	}
	printf("按任意键开始游戏\n");
    i = getch();
}
void startup(){ // 数据初始化
	high = 22;  width = 32;  //画面尺寸
	position_x = high * 3 / 4;  position_y = width / 2;  //飞机位置
	bullet_x = -2;  bullet_y = position_y;  //子弹位置
	enemy_x = 2;  enemy_y = rand() % width;;  //敌机位置
	score = 0;  //得分
}
void show(){  // 显示画面
	gotoxy(0,0);  // 光标移动到原点位置
	int i,j;
	for (i = 0; i <= high; i++){
		for (j = 0; j <= width; j++){
			if ((i == position_x) && (j == position_y))  printf("*");  //   输出飞机*
			else if ((i == enemy_x) && (j == enemy_y))  printf("O");  //   输出敌机O
			else if ((i == bullet_x) && (j == bullet_y))  printf("|");  //   输出子弹|
			else if (i == high) printf("-");   // 输出墙壁
            else if (j == 0 || j == width) printf("|");
            else printf(" ");  //   输出空格
		}
		printf("\n");
	}
	printf("得分：%d\n",score);
    printf("输入‘I’暂停游戏");
}	
void updateWithoutInput(){  // 与用户输入无关的更新
	if (bullet_x > -1)  bullet_x--; 
	if ((bullet_x == enemy_x) && (bullet_y == enemy_y)){  // 子弹击中敌机
		score++;                // 分数加1
		enemy_x = -1;           // 产生新的飞机
		enemy_y = rand() % 10 + 11;
		bullet_x = -2;          // 子弹集中敌机后，子弹消失
	}
	if (enemy_x == high-1)  score = -999;  // 敌机跑出显示屏幕，则失败
    if ((position_x==enemy_x) && (position_y==enemy_y)) score = -999;  //两机相撞，失败

	static int speed = 0, speed2 = 0;   // 使用静态变量，可以在离开函数时保存原值
	if (speed < 20)  speed++;  // 敌机向下移动
	else{
		enemy_x++;
		speed = 0;
	}
    if (speed2 < 50) speed2++;  // 敌机左右移动
    else{
        rand() % 2 == 0 ? enemy_y++: enemy_y--; 
        speed2 = 0;
    }
}
void updateWithInput(){  // 与用户输入有关的更新
	char input;
	if(kbhit()){  // 判断是否有输入
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if ((input == 'a' || input == 'A' || input == 75) && position_y > 1)
            position_y--;  // 位置左移
		if ((input == 'd' || input == 'D' || input == 77) && position_y < width - 1)
            position_y++;  // 位置右移
		if ((input == 'w' || input == 'W' || input == 72) && position_x > 1)
            position_x--;  // 位置上移
		if ((input == 's' || input == 'S' || input == 80) && position_x < high - 1)
            position_x++;  // 位置下移
		if (input == ' ' && bullet_x < 0){  // 发射子弹
			bullet_x = position_x-1;  // 发射子弹的初始位置在飞机的正上方
			bullet_y = position_y;
		}
        if (input == 'I' || input == 'i'){
            while(1){
                int i = getch();
                if(i == 'I' || i == 'i') break;
            }
        }
		
	}
}

int main(){
	startup();  // 数据初始化
    Loading();
    HideCursor();
	while (score < 10 && score >= 0){ //  游戏循环执行
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
    show();
    if (score > 0) printf("\n你通关啦!");
    else printf("\n你输了!");
}