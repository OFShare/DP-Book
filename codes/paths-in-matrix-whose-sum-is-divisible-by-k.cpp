class Solution {
public:
    // dp[i][j][k]表示从起点（0，0）出发，走到（i，j）位置，路径和 %K 等于k时，的方案数。
    // 转移：刷表法，往下走或者往右走
    // 时间复杂度：状态数O(m * n * k) * 转移数O(1) = O(m * n * k)
    
    const int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(K, 0)));
        dp[0][0][grid[0][0] % K] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < K; ++k) {
                    // 往下走：(i, j, k) -> (i + 1, j, newk)
                    if (i + 1 < m) {
                        int newk = (k + grid[i + 1][j]) % K;
                        dp[i + 1][j][newk] = (dp[i + 1][j][newk] + dp[i][j][k]) % MOD;
                    }
                    // 往右走：(i, j, k) -> (i, j + 1, newk)
                    if (j + 1 < n) {
                        int newk = (k + grid[i][j + 1]) % K;
                        dp[i][j + 1][newk] = (dp[i][j + 1][newk] + dp[i][j][k]) % MOD;
                    }
                } 
            }
        }
        return dp[m - 1][n - 1][0];
    }
};