#include<stdio.h>
int main()
{
    int x = 0, z = 0;
    scanf("%d %d", &x, &z);
    // 问：为什么(x - z) * 100 / z;前面要加个double强制转换？
    // 答：因为x,z,100都是整数（int型），他们三的+-*/得到的结果也是整形，
    //     如果不转换会丢失精度，导致计算结果不准。
    double b = (double)(x - z) * 100 / z;
    if (b >=50)
    {
        printf("Exceed %.0f%%. License Revoked", b);
    }
    else if (b >= 10 && b < 50)
    {
        printf("Exceed %.0f%%. Ticket 200", b);
    }
    else if (b < 10)
    {
        printf("OK");
    }
    return 0;
}