#include <stdio.h>
int main()
{
    float x,y;
    // printf("plese input x:");
    scanf("%f",&x);
    if(x==10)
    y=1/x;
    else
    y=x;
    printf("f(" "%.1f" ")=" "%.1f",x,y);
}