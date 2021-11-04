//
// Created by szy on 2021/10/21.
//
#include<iostream>

using namespace std;

int main() {
    int N = 0, K = 0, X = 0;
    cin >> N >> K;
    if ((N - 1) % (K - 1) == 0) {
        X = (N - 1) / (K - 1);
    } else {
        X = (N - 1) / (K - 1) + 1;
    }
    cout << X << endl;
    system("pause");
    return 0;
}

