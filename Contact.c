#include"Contact.h"
//显示菜单
void menu()
{
	printf("***********************************\n");
	printf("*        1.add      2.del         *\n");
	printf("*        3.show     4.sort        *\n");
	printf("*        5.search   6.modify      *\n");
	printf("*        0.exit                   *\n");
	printf("***********************************\n");

}
//初始化通讯录
void Inti_contact(contact* con)
{
	assert(con);
	con->count = 0;
	memset(con->data, 0, sizeof(con->data));
}

//增加联系人
void add_contact(contact* con)
{
	assert(con);
	if (con->count == NUM)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入名字:>\n");
		scanf("%s", con->data[con->count].name);
		printf("请输入年龄:>\n");
		scanf("%d", &(con->data[con->count].age));
		printf("请输入性别:>\n");
		scanf("%s", con->data[con->count].sex);
		printf("请输入电话:>\n");
		scanf("%s", con->data[con->count].tel);
		printf("请输入地址:>\n");
		scanf("%s", con->data[con->count].addr);
		con->count++;
		printf("增加成功\n");
	}
}
//显示联系人
void show_contact(const contact* con)
{
	assert(con);
	int i = 0;
	printf("%-10s\t%-5s\t%-10s\t%-15s\t%-30s\n", "名字","年龄", "性别", "电话", "地址");
	for (i = 0; i < con->count; i++)
	{
		printf("%-10s\t%-5d\t%-10s\t%-15s\t%-30s\n",
			con->data[i].name,
			con->data[i].age,
			con->data[i].sex,
			con->data[i].tel,
			con->data[i].addr);
	}
}
//查找函数
int find_name(const contact* con, const char* s)
{
	assert(con && s);
	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		if (strcmp((con->data[i].name), s) == 0)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void del_contact(contact* con)
{
	assert(con);
	if (con->count == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("请输入要删除的人的姓名:>\n");
		char s[NAME] = { 0 };
		scanf("%s", &s);
		int i = find_name(con, s);
		if (i == -1)
		{
			printf("没有找到该联系人\n");
		}
		else
		{
			for (i = i; i < con->count - 1; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			con->count--;
			printf("删除成功\n");
		}
	}
}
//按首元素排序函数
int cmp (const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp((char*)e1, (char*)e2);
}
//排序通讯录
void sort_contact(contact* con)
{
	assert(con);
	if (con->count == 0)
		printf("通讯录为空，请先输入\n");
	else
	{
		qsort(con->data, con->count, sizeof(infor), cmp);
		printf("排序成功\n");
	}
}
//搜索联系人
void search_contact(contact* con)
{
	assert(con);
	if (con->count == 0)
	{
		printf("通讯录为空，请先输入\n");
	}
	else
	{
		printf("请输入要搜索的联系人的名字\n");
		char s[NAME] = { 0 };
		scanf("%s", &s);
		int i = find_name(con, s);
		if (i = -1)
		{
			printf("未找到该联系人信息\n");
		}
		else
		{
			printf("%-10s\t%-5s\t%-10s\t%-15s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
			printf("%-10s\t%-5d\t%-10s\t%-15s\t%-30s\n",
				con->data[i].name,
				con->data[i].age,
				con->data[i].sex,
				con->data[i].tel,
				con->data[i].addr);
		}
	}
}
//修改联系人信息
void modify_contact(contact* con)
{
	assert(con);
	char s[NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", &s);
	int i = find_name(con, s);
	if (i == -1)
	{
		printf("找不到该联系人\n");
	}
	else
	{
		printf("请重新输入名字:>\n");
		scanf("%s", con->data[i].name);
		printf("请重新输入年龄:>\n");
		scanf("%d", &(con->data[i].age));
		printf("请重新输入性别:>\n");
		scanf("%s", con->data[i].sex);
		printf("请重新输入电话:>\n");
		scanf("%s", con->data[i].tel);
		printf("请重新输入地址:>\n");
		scanf("%s", con->data[i].addr);
		printf("修改成功\n");
	}
}