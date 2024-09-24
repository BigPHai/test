#include"Contact.h"
int main()
{
	int input = 0;
	contact con;
	Inti_contact(&con);
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("退出程序\n");
			break;
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}