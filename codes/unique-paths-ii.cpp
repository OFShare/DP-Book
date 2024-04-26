class Solution {
public:
    static const int N = 1e2 + 5;
    // dp[m][n]表示从左上角走到以（m, n）结束时，的不同的路径数
    int dp[N][N];
    int uniquePaths(int m, int n, const vector<vector<int>>& obstacleGrid) {
        if (m < 0 || n < 0 || obstacleGrid[m][n] == 1) return 0;
        if (m == 0 && n == 0) return 1;
        if (dp[m][n] != 0) return dp[m][n];
        return dp[m][n] = uniquePaths(m - 1, n, obstacleGrid) + uniquePaths(m, n - 1, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() - 1, n = obstacleGrid[0].size() - 1;
        return uniquePaths(m, n, obstacleGrid);
    }
};