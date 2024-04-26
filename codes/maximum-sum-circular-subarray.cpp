class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), pre = 0, ans = -1e9;
        // 情况一：单独的某一段，为答案
        for (int i = 0; i < n; ++i) {
            pre = std::max(nums[i], pre + nums[i]);
            ans = std::max(ans, pre);
        }
        // 预处理dp, dp[i]表示[0: i]范围内，前缀和的最大值
        int s = nums[0];
        vector<int> dp(n + 5, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            s += nums[i];
            dp[i] = std::max(dp[i - 1], s);
        }
        // 情况二：开头的一段 + 末尾的一段，为答案
        s = 0;
        for (int i = n - 1; i >= 1; --i) {
            s += nums[i];
            ans = std::max(ans, dp[i - 1] + s);
        }
        return ans;
    }
};