#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int position_x,position_y; // �ɻ�λ��
int high,width; //  ��Ϸ����ߴ�

void startup(){  // ���ݳ�ʼ��
    high = 20;
	width = 30;
	position_x = high/2;
	position_y = width/2;
}
void show(){  //��ʾ����
    system("cls");   // ����
	int i,j;
	for (i = 0; i < high; i++){
		for (j = 0; j < width; j++){
			if ((i == position_x) && (j == position_y))
				printf("*");  //   ����ɻ�*
			else
				printf(" ");  //   ����ո�
		}
		printf("\n");
	}

}
void updateWithoutInput(){

}
void updateWithInput(){
    char input;
	if (kbhit()){  // �ж��Ƿ�������
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == 'a')  position_y--;  // λ������
		if (input == 'd')  position_y++;  // λ������
		if (input == 'w')  position_x--;  // λ������
		if (input == 's')  position_x++;  // λ������
	}
}

int main(){
   startup();    // ���ݳ�ʼ��
   while(1){  //  ��Ϸѭ��ִ��
        show();   // ��ʾ����
        updateWithoutInput();  // ���û������޹صĸ���
        updateWithInput();    // ���û������йصĸ���
    }
}