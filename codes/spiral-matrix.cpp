class Solution {
public:
    static const int N = 10 + 5;
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    int vis[N][N];
    vector<int> ans;
    // 螺旋是向内旋转的，维护的状态是(x, y, dir)以及vis，不过vis是全局的，并没写在dfs函数的参数列表里
    // (x, y, dir)记录走到当前位置（x, y）时，来时的方向dir。下一个走的位置肯定优先沿着来时的方向。
    // vis记录每个位置是否被访问过，每个坐标最多被访问一次，所以总的时间复杂度为O(M * N)
    void dfs(int x, int y, int dir, const vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vis[x][y] = 1;
        ans.push_back(matrix[x][y]);
        for (int i = dir; i < dir + 4; ++i) {
            int newx = x + dx[i % 4], newy = y + dy[i % 4];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                if (vis[newx][newy] == 0) {
                    dfs(newx, newy, i % 4, matrix);
                }
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dfs(0, 0, 0, matrix);
        return ans;
    }
};