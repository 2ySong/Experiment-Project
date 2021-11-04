//
// Created by szy on 2021/10/31.
//

#include <iostream>

#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int matrix1[10000][10000], matrix2[10000][10000], matrix3[10000][10000];

int main() {
    int n = 0;
    cout << "矩阵大小：";
    cin >> n;
    srand(unsigned(time(0)));//根据当前时间产生随机数种子
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix1[i][j] = rand() % 10;//将产生的随机数赋值给第一个矩阵元素
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix2[i][j] = rand() % 10;//将产生的随机数赋值给第二个矩阵元素
        }
    }

    clock_t sTime, eTime;//计算时间
    sTime = clock();
    //普通的矩阵乘法
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d = 0; d < n; d++) {
                matrix3[i][j] += matrix1[i][d] * matrix2[d][j];
            }
        }
    }
    eTime = clock();
    cout << "普通矩阵乘法消耗时间：" << eTime - sTime << endl;

    int piece = 1;
    while (piece != 0) {
        cout << "输入分块大小：";
        cin >> piece;
        if (piece > n) {
            cout << "输入错误" << endl;
            exit(0);
        }
        sTime = clock();
        //分块矩阵乘法
        for (int i = 0; i < n; i = i + piece) {
            for (int j = 0; j < n; j = j + piece) {
                for (int d = 0; d < n; d = d + piece) {
                    for (int i1 = i; i1 < i + piece; i1++) {
                        for (int j1 = j; j1 < j + piece; j1++) {
                            for (int d1 = d; d1 < d + piece; d1++) {
                                matrix3[i1][j1] += matrix1[i1][d1] * matrix2[d1][j1];
                            }
                        }
                    }
                }
            }
        }
        eTime = clock();
        cout << "分块矩阵乘法消耗时间：" << eTime - sTime << endl;
    }
    return 0;
}
