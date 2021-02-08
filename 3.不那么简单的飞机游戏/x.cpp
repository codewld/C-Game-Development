#include <stdio.h>
#include <conio.h>
#include <windows.h>

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void endgame(){
	char i;
	printf("\n此段代码的目的是防止因为误按而看不到结束画面\n");
	while(1){
		printf("请输入Q停止游戏\n");
		scanf("%c", &i);
		while(i == '\n') scanf("%c", &i);
	    if (i == 'Q')	return;
	}
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
	printf("游戏即将开始\n");
	Sleep(1000);
}
void showairplane(int y){
    int i;
    for (i=0;i<y;i++)  printf(" ");  // 下面输出一个复杂的飞机图案
	printf("  *\n");
	for (i=0;i<y;i++)  printf(" ");
	printf("*****\n");
	for (i=0;i<y;i++)  printf(" ");
	printf(" * * \n");
}
void control(int &x, int &y, int &gun_site, int &isFire){
	if(kbhit())  // 判断是否有输入
	{
		char input;
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if (input == 'a'||input == 75)  y--;
		if (input == 'd'||input == 77)  y++;
		if (input == 'w'||input == 72)  x--;
		if (input == 's'||input == 80)  x++;
		if (input == ' ')  isFire = 1;
	}
    gun_site = y + 2;
}
void print(int startx, int endx, int gun_site, int isFire){
	int i, j;
	if (isFire==0){ // 若未开火，输出空行
			for(i=startx;i<endx;i++)  printf("\n");
		}
		else{   // 若开火，输出激光竖线
			for(i=startx;i<endx;i++){
				for (j=0;j<gun_site;j++)  printf(" ");
				printf("|\n");
			}
		}
}
void printMissile(int ny, int gun_site, int isFire){
	int i;
	if (isFire && gun_site != ny){
		if (gun_site > ny){
			for (i = 0; i < ny; i++)  printf(" ");  // 打印靶子
		    printf("*");
			for (i++; i < gun_site; i++) printf(" ");
			printf("|\n");
		}else if (gun_site < ny){
			for (i = 0; i < gun_site; i++) printf(" ");
            printf("|\n");
			for (i++; i < ny; i++) printf(" ");
			printf("*\n");
		}
	}
	else{
		for (i=0;i<ny;i++)  printf(" ");  // 打印靶子
		printf("*\n");
	}
}
void printall(int nx, int ny, int x, int gun_site, int isFire){  // nx为导弹纵坐标； ny为导弹横坐标； x为飞机纵坐标； gun_site为枪
	system("cls");   // 清屏函数
	int i, j;                                          
	print(0, nx, gun_site, isFire);
	/*for (j=0;j<ny;j++)  printf(" ");  // 打印靶子
		printf("*\n");*/
	printMissile(ny, gun_site, isFire);  // 打印靶子
    print(nx+1, x, gun_site, isFire);
}
void Missile_change(int &ny, int &nx){
	if (ny == 2) ny+=4;
    if (ny == 15) ny-=4;
	int random = rand();
	int num = random % 7;
	if (num == 0)  ny++;
	else if (num == 1)  ny--;
	else if (num == 2)  nx++;
}
void game(){
	int i,j;
	int x = 15, y = 10, gun_site = y + 2, isFire = 0;  // 初始位置
	int ny = 5, nx = 0, isKilled = 0; // 一个靶子，放在第一行，ny列上
	HideCursor();  //隐藏光标
	Loading();  //加载页面
	while (!isKilled){
		//Sleep(20);
		printall(nx, ny, x, gun_site, isFire);
		if (gun_site == ny && isFire)  isKilled = 1; // 击中靶子
		isFire = 0;
		if (nx >= x){
			printf("防守失败！\n");
			endgame();
			return;
		} 
        Missile_change(ny, nx);  // 改变导弹状态
		control(x, y, gun_site, isFire);  // 根据输入改变飞机状态
		showairplane(y);  // 打印飞机
	}
    printf("\n敌军飞机已被击落！\n");
	endgame();
	return;
}

int main(){
	int i;
	out:
	printf("开始游戏请输入 1 退出请输入 0 \n");
	i = getchar();
	if (i == '1')	game();
	else if (i == '0') printf("\n程序已退出\n");
	else{
		system("cls");   // 清屏函数
		printf("输入错误，请重新输入：\n");
		getchar();
		goto out;
	} 
}

