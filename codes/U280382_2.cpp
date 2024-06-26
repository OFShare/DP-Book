/*
 *
 *  欢迎阅读:
 *
 *  https://ofshare.github.io/
 *
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// dp[i][j]表示考虑前i种物品[1:i]，装进背包容量为j时（不一定非要装满），的最大价值
// cur始终指向当前考虑到了第几件物品，由于会拆分，cur并不等于i哟
int N, V, dp[2][20000 + 5], cur = 0;

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) {
        int v, w, s;
        cin >> v >> w >> s;

        // 二进制分解s
        int pre_sum = 0, b = 1;
        while (pre_sum + b <= s) {
            cur += 1;

            // 拆出b件
            for (int j = 0; j <= V; ++j) {
                // 不选
                dp[cur & 1][j] = dp[cur - 1 & 1][j];
                // 选
                if (j - v * b >= 0)
                    dp[cur & 1][j] = std::max(dp[cur & 1][j], dp[cur - 1 & 1][j - v * b] + w * b);
            }

            pre_sum += b;
            b *= 2;
        }

        int x = s - pre_sum;
        cur += 1;
        // 拆出x件
        for (int j = 0; j <= V; ++j) {
            // 不选
            dp[cur & 1][j] = dp[cur - 1 & 1][j];
            // 选
            if (j - v * x >= 0)
                dp[cur & 1][j] = std::max(dp[cur & 1][j], dp[cur - 1 & 1][j - v * x] + w * x);
        }
    }
    cout << dp[cur & 1][V] << "\n";
    return 0;
}