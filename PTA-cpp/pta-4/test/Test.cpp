#include <stdio.h>
#include <math.h>

#define BE(x)  2*x*x*x
#define AA   1
#define B    3
#define ROW(x)    2*x*x

int main() {
    int a = 2, b = 3, c, d;
    float x, y, z;
    char st;
    c = BE(++a);
    d = ROW(b + 1);
    x = 3.14159 / 4;
    y = sin(x) + cos(x);
    st = 'B' + 2;
    printf("\nc=%d,a=%d,d=%d,AA=%d,y=%4.3f,s=%d\n", c, a, d, AA, y, st);
}