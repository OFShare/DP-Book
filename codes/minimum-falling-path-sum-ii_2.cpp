class Solution {
public:
    static const int INF = 1e9;
    // dp[i][j]表示从首行走到（第i行，第j列），的最小值
    // 转移：填表法，由（上一行某一列）的最小值转移而来，由于（上一行某一列）的最小值可能和当前位置同列，所以也需要记录上一行的次小值
    // 时间复杂度：状态数O(N * N) * 转移数O(1) = O(N ^ 2)
    // mi1, mi2 分别记录最小值和次小值
    // mi1_index, mi2_index 分别记录最小值index和次小值index

    int n, mi1 = INF, mi2 = -1, mi1_index = INF, mi2_index = -1;
    void update(int value, int j) {
        if (value < mi1) {
            mi2 = mi1; mi2_index = mi1_index;
            mi1 = value, mi1_index = j;
        }
        else if (value < mi2) {
            mi2 = value, mi2_index = j;
        }
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; ++j) {
            dp[j] = grid[0][j];
            update(dp[j], j);
        }
        for (int i = 1; i < n; ++i) {
            vector<int> new_dp(n, 0);
            // 计算第i行，第j列，的new_dp值
            for (int j = 0; j < n; ++j) new_dp[j] = (mi1_index != j? mi1: mi2) + grid[i][j];
            // 重新更新第i行的, mi1, mi2
            mi1 = mi2 = INF;
            for (int j = 0; j < n; ++j) update(new_dp[j], j);
            // move
            dp = std::move(new_dp);
        }
        
        assert(*min_element(dp.begin(), dp.end()) == mi1);
        return mi1;
    }
};