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
	printf("\n�˶δ����Ŀ���Ƿ�ֹ��Ϊ�󰴶���������������\n");
	while(1){
		printf("������Qֹͣ��Ϸ\n");
		scanf("%c", &i);
		while(i == '\n') scanf("%c", &i);
	    if (i == 'Q')	return;
	}
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
	printf("��Ϸ������ʼ\n");
	Sleep(1000);
}
void showairplane(int y){
    int i;
    for (i=0;i<y;i++)  printf(" ");  // �������һ�����ӵķɻ�ͼ��
	printf("  *\n");
	for (i=0;i<y;i++)  printf(" ");
	printf("*****\n");
	for (i=0;i<y;i++)  printf(" ");
	printf(" * * \n");
}
void control(int &x, int &y, int &gun_site, int &isFire){
	if(kbhit())  // �ж��Ƿ�������
	{
		char input;
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
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
	if (isFire==0){ // ��δ�����������
			for(i=startx;i<endx;i++)  printf("\n");
		}
		else{   // �����������������
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
			for (i = 0; i < ny; i++)  printf(" ");  // ��ӡ����
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
		for (i=0;i<ny;i++)  printf(" ");  // ��ӡ����
		printf("*\n");
	}
}
void printall(int nx, int ny, int x, int gun_site, int isFire){  // nxΪ���������ꣻ nyΪ���������ꣻ xΪ�ɻ������ꣻ gun_siteΪǹ
	system("cls");   // ��������
	int i, j;                                          
	print(0, nx, gun_site, isFire);
	/*for (j=0;j<ny;j++)  printf(" ");  // ��ӡ����
		printf("*\n");*/
	printMissile(ny, gun_site, isFire);  // ��ӡ����
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
	int x = 15, y = 10, gun_site = y + 2, isFire = 0;  // ��ʼλ��
	int ny = 5, nx = 0, isKilled = 0; // һ�����ӣ����ڵ�һ�У�ny����
	HideCursor();  //���ع��
	Loading();  //����ҳ��
	while (!isKilled){
		//Sleep(20);
		printall(nx, ny, x, gun_site, isFire);
		if (gun_site == ny && isFire)  isKilled = 1; // ���а���
		isFire = 0;
		if (nx >= x){
			printf("����ʧ�ܣ�\n");
			endgame();
			return;
		} 
        Missile_change(ny, nx);  // �ı䵼��״̬
		control(x, y, gun_site, isFire);  // ��������ı�ɻ�״̬
		showairplane(y);  // ��ӡ�ɻ�
	}
    printf("\n�о��ɻ��ѱ����䣡\n");
	endgame();
	return;
}

int main(){
	int i;
	out:
	printf("��ʼ��Ϸ������ 1 �˳������� 0 \n");
	i = getchar();
	if (i == '1')	game();
	else if (i == '0') printf("\n�������˳�\n");
	else{
		system("cls");   // ��������
		printf("����������������룺\n");
		getchar();
		goto out;
	} 
}

