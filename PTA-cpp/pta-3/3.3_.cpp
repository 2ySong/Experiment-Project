//
// Created by szy on 2021/10/25.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int order[9];
char str[9];

void range(int l, int r) {
    int nexti = l + 1;
    for (int i = l + 1; i <= r; i++) {
        if (order[i] > order[l] && order[i] < order[nexti]) {
            nexti = i;
        }
    }//找到要和l交换的位置
    int temp;
    temp = order[l];
    order[l] = order[nexti];
    order[nexti] = temp;
    //完成order[l]位置
    for (int i = l + 1; i <= r; i++)
        for (int j = i; j <= r; j++) {
            if (order[i] > order[j]) {
                int tem;
                tem = order[i];
                order[i] = order[j];
                order[j] = tem;
            }
        }
    //对于后面的进行排序
}

void Initorder() {
    for (int i = 0; i < 9; i++)
        order[i] = i;
}

void Order(int n) {
    int end = n;
    while (order[end] < order[end - 1]) {
        end--;
    }//从末尾开始找第一个递增的 用end来保存
    end--;
    if (end < 1)
        return;
    range(end, n);//将end 开始到n的重新开始0排列
}

void output(int n) {
    for (int i = 1; i <= n; i++)
        printf("%c", str[order[i]]);
    Order(n);
}

int main() {
    int n;
    scanf("%s", str + 1);
    n = strlen(str + 1);
    Initorder();
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            if (str[i] > str[j]) {
                int tem;
                tem = str[i];
                str[i] = str[j];
                str[j] = tem;
            }
        }
    //按照字典序排列
    int time = 1;
    for (int i = 1; i <= n; i++)
        time *= i;
    while (time) {
        output(n);
        if (time - 1)
            printf("\n");
        time--;
    }
    printf("\n");
    return 0;
}
