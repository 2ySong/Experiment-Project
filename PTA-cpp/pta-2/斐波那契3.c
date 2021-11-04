/*已知斐波那契数列 Fn=Fn−1+Fn−2(n>=3),F 1=1,F2=1
*求解该数列的第n项，结果对998244353取模。
*/

//提示：提示：矩阵快速幂，unsigned long long的最大值：1844674407370955161（1.8e18）

#include<stdio.h>
#include<math.h>
#define Max 998244353


struct Matrix
{
	unsigned long long M[2][2];
    //数据类型要一致！！！！！我刚开始在pta上答案一直错误，
    // 就是因为把它定义成了int型数据，忽略了乘时数据会变大！！！！
};//结构体 矩阵。

struct Matrix mul(struct Matrix a,struct Matrix b)//矩阵相乘，返回值为矩阵 
{
	struct Matrix c;//创建新的矩阵来放矩阵相乘的结果 
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c.M[i][j]=0;//初始化新矩阵
			for(int k=0;k<2;k++)
			{
				c.M[i][j]=c.M[i][j]+a.M[i][k]*b.M[k][j];
				c.M[i][j]=c.M[i][j]%Max;//取模别忘了
			}
		}
	}
	return c;
 } 
//快速幂
struct Matrix qul(unsigned long long t,struct Matrix a) 
{
	struct Matrix res;
	//单位矩阵 
	res.M[0][0]=1;res.M[0][1]=0;
	res.M[1][0]=0;res.M[1][1]=1;
	while(t>0)
	{
		if(t%2) res=mul(res,a);
		a=mul(a,a);
		t=t/2;
	}
	return res;
}


int main()
{
	unsigned long long n,sum=0;
	scanf("%llu",&n);
	struct Matrix a;
    struct Matrix d;
	a.M[0][0]=1;
	a.M[0][1]=1;
	a.M[1][0]=1;
	a.M[1][1]=0;
	if(n==1||n==2) printf("1");
	else
	{
		d=qul(n-2,a);
		sum=(d.M[0][0]+d.M[0][1])%Max;
		printf("%llu",sum);
	}
		return 0;
}
