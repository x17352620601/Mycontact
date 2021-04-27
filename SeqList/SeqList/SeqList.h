#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<assert.h>

#define SQDataType int
#define DEAFULT_SZ 2
//定义顺序表结构

typedef struct SeqList
{
	SQDataType* arr;
	size_t size;
	size_t capacity;
}SL;
//初始化顺序表
void SeqListInit(SL* ps);

//摧毁顺序表
void SeqListDestory(SL* ps);

//打印顺序表
void SeqListPrint(SL* ps);

//顺序表增容
void SeqListAddCapacity(SL* ps);

//顺序表尾插
void SeqListPushBack(SL* ps, SQDataType x);

//顺序表前插
void SeqListPushFront(SL* ps, SQDataType x);

//顺序表尾删
void SeqListPipBack(SL* ps);

//顺序表尾删
void SeqListPopFront(SL* ps);

//顺序表查找
void SeqListSearch(SL* ps, SQDataType x);

//顺序表在某位置的添家数字
void SeqListInsert(SL* ps, size_t pos, SQDataType x);

//顺序表删除某位置的顺序

void SeqListPopInsert(SL* ps, size_t pos);

