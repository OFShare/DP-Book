#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 3e5 + 5, K = 10 + 5, INF = 1e18;
// dp[i][j]表示前i个位置[1:i], 最多使用j次操作，的最小值
// 状态的转移：我为人人型递推，枚举下一段[i+1，m]，同时记录其最小值mi
ll t, n, k, a[N], dp[N][K];

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        // std::memset(dp, 0x3f, sizeof dp); 由于是多组数据，这样会TLE
        vector<vector<ll>> dp(n + 5, vector<ll>(k + 5, INF));
        for (int j = 0; j <= k; ++j) dp[0][j] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                // 枚举下一段[i+1，m], 同时记录其最小值mi
                ll mi = 1e9;
                for (int m = i + 1; ; ++m) {
                    if (m > n || j + m - i - 1 > k) break;
                    mi = std::min(mi, a[m]);

                    dp[m][j + m - i - 1] = std::min(dp[m][j + m - i - 1], dp[i][j] + mi * (m - i));
                }
            }
        }
        cout << dp[n][k] << "\n";
    }
    return 0;
}
