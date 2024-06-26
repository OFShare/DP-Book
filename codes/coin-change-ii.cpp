/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */
 
class Solution {
public:
    // 完全背包：dp[i][j]表示前i个物品[0:i]，恰好凑成面额为j的金额时，的方案数
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 5, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            vector<int> new_dp = dp;
            for (int j = 0; j <= amount; ++j) {
                // 第i个物品选0件
                new_dp[j] = dp[j];
                // 第i个物品'加选'1件
                if (j - coins[i] >= 0)
                    new_dp[j] += new_dp[j - coins[i]];
            }
            dp = std::move(new_dp);
        }
        return dp[amount];
    }
};