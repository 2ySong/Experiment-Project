/*已知斐波那契数列 Fn=Fn−1+Fn−2(n>=3),F1=1,F2=1
*用递归的思想求解第n项
*/
#include<stdio.h>
int fibonacci(int n)
{
    if(n==1 || n == 2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}
 
int main()
{
    int n;
    printf("hello");
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}