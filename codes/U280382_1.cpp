/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

// dp[i][j]表示考虑前i种物品[1:i]，装进背包容量为j时（不一定非要装满），的最大价值
int N, V, dp[100 + 5][100 + 5];

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = 0; j <= V; ++j) {
            // 第i种物品选0件
            dp[i][j] = dp[i - 1][j];
            // 第i种物品选1，2，3，...，件
            for (int k = 1; k <= s; ++k) {
                if (j - k * v >= 0)
                   dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * v] + k * w);
                else
                    break;
            }
        }   
    }
    cout << dp[N][V] << "\n";
    return 0;
}