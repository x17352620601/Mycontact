#define _CRT_SECURE_NO_WARNINGS
#include"DList.h"

void DListTest()
{
	DListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushFront(plist, 5);
	ListPushFront(plist, 4);
	ListPushFront(plist, 3);
	ListPushFront(plist, 2);
	ListPushFront(plist, 1);
	//ListPopFront(plist);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPopBack(plist);
	ListPrint(plist);
}
void DListTest2()
{
	DListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	DListNode* pos = ListFind(plist, 4);
	if (pos)
	{
		pos->data *= 5;
		printf("找到了，并乘以5\n");
	}
	else
	{
		printf("没有找到\n");
	}
	ListInsert(pos, 24);
	ListErase(pos);
	ListPrint(plist);
	ListDestory(plist);
}
int main()
{
	DListTest();
	return 0;
}