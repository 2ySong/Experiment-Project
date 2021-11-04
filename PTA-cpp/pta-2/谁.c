#include<stdio.h>
unsigned char students[1000010];
int main()
{
    int N,M;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        int v;
        scanf("%d",&v);
        students[v]=1;
    }
    scanf("%d",&M);
    
     for(int i=0;i<M;i++)
    {
        int y;
        scanf("%d",&y);
        if(students[y]==1)
            printf("Yes\n");
         else
             printf("No\n");
    }
    return 0;
}
