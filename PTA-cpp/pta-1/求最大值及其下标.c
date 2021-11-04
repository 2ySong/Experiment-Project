#include<stdio.h>
int main(){
  int a[11], n, i, index;
  scanf("%d", &n);
  for(i = 0; i < n; i++){  //将输入数依次赋给数组a的n个元素；
    scanf("%d", &a[i]);
  }
  index = 0;              //假设a[0]为最大值，index存储最大值下标；
  for(i = 1; i < n; i++){
    if(a[i] > a[index]){   //如果a[i]比假设的的最大值还大，
      index = i;           //再假设a[i]是新的最大值；
    }
  }
  printf("%d %d", a[index], index);//打印出最大值以及最大值对应的下标
  return 0;
}