#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


#define MAX_NAME  20
#define MAX_SEX  20
#define MAX_TELE  20
#define MAX_ADDR  20
#define DEFAULT_SZ 3

enum input
{
	quit,
	add,
	del,
	search,
	print,
	modify,
	save,
	sort
};

struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	int age;
};

struct contact
{
	struct PeoInfo *data;
	int size;
	int capacity;
}ps;

void InitContact(struct contact* ps);//初始化通讯录
void AddContact(struct contact* ps);//添加联系人信息
void PrintContact(struct contact* ps);//打印通讯员
void SaveContact(struct contact* ps);//保存联系人信息
void LoadContact(struct contact* ps);//加载通讯录
void DelContact(struct contact* ps);//删除通讯录联系人
void SearchContact(struct contact* ps);//搜索通讯录中的联系人
void AddCapacity(struct contact* ps);//增加通信录的容量
void ModifyContact(struct contact* ps);//修改联系人信息;
void SortContact(struct contact* ps);//	``