/*
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *  总的做法：要求最大数字，先转换为数位最长的长度（完全背包DAG模型），再在长度一样的时候贪心选取较大的高位
 *
 */

class Solution {
public:
    static const int N = 5e3 + 5, INF = 1e9;
    int dp[N];
    // dp[u]表示从成本u出发，恰好使用完成本，最多能选的数字个数
    int dfs(int u, const vector<int> &cost) {
        if (u == 0) return 0;
        if (dp[u] != -1) return dp[u];

        int ret = -INF;
        for (auto &c: cost) {
            if (u >= c) ret = std::max(ret, dfs(u - c, cost) + 1);
        }
        return dp[u] = ret;
    }

    // 在长度选取一样的前提下，贪心的选取较大的高位
    string print(int u, const vector<int> &cost) {
        if (u == 0) return "";
        for (int i = 8; i >= 0; --i) {
            if (u >= cost[i]) {
                if (dfs(u, cost) == dfs(u - cost[i], cost) + 1) {
                    return std::to_string(i + 1) + print(u - cost[i], cost);
                }
            }
        }
        assert(0);
        return "";
    }
    string largestNumber(vector<int>& cost, int target) {
        std::memset(dp, -1, sizeof dp);
        int mx_len = dfs(target, cost);
        if (mx_len <= 0) return "0";

        return print(target, cost);
    }
};