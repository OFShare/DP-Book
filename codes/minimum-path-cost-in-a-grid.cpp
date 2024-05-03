class Solution {
public:
    // dp[i][j]表示从首行出发，走到位置（第i行，第j列）结束时，的最小值
    // 转移：(i, j) -> (i + 1, k)，其中k = 0, 1, 2, ..., n-1
    // 时间复杂度: 状态数O(m * n) * 转移数O(n) = O(m * n ^ 2)
    
    const int INF = 1e9;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; ++j) dp[j] = grid[0][j];

        for (int i = 0; i < m - 1; ++i) {
            vector<int> new_dp(n, INF);
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j];
                for (int k = 0; k < n; ++k) {
                    new_dp[k] = std::min(new_dp[k], dp[j] + moveCost[num][k] + grid[i + 1][k]);
                }
            }
            dp = std::move(new_dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};