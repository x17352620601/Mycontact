#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

//Ѱ����ϵ��
static int  FindContact(struct contact* ps, char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (!strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	if (i == ps->size)
	{
		return -1;
	}
}

//��ʼ��ͨѶ¼
void InitContact(struct contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(CHAR_SIZE * sizeof(struct PeoInfo));
	if (ps->data != NULL)
	{
		ps->capacity = CHAR_SIZE;
		ps->size = 0;
		
	}
	else
	{
		return;

	}
	LoadContact(ps);
	printf("��ʼ���ɹ�\n");
}
//����ͨѶ¼����
void AddCapacity(struct contact* ps)
{

	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc((ps->data, (2 + ps->capacity) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}
//���ͨѶ¼����
void AddContact(struct contact* ps)
{
	AddCapacity(ps);
	printf("����������\n");
	scanf("%s", ps->data[ps->size].name);
	printf("�������Ա�\n");
	scanf("%s", ps->data[ps->size].sex);
	printf("����������\n");
	scanf("%d", &ps->data[ps->size].age);
	printf("������绰\n");
	scanf("%s", ps->data[ps->size].tele);
	printf("������סַ\n");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n");
}



//��ӡͨѶ¼
void PrintContact(struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n",
		"����", "�Ա�", "����", "�绰", "��ַ");
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			ps->data[i].name,
			ps->data[i].sex,
			ps->data[i].age,
			ps->data[i].tele,
			ps->data[i].addr);
	}
	printf("\n");
}

//ɾ��ͨѶ¼����
void DelContact(struct contact* ps)
{
	printf("��������Ҫɾ������ϵ�˵�����\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int ret = FindContact(ps, name);//������ps
	if (-1 == ret)
	{
		printf("û���Ҵ����ϵ��\n");
	}
	else
	{
		int i = ret;
		for (i = ret; i < ps->size; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(struct contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("��������Ҫ���ҵ���ϵ������\n");
	scanf("%s", name);
	int ret = FindContact(ps, name);
	if (-1 == ret)
	{
		printf("û���ҵ���Ҫ����ϵ��\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n",
			"����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n",
			ps->data[ret].name,
			ps->data[ret].sex,
			ps->data[ret].age,
			ps->data[ret].tele,
			ps->data[ret].addr);
	}
}

void ModifyContact(struct contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸���ϵ����Ϣ������\n");
	scanf("%s", name);
	int ret = FindContact(ps, name);
	if (-1 == ret)
	{
		printf("û���ҵ���Ҫ�ҵ���ϵ��\n");
	}
	else
	{
		printf("����������\n");
		scanf("%s", ps->data[ret].name);
		printf("�������Ա�\n");
		scanf("%s", ps->data[ret].sex);
		printf("����������\n");
		scanf("%d", &ps->data[ret].age);
		printf("������绰\n");
		scanf("%s", ps->data[ret].tele);
		printf("������סַ\n");
		scanf("%s", ps->data[ret].addr);
	}
}

void SortContact(struct contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->data[i].age > ps->data[j+1].age)
			{
				struct PeoInfo tmp = { 0 };
				tmp= ps->data[i];
				ps->data[i] = ps->data[j];
				ps->data[j] = tmp;
			}
		}
	}
	printf("����ɹ�\n");
}
void DestoryContact(struct contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct contact* ps)
{
	FILE* pf = fopen("MyContact.txt", "wb");
	if (pf == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pf);
		}
	printf("����ɹ�\n");
	fclose(pf);
	pf = NULL;
}

//����ͨ��¼��Ϣ
void LoadContact(struct contact* ps)
{
	FILE* pf = fopen("MyContact.txt", "rb");
	if (pf == NULL)
	{
		printf("���ļ�ʧ��");

	}
	
		while (fread(&(ps->data[ps->size]), sizeof(struct PeoInfo), 1, pf))
		{
			AddCapacity(ps);
			ps->size++;
		}
	printf("������ϵ�˳ɹ�\n");
	fclose(pf);
	pf = NULL;
}