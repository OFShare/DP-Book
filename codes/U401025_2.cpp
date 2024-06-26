#include <bits/stdc++.h>
using namespace std;

// dp[i][j]表示考虑前i种物品[1:i]，装进容量为j的背包，能获得最大价值
int N, V, w[1000 + 5], c[1000 + 5], dp[2][100000 + 5];

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) cin >> w[i] >> c[i];

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            // 第i件物品选0件
            dp[i & 1][j] = dp[i - 1 & 1][j];
            // 第i件物品'加选一件'（其实包含了：选1件，选2件，选3件，...）
            if (j - w[i] >= 0)
                dp[i & 1][j] = std::max(dp[i & 1][j], dp[i & 1][j - w[i]] + c[i]);
        }
    }
    cout << dp[N & 1][V] << "\n";
    return 0;
}