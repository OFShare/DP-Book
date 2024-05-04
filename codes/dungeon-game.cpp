class Solution {
public:
    // f(i，j)表示从右下角出发，走到（i，j）位置时，的最低健康点数，并不包含dungeon[i][j]
    const int INF = 1e9;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > dp(m, vector<int>(n, INF));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // 向上走
                if (i - 1 >= 0) {
                    dp[i - 1][j] = std::min(dp[i - 1][j], dp[i][j] - dungeon[i][j]);
                    // 保证健康点数为一个正整数
                    if (dp[i - 1][j] <= 0) dp[i - 1][j] = 1;
                }
                
                // 向左走
                if (j - 1 >= 0) {
                    dp[i][j - 1] = std::min(dp[i][j - 1], dp[i][j] - dungeon[i][j]);
                    // 保证健康点数为一个正整数
                    if (dp[i][j - 1] <= 0) dp[i][j - 1] = 1;
                }
                
            }
        }
        return std::max(1, dp[0][0] - dungeon[0][0]);
    }
};