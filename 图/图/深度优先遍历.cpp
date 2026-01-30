#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX_NUM 100

bool visited[MAX_VERTEX_NUM];   //访问标记数组

void DFSTraverse(Graph G)
{
	//对访问标记数组进行初始化
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = false;

	for (v = 0; v < G.vexnum; ++v)
		if (!visited[v])
			DFS(G, v);
}

void DFS(Graph G, int v)
{
	visit(v);
	visited[v] = true;

	for (w = FirstNeighbor(G, v), w >= 0; w = NextNeighbor(G, v, w))
	{
		if (!visited[w])           //w作为v尚未访问的邻接结点
			DFS(G, w);             //继续对w调用深度优先搜索函数
	}
}