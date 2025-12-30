#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


//串的顺序存储

//静态数组实现
#define MAXLEN 255
typedef struct
{
	char ch[MAXLEN];
	int length;
}SString;


//求子串
bool SubString(SString& Sub, SString S, int pos, int sublen)
{
	//判断子串范围是否越界
	if (pos + sublen - 1 > S.length)
		return false;
	
	for (int i = pos; i < pos + sublen; i++)
		Sub.ch[i - pos + 1] = S.ch[i];

	Sub.length = sublen;
	return true;
}

//字符串比较

//比较操作。若S>T，则返回值>0;若S=T，则返回值=0；若S<T，则返回值<0
int StrCompare(SString S, SString T)
{
	for (int i = 1; i <= S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//如果扫描过的所有字符都相同，则长度长的串更大
	return S.length - T.length;
}



//定位操作
int Index(SString S, SString T)
{
	int i = 1, n = StrLenth(S), m = StrLength(T);
	SString sub;   //暂存子串
	while (i + m - 1 <= n)  //i <= n-m+1
	{
		SubString(sub, S, i, m);  //摘取i位序上长度为m的子串

		if (StrCompare(sub, T) != 0)  //如果从主串摘取出来的子串与T子串不相同
			++i;     //位序加1，重新循环
		else
			return i;   //相同，返回子串在主串中的位置
	}
	return 0;   //S中不存在与T相等的子串
}





//动态数组实现
typedef struct 
{
	char* ch;    //按串长分配存储区，ch指向串的基地址
	int length;  //串的长度
}HString;

//初始化
HString S;
void InitHString(HString S)
{
	S.ch = (char*)malloc(MAXLEN * sizeof(char));
	//注意：当空间使用完毕后，需要使用free释放空间
	S.length = 0;
}

