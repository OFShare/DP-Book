class Solution {
public:
    static const int N = 20 + 5;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    // space统计必须要走的方格数，(sx, sy)表示起点坐标，(ex, ey)表示终点坐标
    int space, sx, sy, ex, ey, n, m;
    int vis[N][N], ans;
    // 状态<x, y, step, vis>表示从起点(sx, sy)走到当前节点(x, y)时，已经走了step步，已经访问过的节点保存在vis里（并不包含当前节点）
    void dfs(int x, int y, int step, const vector<vector<int>>& grid) {
        if (x == ex && y == ey) {
            if (step + 1 == space) ans += 1;
            return ;
        }
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && vis[newx][newy] == 0 && grid[newx][newy] != -1) {
                vis[x][y] = 1;
                dfs(newx, newy, step + 1, grid);
                vis[x][y] = 0;
            }
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != -1) space += 1;
                if (grid[i][j] == 1) sx = i, sy = j;
                if (grid[i][j] == 2) ex = i, ey = j;
            }
        }

        dfs(sx, sy, 0, grid);
        return ans;
    }
};