#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;

struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
};

typedef struct ListNode ListNode;
void ListPrint(ListNode* phead);
ListNode* ListInit();
void ListDestory(ListNode* phead);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
