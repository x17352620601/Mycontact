#define _CRT_SECURE_NO_WARNINGS
#include"MYSList.h"

void SListTest()
{
	SLTNote* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);
	SListPopFront(&plist);
	SListPopBack(&plist);
	
	SLTNote* pos= SListFind(plist,3);
	//SListInsert(&plist,pos,20);
	//SLTNote* pos1 = SListFind(plist, 2);
	//SListInsert(&plist, pos1, 20);
	//SLTNote* pos2 = SListFind(plist, 3);
	//SListInsert(&plist, pos2, 20);
	//SListPrint(plist);
	SListErase(&plist, pos);
	SListPrint(plist);
}
int main()
{
	SListTest();
	return 0;
}