class Solution {
public:
    static const int N = 70 + 5;
    // dp[x][y1][y2]表示机器人1在位置(x, y1)，机器人2在位置(x, y2)，从此出发，能获得的最大的樱桃数
    // 转移：机器人1，机器人2可以走向哪儿
    // 时间复杂度：O(N ^ 3)
    int m, n, dp[N][N][N];
    int dfs(int x, int y1, int y2, const vector<vector<int>> &grid) {
        if (x == m) return 0;
        if (!(y1 >= 0 && y1 < n)) return 0;
        if (!(y2 >= 0 && y2 < n)) return 0;
        if (dp[x][y1][y2] != -1) return dp[x][y1][y2];

        int ret = 0, delt = (y1 == y2? grid[x][y1]: grid[x][y1] + grid[x][y2]);
        for (int delt1 = -1; delt1 <= 1; ++delt1) {
            for (int delt2 = -1; delt2 <= 1; ++delt2) {
                ret = std::max(ret, dfs(x + 1, y1 + delt1, y2 + delt2, grid) + delt);
            }
        }
        return dp[x][y1][y2] = ret;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        std::memset(dp, -1, sizeof dp);
        return dfs(0, 0, n - 1, grid);
    }
};