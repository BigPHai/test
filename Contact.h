#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define NAME 30
#define SEX 10
#define TEL 12
#define ADDR 30
#define NUM 100
typedef struct infor //人的信息
{
	char name[NAME];
	int  age;
	char sex[SEX];
	char tel[TEL];
	char addr[ADDR];
} infor;
typedef struct contact //联系人的信息
{
	infor data[NUM];
	int count; //通讯录内容
} contact;
enum
{
	EXIT,
	ADD,
	DEL,
	SHOW,
	SORT,
	SEARCH,
	MODIFY,
};
void menu();

void Inti_contact(contact* con);

void add_contact(contact* con);

void show_contact(contact* con);

void del_contact(contact* con);

int find_name(contact* con, char* s);

void sort_contact(contact* con);

void search_contact(contact* con);

void modify_contact(contact* con);