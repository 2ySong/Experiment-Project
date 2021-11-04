/*
@Author:Song-zy
@Description:子序列的平均值
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,k;
	float average=0.0;
	int First=0,Final=0;
	int arr[]={1,12,-5,-6,50,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("请输入子数组长度:\n");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		First+=arr[i];
		Final=First;
	}
	for(i=k;i<n;++i)
	{
		First+=arr[i]-arr[i-k];
		Final=max(First,Final);
	}
	average=(double)Final/k;
	printf("%1.2f\n",average);
	system("pause");
	return 0;
}

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
