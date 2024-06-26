/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *  做法： 完全背包问题
 *
 */

class Solution {
public:
    static const int N = 1e4 + 5, INF = 1e9;
    int dp[N];
    // dp[u]从整数u出发，恰好凑成u的，最少数量
    int dfs(int u, const vector<int> &coins) {
        if (u == 0) return 0;
        if (dp[u] != -1) return dp[u];

        int ret = INF;
        for (auto &c: coins) {
            if (u >= c) ret = std::min(ret, dfs(u - c, coins) + 1);
        }
        return dp[u] = ret;
    }
    int numSquares(int n) {
        vector<int> coins;
        for (int i = 1; 1LL * i * i <= n; ++i) {
            coins.push_back(i * i);
        }
        std::memset(dp, -1, sizeof dp);
        int ans = dfs(n, coins);
        return ans >= INF? 0: ans;
    }
};