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

void InitContact(struct contact* ps);//��ʼ��ͨѶ¼
void AddContact(struct contact* ps);//�����ϵ����Ϣ
void PrintContact(struct contact* ps);//��ӡͨѶԱ
void SaveContact(struct contact* ps);//������ϵ����Ϣ
void LoadContact(struct contact* ps);//����ͨѶ¼
void DelContact(struct contact* ps);//ɾ��ͨѶ¼��ϵ��
void SearchContact(struct contact* ps);//����ͨѶ¼�е���ϵ��
void AddCapacity(struct contact* ps);//����ͨ��¼������
void ModifyContact(struct contact* ps);//�޸���ϵ����Ϣ;
void SortContact(struct contact* ps);//	``