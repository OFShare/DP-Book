class Solution {
public:
    static const int N = 50 + 5, INF = 1e9;
    int dp[N][N][2 * N], n;
    // 先从左上角走到右下角，再从右下角走到左上角，等价于，从左上角开始，有两个人同时走，最后走到右下角。
    // dp[x1][x2][step]表示从左上角开始，两人同时走，第一个人走到的位置为(x1, step - x1)，第二个人走到的位置为(x2, step - x2)时，的最大樱桃数
    // 转移：填表法 第一个人可以由上/左走过来，同理第二个人也可以由上/左走过来
    // 时间复杂度：O(N * N * N)
    
    int dfs(int x1, int x2, int step, const vector<vector<int>> &grid) {
        int y1 = step - x1, y2 = step - x2;
        if (!(x1 >= 0 && x1 < n) || !(y1 >= 0 && y1 < n)) return -INF;
        if (!(x2 >= 0 && x2 < n) || !(y2 >= 0 && y2 < n)) return -INF;
        if (grid[x1][y1] == -1 || grid[x2][y2] == -1) return -INF;
        if (x1 + y1 == 0 && x2 + y2 == 0) return grid[x1][y1];
        if (dp[x1][x2][step] != -1) return dp[x1][x2][step];
        
        int delt = 0, ret = -INF;
        if (x1 == x2 && y1 == y2) delt = grid[x1][y1];
        else delt = grid[x1][y1] + grid[x2][y2];

        // 上，上
        ret = std::max(ret, dfs(x1 - 1, x2 - 1, step - 1, grid) + delt);
        // 上，左
        ret = std::max(ret, dfs(x1 - 1, x2, step - 1, grid) + delt);
        // 左，上
        ret = std::max(ret, dfs(x1, x2 - 1, step - 1, grid) + delt);
        // 左，左
        ret = std::max(ret, dfs(x1, x2, step - 1, grid) + delt);
        return dp[x1][x2][step] = ret;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();

        std::memset(dp, -1, sizeof dp);
        int ret = dfs(n - 1, n - 1, n - 1 + n - 1, grid);
        return ret >= 0? ret: 0;
    }
};