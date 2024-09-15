#include"game.h"
void menu()
{
	printf("***********************\n");
	printf("******  1.play   ******\n");
	printf("******  0.exit   ******\n");
	printf("***********************\n");
}
void Init_hide(char hide_mine[ROWS][COLS], int rows, int cols, char set)
{
	int r = 0;
	int c = 0;
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			hide_mine[r][c] = set;
		}
	}
}
void Init_show(char show_mine[ROWS][COLS], int rows, int cols, char set)
{
	int r = 0;
	int c = 0;
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			show_mine [r][c] = set;
		}
	}
}
void Display_mine(char board[ROWS][COLS], int row, int col)
{
	int r = 0;
	int c = 0;
	printf("     ɨ����Ϸ      \n");
	for (c = 0; c <= col; c++)
	{
		printf("%d ", c);
	}
	printf("\n");
	for (r = 1; r <= row; r++) 
	{
		printf("%d ", r);
		for (c = 1; c <= col; c++)
		{
			printf("%c ", board[r][c]);
		}
		printf("\n");
	}
	printf("     ɨ����Ϸ      \n");
}
void Set_mine(char hide_mine[ROWS][COLS], int row, int col) 
{
	int count = EASY_COUNT;
	srand((unsigned int)time(NULL));
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (hide_mine[x][y] != '1')
		{
			hide_mine[x][y] = '1';
			count--;
		}
		
	}
}
int get_mine_count(char hide_mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	int r = 0;
	int c = 0;
	for (r = x - 1; r <= x + 1; r++)
	{
		for (c = y - 1; c <= y + 1; c++)
		{
			if (hide_mine[r][c] - '0' == 1)
			{
				count++;
			}
		}
	}
	return count;
}
void Fine_mine(char hide_mine[ROWS][COLS], char show_mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int z = 0;
	while (z <= ROW * COL - EASY_COUNT)
	{
		printf("������Ҫ�Ų������:->");
		scanf("%d%d", &x, &y);
		//����������ȷ
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�������������Ƿ��ظ�
			if (show_mine[x][y] == '*')//���ظ������֧
			{
				//�������
				if (hide_mine[x][y] == '1')
				{
					printf("�㱻ը���ˣ������¿�ʼ��Ϸ\n");
					Display_mine(hide_mine, ROW, COL);
					break;
				}
				//���������
				else
				{
					//ͳ���׵ĸ���
					int count = get_mine_count(hide_mine, x, y);
					show_mine[x][y] = count + '0';//ת���������ַ�����
					Display_mine(show_mine, ROW, COL);
					z++;
				}

			}
			else
			{
				printf("�Ѿ��������\n");
			}
			
		}
		else
		{
			printf("�����������������\n");
		}
	}
}