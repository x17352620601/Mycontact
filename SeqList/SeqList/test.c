#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
void test()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 0);
	//SeqListPushFront(&sl, 5);
	//SeqListSearch(&sl, 3);
	//SeqListInsert(&sl, 2, 8);
	SeqListPopInsert(&sl, 7);
	SeqListPrint(&sl);

}

int main()
{
	test();
	return 0;
}