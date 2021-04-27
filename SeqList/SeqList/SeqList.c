#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
//��ʼ��˳���
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
	printf("��ʼ���ɹ�\n");
}

//�ݻ�˳���
void SeqListDestory(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
}

//��ӡ˳���
void SeqListPrint(SL* ps)
{

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//˳�������
void SeqListAddCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SQDataType* pf = (SQDataType*)realloc(ps->arr, (2 + ps->capacity) * sizeof(SQDataType));
		if (pf == NULL)
		{
			printf("����ʧ��\n");
			return;
		}
		ps->arr = pf;
		ps->capacity += 2;
		printf("���ݳɹ�\n");
	}
}

//˳���β��
void SeqListPushBack(SL* ps, SQDataType x)
{
	if (ps->size == ps->capacity)
	{
		SeqListAddCapacity(ps);
	}
	ps->arr[ps->size] = x;
	ps->size++;
}

//˳���ǰ��
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

//˳���βɾ
void SeqListPipBack(SL* ps)
{
	assert(ps);
	ps->size--;
	printf("ɾ���ɹ�\n");
}

//˳���ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
	printf("ɾ���ɹ�\n");
}

//˳������
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
		printf("û���ҵ���Ҫ�ҵ�����\n");
	}
	
}
//��˳����ĩλ���������
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

//ɾ��˳���ĳλ�õ�����
void SeqListPopInsert(SL* ps, size_t pos)
{
	int i= 0;
	for (i = pos; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}