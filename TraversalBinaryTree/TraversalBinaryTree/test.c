#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

typedef char  TBTDataType;

typedef struct TraversalBinaryTreeNode
{
	TBTDataType val;
	struct TraversalBinaryTreeNode* left;
	struct TraversalBinaryTreeNode* right;
}TBTNode;

TBTNode* CreateTree()
{
	TBTNode* A = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* B = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* C = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* D = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* E = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* F = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode* G = (TBTNode*)malloc(sizeof(TBTNode));

	A->val = 'A';
	B->val = 'B';
	C->val = 'C';
	D->val = 'D';
	E->val = 'E';
	F->val = 'F';
	G->val = 'G';

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	C->left = F;
	C->right = G;
	D->left = NULL;
	D->right = NULL;
	F->left = NULL;
	F->right = NULL;
	E->left = NULL;
	E->right = NULL;
	G->left = NULL;
	G->right = NULL;
	return A;

}
//Ç°Ðò
void PrevOrder(TBTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	else
	{
		printf("%c ", root->val);
		PrevOrder(root->left);
		PrevOrder(root->right);
	}
}

//ÖÐÐò
void InOrder(TBTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	else
	{

		PrevOrder(root->left);
		printf("%c ", root->val);
		PrevOrder(root->right);
	}
}

//ºóÐò
void PostOrder(TBTNode* root)
{
	if (NULL == root)
	{
		printf("NULL ");
		return;
	}
	else
	{
		PrevOrder(root->left);
		PrevOrder(root->right);
		printf("%c ", root->val);
	}
}
//²ãÐò
void  LevelOrder(TBTNode *root)
{
	Queue q;
	QueueInit(&q);
	if (NULL != root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		TBTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->val);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");
	QueueDestory(&q);
}

int main()
{
	TBTNode* root = CreateTree();
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	LevelOrder(root);
	return 0;
}