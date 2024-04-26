class Solution {
public:
    // steal表示考虑前i个元素[0:i], 第i个元素偷时，的最大值
    // non_steal表示考虑前i个元素[0:i], 第i个元素不偷时，的最大值
    int rob(vector<int>& nums) {
        int n = nums.size(), steal = nums[0], non_steal = 0, ans = nums[0];
        for (int i = 1; i < n; ++i) {
            int new_steal = nums[i] + non_steal;
            int new_non_steal = std::max(non_steal, steal) + 0;

            ans = std::max({new_steal, new_non_steal});
            steal = std::move(new_steal);
            non_steal = std::move(new_non_steal);
        }
        return ans;
    }
};