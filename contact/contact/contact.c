#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

//寻找联系人
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

//初始化通讯录
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
	printf("初始化成功\n");
}
//增加通讯录容量
void AddCapacity(struct contact* ps)
{

	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc((ps->data, (2 + ps->capacity) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("扩容成功\n");
		
		}
		else
		{
			printf("扩容失败\n");
		}
	}
}
//添加通讯录内容
void AddContact(struct contact* ps)
{
	AddCapacity(ps);
	printf("请输入名字\n");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入性别\n");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入年龄\n");
	scanf("%d", &ps->data[ps->size].age);
	printf("请输入电话\n");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入住址\n");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
}



//打印通讯录
void PrintContact(struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n",
		"姓名", "性别", "年龄", "电话", "地址");
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

//删除通讯录类容
void DelContact(struct contact* ps)
{
	printf("请输入你要删除的联系人的名字\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int ret = FindContact(ps, name);//传的是ps
	if (-1 == ret)
	{
		printf("没有找打该联系人\n");
	}
	else
	{
		int i = ret;
		for (i = ret; i < ps->size; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(struct contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入你要查找的联系人姓名\n");
	scanf("%s", name);
	int ret = FindContact(ps, name);
	if (-1 == ret)
	{
		printf("没有找到你要的联系人\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n",
			"姓名", "性别", "年龄", "电话", "地址");
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
	printf("请输入要修改联系人信息的名字\n");
	scanf("%s", name);
	int ret = FindContact(ps, name);
	if (-1 == ret)
	{
		printf("没有找到你要找的联系人\n");
	}
	else
	{
		printf("请输入名字\n");
		scanf("%s", ps->data[ret].name);
		printf("请输入性别\n");
		scanf("%s", ps->data[ret].sex);
		printf("请输入年龄\n");
		scanf("%d", &ps->data[ret].age);
		printf("请输入电话\n");
		scanf("%s", ps->data[ret].tele);
		printf("请输入住址\n");
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
	printf("排序成功\n");
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
		printf("打开文件失败\n");
		return;
	}
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pf);
		}
	printf("保存成功\n");
	fclose(pf);
	pf = NULL;
}

//加载通信录信息
void LoadContact(struct contact* ps)
{
	FILE* pf = fopen("MyContact.txt", "rb");
	if (pf == NULL)
	{
		printf("打开文件失败");

	}
	
		while (fread(&(ps->data[ps->size]), sizeof(struct PeoInfo), 1, pf))
		{
			AddCapacity(ps);
			ps->size++;
		}
	printf("加载联系人成功\n");
	fclose(pf);
	pf = NULL;
}