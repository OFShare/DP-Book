class Solution {
public:
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(int x, int y, vector<vector<int>>& image, const int value, const int &color) {
        int m = image.size(), n = image[0].size();
        image[x][y] = color;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && image[newx][newy] == value) {
                dfs(newx, newy, image, value, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        dfs(sr, sc, image, image[sr][sc], color);
        return image;   
    }
};