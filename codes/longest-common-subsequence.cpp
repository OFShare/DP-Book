class Solution {
public:
    static const int N = 1e3 + 5;
    int dp[N][N];

    // dp[i][j]：表示text1的前i个元素，text2的前j个元素，它们的最长的公共子序列的长度
    int dfs(int i, int j, const string &text1, const string &text2) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ret = 0;
        if (text1[i] == text2[j]) ret = std::max(ret, dfs(i - 1, j - 1, text1, text2) + 1);
        return dp[i][j] = std::max({ret, dfs(i - 1, j, text1, text2), dfs(i, j - 1, text1, text2)});
    }

    int longestCommonSubsequence(string text1, string text2) {
        std::memset(dp, -1, sizeof dp);
        return dfs(text1.size() - 1, text2.size() - 1, text1, text2);
    }
};