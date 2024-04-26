class Solution {
public:
    static const int N = 2e2 + 5;
    int dp[N][N];
    // dp[m][n]表示以(m, n)坐标结束时，路径数字和的最小值
    int dfs(int m, int n, const vector<vector<int>>& grid) {
        if (m == 0 && n == 0) return grid[0][0];
        if (m < 0 || n < 0) return 1e9;
        if (dp[m][n] != -1) return dp[m][n];
        return  dp[m][n] = std::min(dfs(m - 1, n, grid), dfs(m, n - 1, grid)) + grid[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        std::memset(dp, -1, sizeof dp);
        return dfs(m - 1, n - 1, grid);
    }
};