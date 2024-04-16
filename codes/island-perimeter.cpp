class Solution {
public:
    static const int N = 1e2 + 5;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int perimeter = 0, vis[N][N];
    void dfs(int x, int y, const vector<vector<int>>& grid) {
        // 一块陆地格子有4条边，每接触一个相邻陆地格子，少一条边
        int edge = 4, row = grid.size(), col = grid[0].size();
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < row && newy >= 0 && newy < col && grid[newx][newy] == 1 && vis[newx][newy] == 0) {
                dfs(newx, newy, grid);
            }
            if (newx >= 0 && newx < row && newy >= 0 && newy < col && grid[newx][newy] == 1) {
                edge -= 1;
            }
        }
        perimeter += edge;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};