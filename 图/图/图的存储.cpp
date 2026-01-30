#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//邻接表法

#define MaxVertexNum 100
#define VertexType char
#define EdgeType int

//使用链式存储的方式，定义边链表
typedef struct ArcNode
{
	int adjvex;    //该变量用于记录该弧指向的顶点（结点）位置
	struct ArcNode* nextarc;  //指向下一条弧的指针
	//InfoType info;          //边的权值
}ArcNode;

//使用顺序存储的方式，定义存放图中顶点信息的顺序表
typedef struct VNode
{
	VertexType data;     //顶点信息
	ArcNode* firstarc;   //指向第一条依附于该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];

//定义基于邻接表存储的图
typedef struct
{
	AdjList vertices;		//邻接表
	int vexnum, arcnum;		//图的顶点数和弧数
}ALGraph;                   //Adjacency List Graph 邻接表图






//邻接矩阵法
typedef struct
{
	VertexType vex[MaxVertexNum];              //创建顶点表
	EdgeType edge[MaxVertexNum][MaxVertexNum]; //创建邻接矩阵，边表
	int vexnum, arcnum;                        //图当前的顶点数和边数
}MGraph;



