#define _CRT_SECURE_NO_WARNINGS
#include"DLList.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//void ListInit(ListNode* phead)
//{
//	phead = BuyListNode(0);
//	phead->next = phead;
//	phead->prev = phead;
//}//需要用二级指针
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
void ListPrint(ListNode*phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		
		printf("%d-> ",cur->data);
		cur = cur->next;
	}
}
void ListPushBack(ListNode* phead,LTDataType x)
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->next = phead;
	newnode->prev = tail;
	phead->prev = newnode;
}
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->next;//头结点无数据
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = tail;
	tail->prev = newnode;	
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* frist = phead->next;
	ListNode* second = frist->next;
	phead->next = second;
	second->prev = phead;
	free(frist);
	frist = NULL;
	//ListNode* tail = phead->next->next;
	//ListNode* cur = phead->next;
	//phead->next = tail;
	//tail->prev = phead;
	//free(cur);
	//cur = NULL;
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* last = phead->prev;
	ListNode* lastsecond = last->prev;
	phead->prev = lastsecond;
	lastsecond->next = phead;
	free(last);
	last = NULL;
}
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* tail = phead->next;
	while(tail != phead)
	{
		if (tail->data == x)
		{
			return tail;
		}
		tail = tail->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	next->prev = prev;
	prev->next = next;
	free(pos);
	pos = NULL;
}