#define _CRT_SECURE_NO_WARNINGS
#include"MYSList.h"

void SListPrint(SLTNote* phead)
{
	while (phead != NULL)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}

SLTNote* SListMalloc(SLDataType x)
{
	SLTNote* newnode = (SLTNote*)malloc(sizeof(SLTNote));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SLTNote** pphead, SLDataType x)
{
	SLTNote* newnode = SListMalloc(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNote* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}

void SListPushFront(SLTNote** pphead, SLDataType x)
{
	SLTNote* newnode = SListMalloc(x);
	SLTNote* tail = *pphead;
		*pphead = newnode;
		(*pphead)->next = tail;
}

void SListPopFront(SLTNote** pphead)
{
	if (*pphead == NULL)
	{
		printf("这是一个空链表\n");
		return;
	}
	else
	{
		SLTNote* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

void SListPopBack(SLTNote** pphead)
{
	if (*pphead == NULL)
	{
		printf("这是一个空链表\n");
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	else
	{
		SLTNote* prev = NULL;
		SLTNote* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

SLTNote* SListFind(SLTNote* phead, SLDataType x)
{
	while (phead)
	{
		if (x == phead->data)
		{
			return phead;
		}
		phead = phead->next;
	}
	return NULL;
}
void SListInsert(SLTNote** pphead, SLTNote* pos, SLDataType x)
{
	if (NULL == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNote* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNote* newnode = SListMalloc(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListErase(SLTNote** pphead, SLTNote* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNote* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}