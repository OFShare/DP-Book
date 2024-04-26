class Solution {
public:
    using pii = std::pair<int, int>;
    static const int N = 1e2 + 5;
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int color[N][N];
    // mp保存的是，染色为1的所有位置坐标，染色为2的所有位置坐标
    // 然后枚举染色1和染色2的最短距离，即为答案。（虽然能过，但是正解应该是，将染色为1的所有坐标放进队列里，然后bfs最短路搜索直到碰到染色为2的停止
    // （这种将多个源点放进队列里进行最短路bfs，就是大家常说的多源最短路
    std::unordered_map<int, vector<pii> > mp;

    void dfs(int x, int y, const int &c, const vector<vector<int>>& grid) {
        int n = grid.size();
        color[x][y] = c;
        mp[c].push_back({x, y});
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < n && color[newx][newy] == 0 && grid[newx][newy] == 1) {
                dfs(newx, newy, c, grid);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), c = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (color[i][j] == 0 && grid[i][j] == 1) {
                    dfs(i, j, ++c, grid);
                }
            }
        }
        assert(c == 2);
        int ans = n * n;9
        for (auto &c1: mp[1]) {
            for (auto &c2: mp[2]) {
                ans = std::min(ans, std::abs(c1.first - c2.first) + std::abs(c1.second - c2.second) - 1);
            }
        }
        return ans;
    }
};