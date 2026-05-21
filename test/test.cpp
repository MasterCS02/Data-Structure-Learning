#include <stdio.h>
#include <math.h>

// typedef struct LinkNode
// {
// 	int data;
// 	struct LinkNode* next;
// }LinkNode,*LinkList;





int main()
{
	int i;
	int a=0,b=0,c=0;
	for(a=0;a<=1;a++)
	{
		for(b=0;b<=1;b++)
		{
			for(c=0;c<=1;c++)
			{
				if((b==0)+(c==0)+((a==0)||(b==0))==3)
				{
					if(a+b+c==1)
					{
						int arr1[3]={a,b,c};
						char arr2[]={'a','b','c','\0'};
						for(i=0;i<3;i++)
						{
							if(arr1[i]==1)
								printf("%c 说对了\n",arr2[i]);
						}
					}
				}
			}
		}
	}

}
