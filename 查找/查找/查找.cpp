#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ElemType int
#define MAX_LIST 100
#define MAX_BLOCK 50


//存储数据的顺序表（可以无序）
typedef struct SSTable
{
    ElemType List[MAX_LIST];
    int Tablelen;
}SSTable;

SSTable L;

//创建索引表
typedef struct
{
    ElemType maxvalue;  //索引表记录每个块内的元素最大值
    int low, high;       //每个块的低指针和高指针
}Index;

Index Q[MAX_BLOCK];

int Index_Seq_Search(SSTable L, Index Q[], ElemType key)
{
    int i = 0, j = 0;
    //将被查找元素与索引表中的块进行比较
    for (i = 0; (i < MAX_BLOCK) && (key > Q[i].maxvalue); ++i)
        ;

    //如果把所有块都比较完了还没有找到，返回失败
    if (i >= MAX_BLOCK)
        return -1;
    else     //对块内进行顺序查找
    {
        for (j = Q[i].low; (j <= Q[i].high) && (key != L.List[j]); ++j)
            ;

        if (j > Q[i].high)
            return -1;
        else
            return j;
    }
}


#define ElemType int
#define MAX_LIST 100
#define MAX_BLOCK 50

//存储数据的顺序表（可以无序）
typedef struct SSTable
{
    ElemType List[MAX_LIST];
    int Tablelen;
}SSTable;

SSTable L;

//创建索引表
typedef struct
{
    ElemType maxvalue;  //索引表记录每个块内的元素最大值
    int low, high;       //每个块的低指针和高指针
}Index;

Index Q[MAX_BLOCK];

int Index_Binary_Search(SSTable L, Index Q[], ElemType key)
{
    //创建左、右、中指针
    int low_binary = 0, high_binary = MAX_BLOCK - 1, mid;
    int j = 0;

    //根据被查找的关键字，对索引表进行折半查找
    while (low_binary <= high_binary)
    {
        mid = (low_binary + high_binary) / 2;

        if (key == Q[mid].maxvalue)   //必定成功的情况
        {
            for (j = Q[mid].low; (j <= Q[mid].high) && (key != L.List[j]); ++j)
                ;
            return j;
        }

        if (key < Q[mid].maxvalue)
            high_binary = mid - 1;
        else if (key > Q[mid].maxvalue)
            low_binary = mid + 1;
    }

    if (low_binary >= MAX_BLOCK)
        return -1;
    else
    {
        for (j = Q[low_binary].low; (j <= Q[low_binary].high) && (key != L.List[j]); ++j)
            ;

        if (j > Q[low_binary].high)
            return -1;
        else
            return j;
    }
}