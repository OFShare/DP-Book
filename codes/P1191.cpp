#include <bits/stdc++.h>
using namespace std;

const int N = 150 + 5;
// up[i][j]表示从（i, j）位置向上连续'W'的个数
int n, a[N][N], up[N][N], ans = 0;

// 枚举上边界，下边界，再跑一遍类似最大子段和，时间复杂度O(N ^ 3)
// 其实不用枚举上边界？这样时间复杂度降为O(N ^ 2)
// 强化版：https://www.luogu.com.cn/problem/P3400

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        for (int j = 1; j <= str.size(); ++j) {
            if (str[j - 1] == 'W') a[i][j] = 1;
            else a[i][j] = 0; 
            
            if (a[i][j] == 1) up[i][j] = up[i - 1][j] + a[i][j];
            else up[i][j] = 0;
            // cout << "i: " << i << " j; " << j << " " << up[i][j] << endl;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int pre = 0;
            for (int k = 1; k <= n; ++k) {
                if (up[j][k] >= j - i + 1) pre += 1;
                else pre = 0;

                ans += pre;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}