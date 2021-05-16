#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int SDataType;
typedef struct Stack
{
	SDataType* data;
	SDataType capacity;
	SDataType top;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);

//ջ������ɾ������
//��ջ
void StackPush(ST* ps, SDataType x);
//��ջ
void StackPop(ST* ps);

SDataType StackTop(ST* ps);

int StackSize(ST* ps);

bool  StackEmpty(ST* ps);