#include <stdio.h>
int main()
{
    int N;
    double fenzi=2;
    double fenmu=1;
    double sum=0.0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        double item=fenzi/fenmu;//第i项
        sum+=item;
        fenzi=fenzi+fenmu;//表示下一项的分子
        fenmu=fenzi-fenmu;//表示下一项的分母
    }
    printf("%.2lf\n",sum);
    return 0;
}