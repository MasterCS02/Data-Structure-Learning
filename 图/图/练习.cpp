#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


#define MAX_VERTEX_NUM 100
#define MAX_STACK 100
#define MAX_QUEUE 100

typedef struct MGraph
{
	int vexdata[MAX_VERTEX_NUM];
	int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
}MGraph;

//定义一个顺序栈
typedef struct stack
{
	int top;		//栈顶指针
	int data[MAX_STACK];   //数据
}Stack;

//初始化栈
void InitStack(Stack S)
{
	int top = -1;
	for (int i = 0; i < MAX_STACK; ++i)
	{
		S.data[i] = 0;
	}
}

//定义一个队列(链式队列)

//首先对结点进行声明
typedef struct LinkNode
{
	int dada;
	struct LinkNode* next;

}LinkNode;

//声明队列
typedef struct Queue
{
	LinkNode* rear, *front;
}Queue;

void InitQueue(Queue Q)
{
	Q.rear = Q.front = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

void BFSTraverse(MGraph G,Queue Q)
{
	bool visited[MAX_VERTEX_NUM] = {false};
	
	//初始化标记数组
	for (int i = 0; i < G.vexnum; ++i)
	{
		visited[i] = false;
	}

	for (int i = 0; i < G.vexnum; ++i)
	{
		if (!visited[i])
			BFS(G, i, Q);
	}
}

void visit(MGraph G)
{

}

void BFS(MGraph G, int v, Queue Q)
{
	//初始化辅助队列
	InitQueue(Q);

	visit[v];



}
