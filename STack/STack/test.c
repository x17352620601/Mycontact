#define _CRT_SECURE_NO_WARNINGS
#include"STack.h"
int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");


	StackDestory(&st);
	return 0;
}