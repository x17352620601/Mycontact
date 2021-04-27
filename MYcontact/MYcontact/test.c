#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"


int main()
{
	int input = 0;
	InitContact(&ps);
	
	do
	{
		printf("请输入你要进行的操作\n");
		scanf("%d", &input);
		switch (input)
		{
		case quit:
			printf("退出通讯录\n");
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