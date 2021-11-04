//
// Created by szy on 2021/10/25.
//
#include <iostream>
#include <algorithm>
#include<string.h>

using namespace std;

int main() {
    char num[9];
    cin >> num;
    int length = strlen(num);
    sort(num, num + length);
    do {
        for (int i = 0; i < length; i++)
            cout << num[i] << " ";
        cout << endl;
    } while (next_permutation(num, num + length));
    return 0;
}
