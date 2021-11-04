#include <stdio.h>
#include <string.h>
struct Book
{
    double price;
    char name[31];
} book;
 
int main()
{
    int n;
    char c;
    scanf("%d",&n);//读取n之后缓冲区的内容："\n"
    struct Book book[n];
 
    int i,max = 0,min = 0;
    for(i=0; i<n; i++)
    {
        scanf("%c",&c);//读入缓冲区的"\n"
        gets(book[i].name);
        scanf("%lf",&book[i].price);
        if(book[i].price>book[max].price)
        {
            max = i;
        }
        if(book[i].price<book[min].price)
        {
            min = i;
        }
    }
    printf("%.2lf, %s\n",book[max].price,book[max].name);
    printf("%.2lf, %s\n",book[min].price,book[min].name);
    return 0;
}