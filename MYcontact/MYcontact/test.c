#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"


int main()
{
	int input = 0;
	InitContact(&ps);
	
	do
	{
		printf("��������Ҫ���еĲ���\n");
		scanf("%d", &input);
		switch (input)
		{
		case quit:
			printf("�˳�ͨѶ¼\n");
				break;
		case add:
			AddCapacity(&ps);
			AddContact(&ps);
			break;
		case del:
			DelContact(&ps);
			break;
		case search:
		
			SearchContact(&ps);
			break;
		case print:
			PrintContact(&ps);
			break;
		case modify:
			ModifyContact(&ps);
			break;
		case save:
			SaveContact(&ps);
			break;
		case sort:
			SortContact(&ps);
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}