class Solution {
public:
    static const int N = 1e3 + 5, MOD = 1e9 + 7;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    // dp[x][y]表示从（x，y）出发，路径严格递增，的方案数
    // DAG模型，不会出现环
    // 时间复杂度：每个位置最多更新一次，所以总的时间复杂度为O(m * n)
    
    int dp[N][N], m, n, ans;
    int dfs(int x, int y, const vector<vector<int>> &grid) {
        if (dp[x][y] != -1) return dp[x][y];
        int ret = 0;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] > grid[x][y]) {
                ret = (ret + dfs(newx, newy, grid)) % MOD;
            }
        }
        return dp[x][y] = ret + 1;
    }

    int countPaths(vector<vector<int>>& grid) {
        std::memset(dp, -1, sizeof dp);
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = (ans + dfs(i, j, grid)) % MOD;
        return ans;
    }
};