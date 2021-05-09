#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int SLDataType;

struct SListNode
{
	int data;
	struct SListNode* next;
}; 

typedef struct SListNode SLTNode;
//不会改变链表的头指针，传一级指针
void SListPrint(SLTNode* phead);
//可能会改变链表的头指针，传二级指针
void SListPushBack(SLTNode** pphead, SLDataType x);
void SListPushFront(SLTNode** pphead, SLDataType x);
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);
// 单链表查找
SLTNode * SListFind(SLTNode * plist, SLDataType x);
// 单链表在pos位置之前插入x
void SListInsert(SLTNode** pplist, SLTNode* pos, SLDataType x);
// 单链表删除pos位置的值
void SListErase(SLTNode** pplist, SLTNode* pos);