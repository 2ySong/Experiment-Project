#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Max 10000
int Compare(const void* e1, const void* e2)//定义函数比较
{
	return (int)*((int*)e1) - (int)*((int*)e2);
}
 
int add(int a[], int n,int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += abs(a[i]-mid);
	}
	return sum;
}
 
int main()
{
	int x[Max] = { 0 }, y[Max] = { 0 };
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	qsort(x, n, sizeof(x[0]), Compare);
	qsort(y, n, sizeof(y[0]), Compare);
	for (i = 0; i < n; i++)//这是x轴上的坐标移动的最终位置，是根据公式求得的
	{
		x[i] = x[i] - i;
	}
	qsort(x, n, sizeof(x[0]), Compare);
	int Y_mid = y[n / 2], X_mid = x[n / 2];
	int y_sum = 0, x_sum = 0;
	y_sum = add(y, n, Y_mid);	
	x_sum = add(x, n, X_mid);
	printf("%d\n", x_sum + y_sum);
	return 0;
}