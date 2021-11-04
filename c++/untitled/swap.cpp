//
// Created by szy on 2021/10/22.
//

#include "swap.h"
//
// Created by szy on 2021/10/22.
//#include "iostream"
//
//using namespace std;

//函数的定义
void swap(int a, int b) {
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}