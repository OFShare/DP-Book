class Solution {
public:
    // pre_mx, 维护以第i个元素结尾的最大值
    // pre_mi, 维护以第i个元素结尾的最小值
    int maxAbsoluteSum(vector<int>& nums) {
        int pre_mx = 0, pre_mi = 0, ans = -1e9, n = nums.size();
        for (int i = 0; i < n; ++i) {
            pre_mx = std::max(nums[i], pre_mx + nums[i]);
            pre_mi = std::min(nums[i], pre_mi + nums[i]);
            ans = std::max({ans, std::abs(pre_mi), std::abs(pre_mx)});
        }
        return ans;
    }
};