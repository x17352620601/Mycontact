#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DLDataType;

typedef struct ListNode
{
	DLDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}DListNode;
//初始化链表
DListNode* ListInit();
//尾插
void ListPushBack(DListNode* phead, DLDataType x);
//打印链表
void ListPrint(DListNode* phead);
//前插
void ListPushFront(DListNode* phead, DLDataType x);
//前删
void ListPopFront(DListNode* phead);
//weishan
void ListPopBack(DListNode* phead);
//chazhao/xiugai
DListNode* ListFind(DListNode* phead, DLDataType x);
void ListInsert(DListNode* pos, DLDataType x);
void ListErase(DListNode* pos);
void ListDestory(DListNode* phead);