#include"game.h"
void game()
{
	char hide_mine[ROWS][COLS] = { 0 };
	char show_mine[ROWS][COLS] = { 0 };
	//��ʼ����������
	Init_hide( hide_mine, ROWS, COLS, '0');
	//��ʼ��չʾ����
	Init_show( show_mine, ROWS, COLS, '*');
	//������
	Set_mine(hide_mine, ROW, COL);
	//������������
	//Display_mine(hide_mine, ROW, COL);
	//չʾ����
	Display_mine(show_mine, ROW, COL);
	//�Ų���
	Fine_mine(hide_mine, show_mine, ROW, COL);

}
int main()
{
	int input = 0;
	do 
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);
	return 0;
}