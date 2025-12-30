#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ElemType int


//二叉树的中序线索化

//线索二叉树的结点类型的声明
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;


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

	//如果左子树不为空
	//前驱结点如果不为空指针，并且它没有右孩子
	//那么将该前驱节点的右孩子指针域指向q
	//即q作为pre的后继结点
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}



//中序遍历线索二叉树，一边遍历，一边线索化
//左、根、右
void InThread(ThreadTree T)      
{
	if (T != NULL)
	{
		InThread(T->lchild);
		visit(T);          //访问“根节点”
		InThread(T->rchild);
	}
}



//中序线索化二叉树
void CreatInThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);    //中序线索化二叉树(逻辑域中序遍历相同)
		if (pre->rchild == NULL)
			pre->rtag = 1;  
	}
}

//找中序后继

//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode* Firstnode(ThreadNode* p)
{
	//循环找到最左下结点（不一定是叶结点）
	while (p->ltag == 0)
	{
		p = p->lchild;
	}
	return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode* Nextnode(ThreadNode* p)
{
	//右子树最左下结点
	if (p->rtag == 0)
		return Firstnode(p->rchild);
	else
		return p->rchild;
}

//对中序线索二叉树进行中序遍历
void Inorder(ThreadNode* T)
{
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
		visit(p);
}

//找中序前驱
ThreadNode* Lastnode(ThreadNode* p)
{
	//循环找到最右下结点（不一定是叶结点）
	while (p->rtag == 0)
	{
		p = p->rchild;
	}
	return p;
}

//在中序线索二叉树中找到结点p的前驱节点
ThreadNode* Prenode(ThreadNode* p)
{
	//左子树的最右下结点
	if (p->ltag == 0)
		return Lastnode(p->lchild);
	else
		return p->lchild;
}

//对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode* T)
{
	for (ThreadNode* p = Lastnode(T); p != NULL; p = Prenode(p))
		visit(p);
}