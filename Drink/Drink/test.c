#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LDataType;
typedef struct AlcoholNode
{
	LDataType data;
	struct AlcoholNode* prev;
	struct AlcoholNode* next;
}AC;

AC* BuyNewNode(LDataType n)
{
	AC* newnode = (AC*)malloc(sizeof(AC));
	newnode->data = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

AC* ListInit()
{
	AC* phead = BuyNewNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void Listcreat(AC*phead,LDataType n)
{
	AC* next1 = phead->next;
	for (int i = 1; i <= n; i++)
	{
		AC* newnode = BuyNewNode(i);
		newnode->prev = next1;
		newnode->next = phead;
		phead->prev = newnode;
		next1->next= newnode;
		next1 = newnode;
	}
}
void ListPrint(AC* phead)
{
	assert(phead);
	AC *next = phead->next;

	while (next->next != phead)
	{
		printf("%d ", next->data);
		next = next->next;
	}
	printf("%d\n",next->data);
}
int  ListFind7(AC*phead)
{
	int x = phead->data;
	int a = x / 10;
	int b = x / 100;
	if (x % 7 == 0 || a % 10 == 7 || b % 10 == 7 || x % 10 == 7)
	{
		return 1;
	}
	return 0;
}
int  ListFind9(AC* phead)
{
	int x = phead->data;
	int a = x / 10;
	int b = x / 100;
	if (x % 7 == 0 || a % 10 == 7 || b % 10 == 7 || x % 10 == 7)
	{
		return 0;
	}
	if (x % 9 == 0 || a % 10 == 9 || b % 10 == 9 || x % 10 == 9)
	{
		return 1;
	}
	return 0;
}
void LTest()
{
	AC* plist = ListInit();
	int n = 0;
	scanf("%d", &n);
	Listcreat(plist, n);
	AC* next = plist->next;
	while (next!=plist)
	{
		
		while (!ListFind7(next)&& next != plist)
		{
			next = next->next;
		}
		AC* pos1 = next;
		AC* prev = pos1->prev;
		while (!ListFind9(next)&& next != plist)
		{
			next = next->next;
		}
		AC* pos2 = next;
		prev->next = pos2;
		pos2->prev = prev;
	}
	
	ListPrint(plist);

}

int main()
{
	LTest();
	return 0;
}
