class Solution {
public:
    // dp[i]表示已第i个元素结尾的连续最大和
    // 由于dp[i]只和dp[i - 1]有关, 所以可以滚动，用一个变量pre表示dp[i - 1]的状态就行
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), pre = 0, ans = -1e9;
        for (int i = 0; i < n; ++i) {
            pre = std::max(nums[i], pre + nums[i]);
            ans = std::max(ans, pre);
        }
        return ans;
    }
}; 