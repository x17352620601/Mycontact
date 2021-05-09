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
//����ı������ͷָ�룬��һ��ָ��
void SListPrint(SLTNode* phead);
//���ܻ�ı������ͷָ�룬������ָ��
void SListPushBack(SLTNode** pphead, SLDataType x);
void SListPushFront(SLTNode** pphead, SLDataType x);
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);
// ���������
SLTNode * SListFind(SLTNode * plist, SLDataType x);
// ��������posλ��֮ǰ����x
void SListInsert(SLTNode** pplist, SLTNode* pos, SLDataType x);
// ������ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pplist, SLTNode* pos);