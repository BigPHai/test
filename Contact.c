#include"Contact.h"
//��ʾ�˵�
void menu()
{
	printf("***********************************\n");
	printf("*        1.add      2.del         *\n");
	printf("*        3.show     4.sort        *\n");
	printf("*        5.search   6.modify      *\n");
	printf("*        0.exit                   *\n");
	printf("***********************************\n");

}
//��ʼ��ͨѶ¼
void Inti_contact(contact* con)
{
	assert(con);
	con->count = 0;
	memset(con->data, 0, sizeof(con->data));
}

//������ϵ��
void add_contact(contact* con)
{
	assert(con);
	if (con->count == NUM)
	{
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		printf("����������:>\n");
		scanf("%s", con->data[con->count].name);
		printf("����������:>\n");
		scanf("%d", &(con->data[con->count].age));
		printf("�������Ա�:>\n");
		scanf("%s", con->data[con->count].sex);
		printf("������绰:>\n");
		scanf("%s", con->data[con->count].tel);
		printf("�������ַ:>\n");
		scanf("%s", con->data[con->count].addr);
		con->count++;
		printf("���ӳɹ�\n");
	}
}
//��ʾ��ϵ��
void show_contact(const contact* con)
{
	assert(con);
	int i = 0;
	printf("%-10s\t%-5s\t%-10s\t%-15s\t%-30s\n", "����","����", "�Ա�", "�绰", "��ַ");
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
//���Һ���
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
//ɾ����ϵ��
void del_contact(contact* con)
{
	assert(con);
	if (con->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("������Ҫɾ�����˵�����:>\n");
		char s[NAME] = { 0 };
		scanf("%s", &s);
		int i = find_name(con, s);
		if (i == -1)
		{
			printf("û���ҵ�����ϵ��\n");
		}
		else
		{
			for (i = i; i < con->count - 1; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			con->count--;
			printf("ɾ���ɹ�\n");
		}
	}
}
//����Ԫ��������
int cmp (const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp((char*)e1, (char*)e2);
}
//����ͨѶ¼
void sort_contact(contact* con)
{
	assert(con);
	if (con->count == 0)
		printf("ͨѶ¼Ϊ�գ���������\n");
	else
	{
		qsort(con->data, con->count, sizeof(infor), cmp);
		printf("����ɹ�\n");
	}
}
//������ϵ��
void search_contact(contact* con)
{
	assert(con);
	if (con->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ���������\n");
	}
	else
	{
		printf("������Ҫ��������ϵ�˵�����\n");
		char s[NAME] = { 0 };
		scanf("%s", &s);
		int i = find_name(con, s);
		if (i = -1)
		{
			printf("δ�ҵ�����ϵ����Ϣ\n");
		}
		else
		{
			printf("%-10s\t%-5s\t%-10s\t%-15s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-10s\t%-5d\t%-10s\t%-15s\t%-30s\n",
				con->data[i].name,
				con->data[i].age,
				con->data[i].sex,
				con->data[i].tel,
				con->data[i].addr);
		}
	}
}
//�޸���ϵ����Ϣ
void modify_contact(contact* con)
{
	assert(con);
	char s[NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", &s);
	int i = find_name(con, s);
	if (i == -1)
	{
		printf("�Ҳ�������ϵ��\n");
	}
	else
	{
		printf("��������������:>\n");
		scanf("%s", con->data[i].name);
		printf("��������������:>\n");
		scanf("%d", &(con->data[i].age));
		printf("�����������Ա�:>\n");
		scanf("%s", con->data[i].sex);
		printf("����������绰:>\n");
		scanf("%s", con->data[i].tel);
		printf("�����������ַ:>\n");
		scanf("%s", con->data[i].addr);
		printf("�޸ĳɹ�\n");
	}
}