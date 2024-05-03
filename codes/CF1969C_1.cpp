#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 3e5 + 5, K = 10 + 5, INF = 1e18;
// dp[i][j]表示前i个位置[1:i], 最多使用j次操作，的最小值
// 状态的转移：人人为我，枚举中点middle，再枚举左边端点off，即将[off, i]的区间每个数，都由a[middle]替换。
ll t, n, k, a[N], dp[N][K];

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j] + a[i];
                for (int middle = i; middle >= 1; --middle) {
                    if (i - middle > j) break;
                    for (int off = middle; off >= 1; --off) {
                        if (j - (i - off) < 0 || off - 1 < 0) break;
                        
                        dp[i][j] = std::min(dp[i][j], dp[off - 1][j - (i - off)] + a[middle] * (i - off + 1));
                    }
                }
            }
        }
        cout << dp[n][k] << "\n";
    }
    return 0;
}