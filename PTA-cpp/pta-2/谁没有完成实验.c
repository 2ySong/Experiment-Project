#include<stdio.h>
#include<stdlib.h>

#define Max 1000000

int main()
{
    int n;
    int ai[Max] = {0};
    scanf("%d",&n);
    // int ai[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&ai[i]);
    }

    int m;
    scanf("%d",&m);
    int stu[Max] = {0} ;
    for (int i = 0; i < m; i++) {
        scanf("%d",&stu[i]);
    }

    int index[Max] = {0};
    for (int i = 0; i < m; i++) {
        index[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(stu[i]==ai[j]){
                index[i] = j;
            }
        }

    }
    for (int j = 0; j < m; j++) {
        if(index[j]!=-1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    // for (int i = 0; i < m; i++)
	// {
	// 	if (ai[stu[i]] != 0)
	// 	{
	// 		printf("Yes\n");
	// 	}
	// 	else
	// 	{
	// 		printf("No\n");
	// 	}
	// }
    return 0;
}