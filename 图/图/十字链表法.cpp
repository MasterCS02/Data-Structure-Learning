#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


//十字链表法

#define MaxVertexNum 100
#define VertexType char
#define EdgeType int

//定义顶点结点
typedef struct ONode
{
	VertexType data;             //顶点信息
	OrArc* firstin,*firstout;    

	//firstin是该顶点作为弧头的第一条弧的指针
	//firstout是该顶点作为弧尾的第一条弧的指针

}ONode,OrList[MaxVertexNum];
//用顺序表存储顶点结点，实现十字链表


//定义弧结点
typedef struct OrArc
{
	VertexType tailvex,headvex;
	OrArc* hlink, * tlink;

	//tailvex是弧尾顶点的编号
	//headvex是弧头顶点的编号

	//hlink是弧头相同的下一条弧
	//tlink是弧=尾相同的下一条弧


}OrArc;

//定义十字链表实现的图
typedef struct OrGraph
{
	OrList vertices;
	int vexnum, arcnum;
}OrGraph;


