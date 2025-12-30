#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ElemType int

//线索二叉树的结点类型的声明
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode, * ThreadTree;

//全局变量pre,指向当前访问结点的前驱
ThreadNode* pre = NULL;

//访问结点函数的改造
void visit(ThreadNode* q)
{
	//如果左子树为空，则建立前驱线索
	if (q->lchild == NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}

	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}



//后序遍历线索二叉树，一边遍历，一边线索化
//左、右、根
void PostThread(ThreadTree T)
{
	if (T != NULL)
	{
		PostThread(T->lchild);
		PostThread(T->rchild);
		visit(T);
	}
}

//后序线索化二叉树
void CreatInThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		PostThread(T);    //先序线索化二叉树
		if (pre->rchild == NULL)
			pre->rtag = 1;
	}
}