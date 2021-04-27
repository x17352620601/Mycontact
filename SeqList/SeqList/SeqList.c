#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
//初始化顺序表
void SeqListInit(SL* ps)
{
	ps->arr = (SQDataType*)malloc(DEAFULT_SZ * sizeof(SQDataType));
	if (ps->arr == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	memset(ps->arr, 0, DEAFULT_SZ * sizeof(SQDataType));
	ps->size = 0;
	ps->capacity = DEAFULT_SZ;
	printf("初始化成功\n");
}

//摧毁顺序表
void SeqListDestory(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
}

//打印顺序表
void SeqListPrint(SL* ps)
{

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//顺序表增容
void SeqListAddCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SQDataType* pf = (SQDataType*)realloc(ps->arr, (2 + ps->capacity) * sizeof(SQDataType));
		if (pf == NULL)
		{
			printf("扩容失败\n");
			return;
		}
		ps->arr = pf;
		ps->capacity += 2;
		printf("扩容成功\n");
	}
}

//顺序表尾插
void SeqListPushBack(SL* ps, SQDataType x)
{
	if (ps->size == ps->capacity)
	{
		SeqListAddCapacity(ps);
	}
	ps->arr[ps->size] = x;
	ps->size++;
}

//顺序表前插
void SeqListPushFront(SL* ps, SQDataType x)
{
	if (ps->size == ps->capacity)
	{
		SeqListAddCapacity(ps);
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ps->arr[ps->size - i] = ps->arr[ps->size - i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//顺序表尾删
void SeqListPipBack(SL* ps)
{
	assert(ps);
	ps->size--;
	printf("删除成功\n");
}

//顺序表头删
void SeqListPopFront(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
	printf("删除成功\n");
}

//顺序表查找
void  SeqListSearch(SL* ps, SQDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			printf( "%d ",ps->arr[i]);
			return;
		}
	}
	if(i=ps->size)
	{ 
		printf("没有找到你要找的数字\n");
	}
	
}
//在顺序表的末位置添加数字
void SeqListInsert(SL* ps, size_t pos, SQDataType x)
{
	if (ps->size == ps->capacity)
	{
		SeqListAddCapacity(ps);
	}
	assert(ps);
	int i = 0;
	
	for (i = 0; i < ps->size-pos; i++)
	{
		ps->arr[ps->size-i] = ps->arr[ps->size-i-1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//删除顺序表某位置的数组
void SeqListPopInsert(SL* ps, size_t pos)
{
	int i= 0;
	for (i = pos; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}