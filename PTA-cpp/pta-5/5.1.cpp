/**
 * @Author: Song-zy
 * @Date: 2021/11/22 16:06
 * @Description: 
 */
#include "iostream"
#include "cstdio"

using namespace std;

int max_len(int arr[], int l, int a) {
    int ans = 1;
    for (int i = a; i < l; i++) {
        if (arr[i] > arr[i + 1]) {
            ans++;
        } else {
            int ans_c = max_len(arr, l, i + 1);
            if (ans_c > ans) {
                return ans_c;
            }
        }
    }

    return ans;
}

int main() {
//    int num[1000] = {}, b, k = 0;
//    while (cin >> b) {
//        if (cin.get() == '\n')
//            break;
//        num[k] = b;
//        k++;
//    }//输入数组
//    for (int i = 0; i < k + 1; i++) {
//        cout << num[i] << endl;
//    }
    //求最长递减序列
    int arr[] = {389, 207, 155, 300, 299, 170, 158, 65};
    int len = sizeof(arr) / sizeof(arr[0]);
    int ans = max_len(arr, len, 0);
    cout << ans << endl;
    return 0;
}