#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MaxVertexNum 100
#define VertexType char
#define EdgeType int

//定义顶点结点
typedef struct OrMNode
{
	VertexType data;
	OrMArc* firstedge;
}OrMNode,OrMList[MaxVertexNum];

//定义边结点
typedef struct OrMArc
{
	VertexType i, j;
	OrMArc* iLink, * jLink;
}OrMArc;

//定义邻接多重表实现的图
typedef struct OrMGraph
{
	OrMList vertices;
	int vexnum, arcnum;
}OrMGraph;