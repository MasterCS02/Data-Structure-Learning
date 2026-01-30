#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX_NUM 100

bool visited[MAX_VERTEX_NUM];   //访问标记数组

void BFSTraverse(Graph G)
{
	//对访问标记数组进行初始化
	for (i = 0; i < G.vexnum; ++i)
		visited[i] = false;

	//初始化辅助队列Q
	InitQueue(Q);             

	for (i = 0; i < G.vexnum; ++i)
		if (!visited[i])          //对每个连通分量调用一次BFS
			BFS(G, i);
}

//广度优先遍历算法
void BFS(Graph G, int v)          //从顶点v出发，广度优先遍历G
{
	visit(v);            //访问初始结点v
	visited[v] = true;   //对已访问的结点v做上标记

	EnQueue(Q,v);       //顶点v入队列Q

	while (!isEmpty(Q))
	{
		DeQueue(Q, v); //队头元素出列
		for (w = FirstNeighbor(G, v), w >= 0; w = NextNeighbor(G, v, w))
		{
			//检测v所有邻接点
			if (!visited[w])         //w作为尚未访问的邻接结点
			{
				visit(w);            //访问w
				visited[w] = true;   //对已访问的结点w做上标记
				EnQueue(Q, w);       //顶点w入队列
			}
		}
	}
}