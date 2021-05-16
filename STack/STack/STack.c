#define _CRT_SECURE_NO_WARNINGS
#include"STack.h"
void StackInit(ST* ps)
{
	ps->data = (SDataType*)malloc(sizeof(SDataType*) * 4);
	if (ps->data == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;//初始化给0top指向的是栈顶元素的下一个
	             //给-1则指向栈顶
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = ps->capacity = 0;
}

//栈顶插入删除数据
//入栈
void StackPush(ST* ps,SDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		SDataType* newps = (SDataType*)realloc(ps->data,sizeof(SDataType*) * 2 * ps->capacity);
		if (newps == NULL)
		{
			printf("realloc fail\n");
			return;
		}
		else
		{
			ps->data = newps;
			ps->capacity = 2 * ps->capacity;
		}
	}

	ps->data[ps->top] = x;
	ps->top++;	
}
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

SDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps > 0);
	return ps->data[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool  StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}