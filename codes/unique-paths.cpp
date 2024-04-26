class Solution {
public:
    static const int N = 1e2 + 5;
    // dp[m][n]表示从左上角走到以（m, n）结束时，的不同的路径数
    int dp[N][N];
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (m == 1 && n == 1) return 1;
        if (dp[m][n] != 0) return dp[m][n];
        return dp[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};