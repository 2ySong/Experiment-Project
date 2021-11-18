/**
 * @Author: Song-zy
 * @Date: 2021/11/8 16:01
 * @Description: 
 */
#include <cstring>
#include <cmath>
#include "iostream"

using namespace std;

int main() {
    string text1;
    string text2;
    cin >> text1;
    cin >> text2;
    int m = text1.length(), n = text2.length();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));//将所有元素置0

    for (int i = 1; i <= m; i++) {
        char c1 = text1[i - 1];
        for (int j = 1; j <= n; j++) {
            char c2 = text2[j - 1];
            if (c1 == c2) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d", dp[m][n]);
    return 0;
}
