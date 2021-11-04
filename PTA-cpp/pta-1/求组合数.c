#include <stdio.h>
double fact(int n)
{
    int s;
    if(n>1) return n*fact(n-1);
    if(n==1||n==0) return 1;
}

int main()
{
    int m,n;
    double a,b;
    scanf("%d %d",&m,&n);
    a=fact(n);
    b=fact(m)*fact(n-m);
    printf("result = %.0f",a/b);
}