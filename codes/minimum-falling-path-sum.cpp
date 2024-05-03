class Solution {
public:
    // dp[i][j]表示从首行出发，走到位置（第i行，第j列）结束时，的最小值
    // 转移：(i, j) -> (i + 1, j + delt)，其中delt = {-1, 0, 1}
    
    const int INF = 1e9;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; ++j) dp[j] = matrix[0][j];

        for (int i = 0; i < n - 1; ++i) {
            vector<int> new_dp(n, INF);
            for (int j = 0; j < n; ++j) {
                // -1, 0, 1
                for (int delt = -1; delt <= 1; ++delt) {
                    if (j + delt >= 0 && j + delt < n)
                        new_dp[j + delt] = std::min(new_dp[j + delt], dp[j] + matrix[i + 1][j + delt]);
                }
            }
            dp = std::move(new_dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};