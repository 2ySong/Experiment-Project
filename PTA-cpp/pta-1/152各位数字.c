#include <stdio.h>
int main()
{
  int a,b,c;
  a=152%10;
  b=(152%100)/10;
  c=152/100;
  printf("152 = %d + %d*10 + %d*100\n",a,b,c);
  return 0;
}