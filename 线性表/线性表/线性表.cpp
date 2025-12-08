#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ElemType int

//顺序表

////顺序表的静态实现
//#define MaxSize 10
//typedef struct
//{
//	ElemType data[MaxSize];
//	int length;
//}SqList;
//
//
////初始化一个顺序表
//void InitList(SqList &L)
//{
//	int i = 0;
//	for (i = 0; i < MaxSize; i++)
//	{
//		L.data[i] = 0;  //将所有数据元素设置为默认初始值
//		L.length = 0;   //顺序表初始长度为0
//	}
//}
//
////主函数
//int main()
//{
//	SqList L;     //定义一个顺序表
//	InitList(L);  //初始化顺序表
//	
//	return 0;
//}

//顺序表的动态实现
//#define InitSize 10
//typedef struct
//{
//	ElemType* data;
//	int MaxSize;
//	int length;
//}SqList;
//
////初始化动态顺序表
//void InitList(SqList &L)
//{
//	L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
//	L.length = 0;
//	L.MaxSize = InitSize;
//} 
//
////增加动态数组的长度（malloc实现）
////void IncreaseSize(SqList& L, int len)
////{
////	int* p = L.data;
////	L.data = (ElemType*)malloc((L.MaxSize + len) * sizeof(ElemType));
////	//此时malloc会返回一个新的指针，用来接收新开辟的空间
////
////	int i = 0;
////	for (i = 0; i < L.length; i++)
////	{
////		L.data[i] = p[i];  //将数据赋值到新区域
////	}
////
////	L.MaxSize += len;      //顺序表最大长度增加len
////	free(p);               //释放原来的内存空间
////}
//
////realloc实现
//void IncreaseSize(SqList& L, int len)
//{
//	ElemType* p = (ElemType*)realloc(L.data, (L.MaxSize + len) * sizeof(ElemType));
//
//	//判断realloc是否开辟成功
//	if (p != NULL)
//	{
//		L.data = p;
//	}
//	else
//	{
//		perror("realloc");
//		return;
//	}
//
//	L.MaxSize += len;
//}
//
////主函数
//int main()
//{
//	SqList L;               //定义一个顺序表
//	InitList(L);            //初始化顺序表
//	IncreaseSize(L, 5);      //增加动态数组的长度
//
//	return 0;
//}

//#define MaxSize 10
//typedef struct
//{
//	int data[MaxSize];
//	int length;
//}SqList;

//在L的位序i处插入元素e
//bool ListInsert(SqList& L, int i, int e)  //在L的位序i处插入元素e
//{
//	if (i<1 || i>L.length + 1)
//	{
//		return false;    //判断位序i是否越界
//	}
//
//	if (L.length >= MaxSize)
//	{
//		return false;   //判断存储空间是否已满
//	}
//
//	int j = L.length;
//	for (j = L.length; j >= i; j--)  //将第i个元素及之后的元素后移
//	{
//		L.data[j] = L.data[j - 1];
//	}
//	L.data[i - 1] = e;             //在位置i处放入e
//	L.length++;                    //长度+1
//
//	return true;
//}


//bool ListDelete(SqList &L, int i, int &e)
//{
//	if (i<1 || i>L.length + 1)  //判断位序i是否有效
//		return false;
//
//	e = L.data[i - 1];  //把被删除的元素赋值给e
//	int j = 0;
//	for (j = i; j < L.length; j++)
//	{
//		L.data[j - 1] = L.data[j];  //将第i个位置后的元素前移
//	}
//	L.length--;  //线性表长度减1
//	return true;
//}
//
//
//int main()
//{
//	SqList L;
//	InitList(L);
//	//...
//	//ListInsert(L, 3, 3);
//	int e = -1;
//	if (ListDelete(L, 3, e))
//		printf("已删除第三个元素，删除元素值为%d\n", e);
//	else
//		printf("位序不合法，删除失败\n")
//
//	return 0;
//}

//单链表的删除

//按照位序删除
//typedef struct LNode
//{
//	ElemType data;
//	struct LNode* next;
//}LNode,*LinkList;
//
////带头结点
//bool InitList(LinkList& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));
//	if (L == NULL)
//		return false;
//
//	L->next = NULL;
//	return true;
//}

