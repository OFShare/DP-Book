class Solution {
public:
    static const int N = 50 + 5;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int vis[N][N];
    void dfs(int x, int y, int value, int color, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), border = 0;
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i], newy = y + dy[i];
            // 判断(x, y)是否在边界上
            if (!(newx >= 0 && newx < m && newy >= 0 && newy < n)) border = 1;
            if ((newx >= 0 && newx < m && newy >= 0 && newy < n) && vis[newx][newy] == 0 && grid[newx][newy] != value) border = 1;
            if (border) grid[x][y] = color;

            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == value && vis[newx][newy] == 0) {
                dfs(newx, newy, value, color, grid);
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if (grid[row][col] == color) return grid;
        int m = grid.size(), n = grid[0].size();
        dfs(row, col, grid[row][col], color, grid);
        return grid;
    }
};