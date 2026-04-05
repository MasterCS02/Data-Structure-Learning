#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//int Partition(int A[], int low, int high)
//{
//	//选定枢轴元素
//	int pivot = A[low];   //选取第一个元素作为枢轴
//	while (low < high)
//	{
//		//当high所指元素大于枢轴元素时
//		while (low<high && A[high]>pivot)
//			high--;				//high指针-1
//
//		//循环跳出，说明high所指元素小于枢轴
//		A[low] = A[high];		//则将A[high]移到low所指的位置
//
//		//当low所指元素小于枢轴元素时
//		while (low<high && A[low] > pivot)
//			low++;				//low指针+1
//
//		//循环跳出，说明low所指元素大于枢轴
//		A[high] = A[low];		//则将A[low]移到high所指的位置
//	}
//
//	//上层while循环结束，说明排序表已划分完毕
//	//此时low和high重叠在一起，就让pivot枢轴元素填入其中
//	A[low] = pivot;
//	return low;					//返回low下标，即枢轴下标
//}
//
//
//
//
//void QuickSort(int A[], int low, int high)
//{
//	if (low < high)
//	{
//		int pivotpos = Partition(A, low, high);  
//		//使用Partition函数将排序表划分为左右两个子表
//		//并将用于划分的基准下标用pivotops接受
//		QuickSort(A, low, pivotpos - 1);       //对左半部分调用快速排序
//		QuickSort(A, pivotpos + 1, high);	   //对右半部分调用快速排序
//	}
//}
//



void counting_sort(int A[], int n)
{
	//1. 找到数组A中的最大值和最小值
	int max = A[0];
	int min = A[0];
	for (int i = 1; i < n; i++)
	{
		if (max < A[i])
			max = A[i];

		if (min > A[i])
			min = A[i];
	}

	//2. 创建计数数组
	int k = max - min + 1;
	int* C = (int*)calloc(k, sizeof(int));
	if (!C) 
	{
		printf("C 分配失败\n");
		exit(1);
	}
	//使用calloc开辟k个大小为int类型的内存空间，并将该内存空间初始化


	//3. 统计每个元素出现的次数
	for (int i = 1; i < n; i++)
		C[A[i] - min]++;


	//4. 将计数数组转化为累计数组
	for (int i = 0; i < k; i++)
		C[i] += C[i - 1];


	//5. 构建输出数组
	int* B = (int*)calloc(n, sizeof(int));
	if (!B) 
	{
		printf("B 分配失败\n");
		exit(1);
	}

	for (int i = n - 1; i >= 0; i--)
		B[--C[A[i] - min]] = A[i];



	//6. 将输出数组B拷贝回原数组A
	for (int i = 0; i < n; i++)
		A[i] = B[i];


	//7. 释放内存
	free(B);
	free(C);
}

int main()
{
	int A[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &A[i]);
	}
	counting_sort(A, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}