//bool ListDelete(LinkList& L, int i, ElemType& e)  //按照位序删除时，被删除的数据要传给调用者
//{
//	//判断位序合法性
//	if (i < 1)
//		return false;
//
//	LNode* p;                 //创建一个p指针，来扫描单链表
//	p = L;                    //将p指针指向头结点（第0个节点）
//	int j = 0;                //记录p指针所在的位置
//
//	while (p != NULL && j < i - 1)
//	{
//		p = p->next;     //让p指针找到第i-1个位序的结点就停下
//		j++;
//	}
//
//	if (p == NULL)         //i值不合法（i位序指向空间是空指针）
//		return false;
//	if (p->next == NULL)   //i-1后无其他结点
//		return false;
//
//	LNode* q = p->next;    //让q结点指向要被删除的结点
//	e = q->data;           //传回被删除的数据
//	p->next = q->next;     //将被删除结点的后继结点与其前驱节点相连，从而形成被删除结点的断链效果
//	free(q);               //释放被删除结点的内存空间
//
//	return true;
//}
//
//
////指定结点的删除
//bool DeleteNode(LNode* p, ElemType& e)   //删除p结点
//{
//	if (p == NULL)
//		return false;
//	e = p->data;
//	LNode* q = p->next;     //定义p的后继结点为q
//	p->data = q->data;      //把q结点的数据复制给p结点，从而抹去p结点的数据，达成删除的效果
//	p->next = q->next;      //让p结点指向q的后继结点，从而让q这个节点断链
//
//	free(q);
//	return true;
//}

//单链表的查找

//按位查找
//LNode* GetElem(LinkList L,int i)
//{
//	//判断位序合法性
//	if (i < 0)
//		return NULL;
//
//	LNode* p = L;
//	int j = 0;
//
//	while (p != NULL && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//
//	return p;
//
//}
//
////按值查找
//LNode* LocateElem(LinkList L, ElemType e)
//{
//	LNode* p = L->next;  //从第一个结点开始查找（不是头结点！）
//	while (p != NULL && p->data != e)
//	{
//		p = p->next;
//	}
//	return p;
//}
//
//
////求表的长度
//int Length(LinkList L)
//{
//	int len = 0;
//	LNode* p = L;
//	while (p->next != NULL)
//	{
//		p = p->next;
//		len++;
//	}
//	return len;
//
//}
//
//#define STOP 9999
//
////尾插法
//LinkList List_tailInsert(LinkList& L)
//{
//	int x;
//	L = (LNode*)malloc(sizeof(LNode));
//	LNode* s, * r = L;
//	scanf("%d", &x);
//	while (x != STOP)
//	{
//		s = (LNode*)malloc(sizeof(LNode));
//		s->data = x;
//		r->next = s;
//		scanf("%d", &x);
//
//	}
//	r->next = NULL;
//	return L;
//}
//
////头插法
//
//LinkList List_HeadInsert(LinkList& L)
//{
//	LNode* s;
//	int x ;
//	L = (LNode*)malloc(sizeof(LNode));  //创建头结点
//	L->next = NULL;
//	scanf("%d", &x);   //输入要添加的数据元素
//
//	while (x != STOP)
//	{
//		s = (LNode*)malloc(sizeof(LNode));  //创建一个新结点
//		s->data = x;       //把数据元素添加到新结点中
//		s->next = L->next;
//		L->next = s;      //把新结点插入到头结点的后面
//		scanf("%d", &x);
//	}
//	return L;
//}
//
//
//int main()
//{
//	LinkList L;
//	InitList(L);
//
//	ElemType Deletedata;
//	//ListDelete(L, 3, Deletedata);
//
//
//	return 0;
//}

//双链表

