/**
 * @Author: Song-zy
 * @Date: 2021/11/22 20:02
 * @Description: 
 */
#include "iostream"

using namespace std;

int main() {
    int num[1000] = {}, b, k = 0;
    while (cin >> b) {
        num[k] = b;
        if (cin.get() == '\n')
            break;
        k++;
    }//输入数组
    for (int i = 0; i < k + 1; i++) {
        cout << num[i] << endl;
    }
    return 0;
}
