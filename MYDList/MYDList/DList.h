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
//��ʼ������
DListNode* ListInit();
//β��
void ListPushBack(DListNode* phead, DLDataType x);
//��ӡ����
void ListPrint(DListNode* phead);
//ǰ��
void ListPushFront(DListNode* phead, DLDataType x);
//ǰɾ
void ListPopFront(DListNode* phead);
//weishan
void ListPopBack(DListNode* phead);
//chazhao/xiugai
DListNode* ListFind(DListNode* phead, DLDataType x);
void ListInsert(DListNode* pos, DLDataType x);
void ListErase(DListNode* pos);
void ListDestory(DListNode* phead);