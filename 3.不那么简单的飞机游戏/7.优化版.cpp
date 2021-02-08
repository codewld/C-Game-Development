#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// ȫ�ֱ���
int position_x, position_y; // �ɻ�λ��
int bullet_x, bullet_y; // �ӵ�λ��
int enemy_x, enemy_y; // �л�λ��
int high, width; //  ��Ϸ����ߴ�
int score; // �÷�

void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void gotoxy(int x,int y){  //��������������������ƶ���ԭ��λ�ý����ػ�
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void Loading(){
	int i;
	system("cls");   // ��������
    printf("�����صз�����\n");
	printf("WASD���������ҿ����ƶ�\n");
	printf("�ո�����ƿ���\n\n");
    for (i = 10; i > 0; i--){
	    printf("%d\n",i);
	    Sleep(100);
	}
	printf("���������ʼ��Ϸ\n");
    i = getch();
}
void startup(){ // ���ݳ�ʼ��
	high = 22;  width = 32;  //����ߴ�
	position_x = high * 3 / 4;  position_y = width / 2;  //�ɻ�λ��
	bullet_x = -2;  bullet_y = position_y;  //�ӵ�λ��
	enemy_x = 2;  enemy_y = rand() % width;;  //�л�λ��
	score = 0;  //�÷�
}
void show(){  // ��ʾ����
	gotoxy(0,0);  // ����ƶ���ԭ��λ��
	int i,j;
	for (i = 0; i <= high; i++){
		for (j = 0; j <= width; j++){
			if ((i == position_x) && (j == position_y))  printf("*");  //   ����ɻ�*
			else if ((i == enemy_x) && (j == enemy_y))  printf("O");  //   ����л�O
			else if ((i == bullet_x) && (j == bullet_y))  printf("|");  //   ����ӵ�|
			else if (i == high) printf("-");   // ���ǽ��
            else if (j == 0 || j == width) printf("|");
            else printf(" ");  //   ����ո�
		}
		printf("\n");
	}
	printf("�÷֣�%d\n",score);
    printf("���롮I����ͣ��Ϸ");
}	
void updateWithoutInput(){  // ���û������޹صĸ���
	if (bullet_x > -1)  bullet_x--; 
	if ((bullet_x == enemy_x) && (bullet_y == enemy_y)){  // �ӵ����ел�
		score++;                // ������1
		enemy_x = -1;           // �����µķɻ�
		enemy_y = rand() % 10 + 11;
		bullet_x = -2;          // �ӵ����ел����ӵ���ʧ
	}
	if (enemy_x == high-1)  score = -999;  // �л��ܳ���ʾ��Ļ����ʧ��
    if ((position_x==enemy_x) && (position_y==enemy_y)) score = -999;  //������ײ��ʧ��

	static int speed = 0, speed2 = 0;   // ʹ�þ�̬�������������뿪����ʱ����ԭֵ
	if (speed < 20)  speed++;  // �л������ƶ�
	else{
		enemy_x++;
		speed = 0;
	}
    if (speed2 < 50) speed2++;  // �л������ƶ�
    else{
        rand() % 2 == 0 ? enemy_y++: enemy_y--; 
        speed2 = 0;
    }
}
void updateWithInput(){  // ���û������йصĸ���
	char input;
	if(kbhit()){  // �ж��Ƿ�������
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		if ((input == 'a' || input == 'A' || input == 75) && position_y > 1)
            position_y--;  // λ������
		if ((input == 'd' || input == 'D' || input == 77) && position_y < width - 1)
            position_y++;  // λ������
		if ((input == 'w' || input == 'W' || input == 72) && position_x > 1)
            position_x--;  // λ������
		if ((input == 's' || input == 'S' || input == 80) && position_x < high - 1)
            position_x++;  // λ������
		if (input == ' ' && bullet_x < 0){  // �����ӵ�
			bullet_x = position_x-1;  // �����ӵ��ĳ�ʼλ���ڷɻ������Ϸ�
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
	startup();  // ���ݳ�ʼ��
    Loading();
    HideCursor();
	while (score < 10 && score >= 0){ //  ��Ϸѭ��ִ��
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();  // ���û������йصĸ���
	}
    show();
    if (score > 0) printf("\n��ͨ����!");
    else printf("\n������!");
}