#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType;

struct SListNote
{
	SLDataType data;
	struct SListNote* next;
};
typedef struct SListNote SLTNote;
//打印链表
void SListPrint(SLTNote* phead);
//链表后插
void SListPushBack(SLTNote** pphead, SLDataType x);
//链表前插
void SListPushFront(SLTNote** pphead, SLDataType x);
//链表前删
void SListPopFront(SLTNote** pphead);
//链表尾删
void SListPopBack(SLTNote** pphead);
//链表查找
SLTNote* SListFind(SLTNote* phead, SLDataType x);
//链表插入
void SListInsert(SLTNote** pphead, SLTNote* pos, SLDataType x);
//链表随删
void SListErase(SLTNote** pphead, SLTNote* pos);
