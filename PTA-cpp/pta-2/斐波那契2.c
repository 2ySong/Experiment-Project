/*已知斐波那契数列 Fn=Fn−1+Fn−2(n>=3),F 1=1,F2=1
*求解该数列的第n项，结果对998244353取模。
*/

#include<stdio.h>
#define N 998244353
 
int main()
{
    int n;
    int i;
    int num;
    int f1 = 1, f2 = 1;
    int fn;
 
    scanf("%d", &n);
    if(n==1 || n==2) num = 1;
    else{
        for(i=3; i<=n; i++){
            fn = (f1 + f2) % N;
            f2 = f1;
            f1 = fn;
        }
        num = fn;
    }
    
    printf("%d", num);
    return 0;
}