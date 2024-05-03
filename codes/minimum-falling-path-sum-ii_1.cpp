class Solution {
public:
    // dp[i][j]表示从首行走到（第i行，第j列），的最小值
    // 转移：刷表法，走到下一行的第k列，当然k != j
    // 时间复杂度：状态数O(N * N) * 转移数O(N) = O(N ^ 3)
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; ++j) dp[j] = grid[0][j];

        for (int i = 0; i < n - 1; ++i) {
            vector<int> new_dp(n, 1e9);
            for (int j = 0; j < n; ++j) {
                // 第j例 -> 第k列
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        new_dp[k] = std::min(new_dp[k], dp[j] + grid[i + 1][k]);
                    }
                }
            }
            dp = std::move(new_dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};