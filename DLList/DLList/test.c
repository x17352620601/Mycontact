#define _CRT_SECURE_NO_WARNINGS
#include"DLList.h"
//��ͷ˫��ѭ��
void DListTest()
{
	ListNode* plist = ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	ListPushBack(plist,4);
	//ListPushFront(plist, 4);
	//ListPopFront(plist);
	//ListPopBack(plist);
	ListNode* pos = ListFind(plist, 3);
	ListInsert(pos,  30);
	ListErase(pos);
	ListPrint(plist);
	ListDestory(plist);
}
int main()
{
	DListTest();
	return 0;
}