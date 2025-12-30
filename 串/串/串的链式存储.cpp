#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//串的链式存储
typedef struct StringNode
{
	char ch[4];                  //每个结点存4个字符
	struct StringNode* next;  //下一个结点的指针域
}StringNode,*String;

//求子串

