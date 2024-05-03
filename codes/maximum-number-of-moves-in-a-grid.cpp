class Solution {
public:
    // dp[i][j]表示从第一列出发，走到位置（第i行，第j列）结束时，移动的最大次数
    // 转移：刷表法（i，j）-> (i + delt, j + 1)，其中delt等于-1, 0, 1。也就是题目描述的转移方式
    const int INF = 1e9;
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> dp(m, 0);

        for (int j = 0; j < n - 1; ++j) {
            vector<int> new_dp(m, -INF);
            for (int i = 0; i < m; ++i) {
                // i - 1, i - 0, i + 1三个位置
                for (int delt = -1; delt <= 1; ++delt) {
                    if (i + delt >= 0 && i + delt < m && grid[i + delt][j + 1] > grid[i][j]) {
                        new_dp[i + delt] = std::max(new_dp[i + delt], dp[i] + 1);
                    } 
                }
            }

            dp = std::move(new_dp);
            ans = std::max(ans, *max_element(dp.begin(), dp.end()));
        }
        return ans;
    }
};