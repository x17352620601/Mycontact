#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<assert.h>

#define SQDataType int
#define DEAFULT_SZ 2
//����˳���ṹ

typedef struct SeqList
{
	SQDataType* arr;
	size_t size;
	size_t capacity;
}SL;
//��ʼ��˳���
void SeqListInit(SL* ps);

//�ݻ�˳���
void SeqListDestory(SL* ps);

//��ӡ˳���
void SeqListPrint(SL* ps);

//˳�������
void SeqListAddCapacity(SL* ps);

//˳���β��
void SeqListPushBack(SL* ps, SQDataType x);

//˳���ǰ��
void SeqListPushFront(SL* ps, SQDataType x);

//˳���βɾ
void SeqListPipBack(SL* ps);

//˳���βɾ
void SeqListPopFront(SL* ps);

//˳������
void SeqListSearch(SL* ps, SQDataType x);

//˳�����ĳλ�õ��������
void SeqListInsert(SL* ps, size_t pos, SQDataType x);

//˳���ɾ��ĳλ�õ�˳��

void SeqListPopInsert(SL* ps, size_t pos);

