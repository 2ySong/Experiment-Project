//
// Created by szy on 2021/10/25.
//

#include <list>
#include <vector>
#include "iostream"

using namespace std;

int main() {
    int T = 0;//数据组数
    cin >> T;
    int arr[T];//数据组数存到数组中
    while (T--) {
        int n = 0;
        cin >> n;//对于每组数据，第一行一个n，代表文章中单词的个数，其后n行每行一个只包含小写字母的长度为1到10的字符串
        for (int i = 0; i < T; i++) {
            arr[i] = n;
        }
        string vec[n];

        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            vec[i] = str;
        }
//        for (string s: vec) {
//            cout << s << " ";
//        }
        int k[n];
        for (int i = 0; i < n; i++) {
            k[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (vec[i] == vec[j]) {
                    k[i]++;
                    vec[j] = "";
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (vec[i]!="")
                cout << vec[i] << " " << k[i] + 1 << endl;
        }
    }
    return 0;
}