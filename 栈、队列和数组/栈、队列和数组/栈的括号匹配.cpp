#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


#define MaxSize 10

//声明一个顺序表
typedef struct
{
	char data[MaxSize];  //栈中存放的是字符（括号）
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack& S)
{
	S.top = 0;
}

//判空
bool StackEmpty(SqStack S)
{
	if (S.top == 0)
		return true;
	else
		return false;
}

//入栈函数
bool Push(SqStack& S, char x)
{
	//判断是否栈满
	if (S.top == MaxSize)
		return false;
	S.data[S.top++] = x;

	return true;
}

//出栈函数
bool Pop(SqStack& S, char& x)
{
	//判断是否栈空
	if (StackEmpty(S))
		return false;
	x = S.data[--S.top];

	return true;
}

//括号匹配函数
bool bracketCheck(char str[], int length)
{
	SqStack S;  //定义栈
	InitStack(S); // 初始化栈
	
	for (int i = 0; i < length; i++)
	{
		//扫描存放括号的字符数组
		//第一步：将左括号压入栈中
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')  
		{
			Push(S, str[i]);    //扫到左括号时,入栈
		}
		//第二步：没有扫到左括号的处理办法
		else
		{
			if (StackEmpty(S))  //扫到右括号而且栈空了，就说明匹配失败
				return false;

			//栈没空的情况
			//step1:栈顶元素出栈
			char topElem;
			Pop(S, topElem);

			//step2：判断栈顶的左括号是否与读到的右括号相匹配
			//以下语句是按照左右括号不匹配的思路来写的
			if (str[i] == ')' && topElem != '(')
				return false;
			if (str[i] == ']' && topElem != '[')
				return false;
			if (str[i] == '}' && topElem != '{')
				return false;
		}
	}
	return StackEmpty(S);  //如果检索完全部括号后栈空，则说明全部匹配成功
}

//主函数
int main()
{
	char str[100] = "";

	scanf("%s", str);

	size_t len = strlen(str);

	printf("%d\n", len);
	if (bracketCheck(str, len))
		printf("成功\n");
	else
		printf("失败\n");

	return 0;
}