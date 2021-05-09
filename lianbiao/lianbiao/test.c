#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"

void TesTSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SLTNode* pos = SListFind(plist, 1);
	SListErase(&plist, pos);
	
	//SListInsert(&plist,pos,30);
	//SListPopBack(&plist);
	//SListPopFront(&plist);
	//SListPushFront(&plist, 0);
	


	SListPrint(plist);
	
}
int main()
{
	TesTSList1();
	return 0;
}