//typedef struct DNode
//{
//	ElemType data;
//	struct DNode* prior;  //前驱结点
//	struct DNode* next;   //后继结点
//}DNode,*DLinkList;
//
//
////初始化双链表
//bool InitDList(DLinkList& L)
//{
//	L = (DNode*)malloc(sizeof(DNode));
//	if (L == NULL)
//		return false;
//	L->next = NULL;
//	L->prior = NULL;
//	return true;
//}
//
////双链表的插入
//bool InsertNextDNode(DNode* p, DNode* s)  //在p结点后面插入s结点
//{
//	if (p == NULL || s == NULL)
//		return false;
//	s->next = p->next;
//
//	if(p->next!=NULL)             //如果p结点有后继结点
//		p->next->prior = s;       //让p结点的后继结点的前向指针指向s
//
//	p->next = s;
//	s->prior = p;
//
//	return true;
//}
//
////双链表的删除
//bool DeleteNextDNode(DNode* p)  //删除p结点的后继结点s
//{
//	if (p == NULL)
//		return false;
//
//	DNode* s = p->next;   //定义p的后继结点是s
//	if (s == NULL)
//		return false;    //说明p结点没有后继
//
//	p->next = s->next;
//	if(s->next!=NULL)
//		s->next->prior = p;   
//	//如果s有后继结点，那么把后继结点的前向节点改成p
//	//如果没有后继结点，那也没有更改的必要
//
//	free(s);  //释放被删除结点的空间
//	return true;
//}
//
//int main()
//{
//	DLinkList L;
//	InitDList(L);
//
//	return 0;
//}

//循环单链表
//typedef struct LNode
//{
//	ElemType data;
//	struct LNode* next;
//}LNode,*LinkList;
//
////初始化循环单链表
//bool InitList(LinkList& L)
//{
//	L = (LNode*)malloc(sizeof(LNode));
//	if (L == NULL)
//		return false;
//	L->next == L;   //头结点next指向头结点
//	return true;
//}
//
////判断循环单链表是否为空
//bool Empty(LinkList L)
//{
//	if (L->next == L)
//		return true;
//	else
//		return false;
//}

//循环双链表

//typedef struct DNode
//{
//	ElemType data;
//	struct DNode* prior;
//	struct DNode* next;
//}DNode,*DLinkList;
//
////初始化循环双链表
//bool InitDLinkList(DLinkList& L)
//{
//	L = (DNode*)malloc(sizeof(DNode));
//	if (L == NULL)
//		return false;
//	L->next = L;
//	L->prior = L;
//	return true;
//}
//
////判断循环双链表是否为空
//bool Empty(DLinkList& L)
//{
//	if (L->next == L)
//		return true;
//	else
//		return false;
//}
//
////判断结点p是否为循环双链表的表尾结点
//bool isTail(DLinkList L,DNode* p)
//{
//	if (p->next == L)
//		return true;
//	else
//		return false;
//}

//静态链表
//#define MaxSize 10
//struct Node
//{
//	ElemType data;
//	int next;
//};
//
//bool InitSLinkList(struct Node* arr)
//{
//	int i = 0;
//	arr[0].data = 0;   //假设ElemType为int
//	arr[0].next = -1;
//
//	for (i = 1; i < MaxSize; i++)
//	{
//		arr[i].data = 0;
//		arr[i].next = -2;
//	}
//
//	return true;
//}
//
//void testSLinkList()
//{
//	struct Node arr[MaxSize];  //数组arr作为静态链表
//
//	InitSLinkList(arr);
//}


typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

//创建带有头结点的单链表
bool InitList(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}

//后插插入元素
bool InsertNextNode(LinkList& L, int x)
{
	//创建新结点
	LNode* p = (LNode*)malloc(sizeof(LNode));
	//创建尾指针
	LNode* r = (LNode*)malloc(sizeof(LNode));

	if (p == NULL || r == NULL)
		return false;
	p->data = x;
	p->next = L->next;
	L->next = p;
	r = p;
	return true;
}

//头插法左旋p个元素
bool LeftMove(LinkList& L, int p,int n)
{
	//假设p=4
	//遍历数组，找到第p个结点
	int j = 1;  //记录q指针的位置
	LNode* q = (LNode*)malloc(sizeof(LNode));
	LNode* tmp = (LNode*)malloc(sizeof(LNode));

	while (q != NULL && j < p)
	{
		q = q->next;
		j++;
	}

	tmp = q;

	while (tmp != NULL && q != NULL && j < n)
	{
		tmp->next = L->next;
		L->next = tmp;
		q = q->next;
		tmp = q;
	}

	return true;

}


int main()
{
	LinkList L;
	InitList(L);
	int x = 0;
	int n = 10; //假设插入10个元素

	//插入元素
	scanf("%d", &x);
	while (n--)
	{
		InsertNextNode(L, x);
		scanf("%d", &x);
	}





	return 0;
}