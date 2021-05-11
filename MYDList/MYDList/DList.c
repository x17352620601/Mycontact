#define _CRT_SECURE_NO_WARNINGS
#include"DList.h"
//产生一个新的链表
DListNode* ListNewnode(DLDataType x)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//初始化链表
DListNode* ListInit()
{
	DListNode*newnode = ListNewnode(0);
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}
//后插
void ListPushBack(DListNode* phead, DLDataType x)
{
	assert(phead);
	//DListNode* newnode = ListNewnode(x);
	//DListNode* prev = phead->prev;
	//prev->next = newnode;
	//newnode->prev = prev;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}
//打印链表
void ListPrint(DListNode* phead)
{
	assert(phead);
	DListNode* next = phead->next;
	while (next != phead)
	{
		printf("%d->", next->data);
		next = next->next;
	}
	printf("\n");
}

//前插
void ListPushFront(DListNode* phead, DLDataType x)
{
	assert(phead);
	//DListNode* next = phead->next;
	//DListNode* newnode = ListNewnode(x);
	//newnode->next = next;
	//next->prev = newnode;
	//newnode->prev = phead;
	//phead->next = newnode;
	ListInsert(phead->next, x);
}

//前删
void ListPopFront(DListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//DListNode* next = phead->next;
	//DListNode* second = next->next;
	//phead->next = second;
	//second->prev = phead;
	//free(next);
	//next = NULL;
	ListErase(phead->next);
}

//weishan
void ListPopBack(DListNode* phead)
{
	assert(phead);
	assert(phead->next!=phead);
	//DListNode* prev = phead->prev;
	//DListNode* last = prev->prev;
	//phead->prev = last;
	//last->next = phead;
	//free(prev);
	//prev = NULL;
	ListErase(phead->prev);
}

//chazhao/xiugai
DListNode* ListFind(DListNode* phead, DLDataType x)
{
	assert(phead);
	DListNode* next = phead->next;
	while (next != phead)
	{
		if (next->data == x)
		{
			return next;
		}
		next = next->next;
	}
	return NULL;
}

void ListInsert(DListNode* pos, DLDataType x)
{
	assert(pos);
	DListNode* prev = pos->prev;
	DListNode* newnode = ListNewnode(x);
	newnode->next = pos;
	newnode->prev = prev;
	prev->next = newnode;
	pos->prev = newnode;
}

void ListErase(DListNode* pos)
{
	assert(pos);
	DListNode* next = pos->next;
	DListNode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
void ListDestory(DListNode* phead)
{
	assert(phead);
	DListNode* next = phead->next;
	while (next != phead)
	{
		DListNode* cur = next->next;
		free(next);
		next = cur;
	}
	free(phead);
	phead = NULL;
}