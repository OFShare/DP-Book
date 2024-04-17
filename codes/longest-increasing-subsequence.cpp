class Solution {
public:
    static const int N = 3e3 + 5;
    // dp[i]表示前i个元素[0: i], 以第i个元素结尾时，最长单调上升子序列长度
    int dp[N];
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};