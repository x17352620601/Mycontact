#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
}

SLTNode* BuySListNode(SLDataType x)
{
	SLTNode* Newnode = (SLTNode*)malloc(sizeof(SLTNode));
	Newnode->data = x;
	Newnode->next = NULL;
	return Newnode;
}
void SListPushBack(SLTNode** pphead, SLDataType x)
{
	SLTNode* Newnode = (SLTNode*)malloc(sizeof(SLTNode));
	Newnode->data = x;
	Newnode->next = NULL;

	if (*pphead == NULL)
	{
		*pphead = Newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//尾结点链接新节点
		tail->next = Newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLDataType x)
{
	SLTNode* Newnode = BuySListNode(x);
	Newnode->next = *pphead;
	*pphead = Newnode;
}

void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("是空链表不用删除\n");
		return;
	}
	else
	{
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
		/*(*pphead) = (*pphead)->next;*/
	}
}
void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("是空链表不用删除\n");
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* P = *pphead;
		while (tail->next != NULL)
		{	
			tail = tail->next;
		}
		while (P->next != tail)
		{
			P = P->next;
		};
		P->next = NULL;
		free(tail);
		tail = NULL;
	}
}
SLTNode* SListFind(SLTNode* plist, SLDataType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(SLTNode** pplist, SLTNode* pos, SLDataType x)
{
	if (pos == *pplist)
	{
		SListPushFront(pplist,x);
	}
	else
	{
		SLTNode* prev = *pplist;
		//SLTNode* cur = *pplist;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListErase(SLTNode** pplist, SLTNode* pos)
{
	if (pos == *pplist)
	{
		SListPopFront(pplist);
	}
	else
	{
		SLTNode* prev = *pplist;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}