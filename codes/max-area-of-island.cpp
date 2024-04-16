class Solution {
public:
    static const int N = 50 + 5;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(int x, int y, int &area, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        area += 1;
        grid[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1) {
                dfs(newx, newy, area, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, area, grid);
                    ans = std::max(ans, area);
                }
            }
        }
        return ans;
    }
};