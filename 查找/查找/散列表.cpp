#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_HASH 100

//创建拉链节点
typedef struct ChainNode
{
	int key;  //关键字为整型
	struct ChainNode* next;
}ChainNode,*ChainList;

//顺序存储的散列表
typedef ChainList HashTable[MAX_HASH];

void InitHashTable(HashTable H)
{
	for (int i = 0; i < MAX_HASH; ++i)
		H[i] = NULL;
}

//不带头指针
//void InitChainList(ChainList& L)
//{
//	L = NULL;
//}
//
//bool HeadInsert(ChainList& L, int k)
//{
//	ChainNode* p = (ChainNode*)malloc(sizeof(ChainNode));
//	if (p == NULL)
//		return false;
//	p->key = k;
//
//	p->next = L;
//	L = p;
//
//	return true;
//}


//构造散列函数
//取留余数法，找到小于散列表长度的最大的质数

bool isPrime(int x)
{
	for (int j = 2; j <= sqrt(x); j++)
	{
		if (x % j == 0)
			return false;
	}
	return true;
}

int maxPrime(int len)
{
	//从len往下搜索，第一个找到的就是最大的
	for (int i = len; i >= 2; --i)
	{
		if (isPrime(i))
			return i;
	}
	return 2;
}

//插入结点
bool InsertHash(HashTable& H, int key)
{
	//求得关键字通过散列函数计算出来的结果
	//从而将关键字的存储地址进行映射
	int x = key % maxPrime(MAX_HASH);

	ChainNode* p = (ChainNode*)malloc(sizeof(ChainNode));
	if (p == NULL)
		return false;
	p->key = key;

	p->next = H[x];  //H[x]本身就是一个头指针
	H[x] = p;

	return true;

}


