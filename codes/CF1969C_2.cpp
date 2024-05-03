#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 3e5 + 5, K = 10 + 5, INF = 1e18;
// dp[i][j]表示前i个位置[1:i], 最多使用j次操作，的最小值
// 状态的转移：人人为我，枚举最后一段区间[off, i]，将区间[off, i]的每个数都替换成区间[off，i]内的最小值。
ll t, n, k, a[N], dp[N][K];

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j] + a[i];
                // 枚举最后一段区间[off，i]
                ll mi = a[i];
                for (int off = i; off >= 1; --off) {
                    if (j - (i - off) < 0) break;
                    mi = std::min(mi, a[off]);
                    dp[i][j] = std::min(dp[i][j], dp[off - 1][j - (i - off)] + mi * (i - off + 1));
                }
            }
        }
        cout << dp[n][k] << "\n";
    }
    return 0;
}