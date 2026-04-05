#include <stdio.h>
#include <math.h>

//lnab=lna+lnb
// 
//double fun(int m)
//{
//	int i;
//	double s;
//	double mul = 1.0;
//	for (i = 1; i <= m; i++)
//	{
//		mul *= i;
//	}
//	s = log(mul);
//	return sqrt(s);
//}


//累加
double fun(int m)
{
	int i;
	double add = 0.0;

	for (i = 1; i <= m; i++)
	{
		add += log((double)i);
	}

	return sqrt(add);
}



int main()
{
	double s = fun(20);
	printf("%lf\n", s);
	return 0;
}
