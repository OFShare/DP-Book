#include <bits/stdc++.h>
using namespace std;

// dp[i][j]表示考虑前i种物品[1:i]，装进容量为j的背包（不一定非要装满），能获得最大价值
int V, N, dp[1000 + 5][1000 + 5];

int main() {
    cin >> V >> N;
    for (int i = 1; i <= N; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = 0; j <= V; ++j) {
            // 第i种物品不选
            dp[i][j] = dp[i - 1][j] + 0;
            // 第i种物品选
            if (j - v >= 0)
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - v] + w);
        }
    }
    cout << dp[N][V] << "\n";
    return 0;
}