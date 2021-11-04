#include <stdio.h>
#include <stdlib.h>
int main()
{
   int n;   
   scanf("%d", &n);
   int a[n][n];
      for(int i = 0; i < n; i++){
             for(int j = 0; j < n; j++){
                        scanf("%d", &a[i][j]);
                        //printf("%3d ", a[i][j]);
                        }
             //puts("")；
   }
   int sum_1 = 0, sum_2 = 0;
   //puts("");
   int i, j;
   //printf("sum_1:\n");
   for (i = 0; i < n - 1; i++)
   {
        for (j = 0; j < n - i - 1; j++){
             sum_1 = sum_1 + a[i][j];
             //printf("%d\n", sum_1);                       
        }
   }
   //printf("%d\n", sum_1);
   //printf("sum_2:\n");
   if (n > 3){
       for (j = 2; j < n - 1; j++){
           for (i = n - j; i < n - 1; i++){
                sum_2 = sum_2 + a[i][j];               
                //printf("%d\n", sum_2);           
           }
       }
   }
   //printf("%d\n", sum_2);
   int sum = sum_2 + sum_1;
   printf("%d", sum);
   system("pause");
   return 0;
}
