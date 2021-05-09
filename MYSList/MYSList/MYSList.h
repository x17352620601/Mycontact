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
//��ӡ����
void SListPrint(SLTNote* phead);
//������
void SListPushBack(SLTNote** pphead, SLDataType x);
//����ǰ��
void SListPushFront(SLTNote** pphead, SLDataType x);
//����ǰɾ
void SListPopFront(SLTNote** pphead);
//����βɾ
void SListPopBack(SLTNote** pphead);
//�������
SLTNote* SListFind(SLTNote* phead, SLDataType x);
//�������
void SListInsert(SLTNote** pphead, SLTNote* pos, SLDataType x);
//������ɾ
void SListErase(SLTNote** pphead, SLTNote* pos);
