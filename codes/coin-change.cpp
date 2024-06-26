/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */
class Solution {
public:
    static const int N = 1e4 + 5, INF = 1e9;
    int dp[N];
    // dp[u]表示从总金额为u出发，所需的最少的硬币个数
    int dfs(int u, const vector<int> &coins) {
        if (u == 0) return 0;
        if (dp[u] != -1) return dp[u];
        int ret = INF;
        for (auto &c: coins) {
            if (u >= c) ret = std::min(ret, dfs(u - c, coins) + 1);
        }
        return dp[u] = ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        std::memset(dp, -1, sizeof dp);
        int ans = dfs(amount, coins);
        if (ans >= INF) return -1;
        return ans;
    }
};