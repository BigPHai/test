#include"game.h"
void game()
{
	char hide_mine[ROWS][COLS] = { 0 };
	char show_mine[ROWS][COLS] = { 0 };
	//初始化隐藏雷盘
	Init_hide( hide_mine, ROWS, COLS, '0');
	//初始化展示雷盘
	Init_show( show_mine, ROWS, COLS, '*');
	//设置雷
	Set_mine(hide_mine, ROW, COL);
	//调试隐藏雷盘
	//Display_mine(hide_mine, ROW, COL);
	//展示雷盘
	Display_mine(show_mine, ROW, COL);
	//排查雷
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
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}