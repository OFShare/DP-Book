class Solution {
public:
    // pre_mx表示考虑前i元素[0:i], 以第i元素结尾，的最大值
    // pre_mi表示考虑前i元素[0:i], 以第i元素结尾，的最小值
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], pre_mx = nums[0], pre_mi = nums[0];
        for (int i = 1; i < n; ++i) {
            int newpre_mx = std::max({nums[i], pre_mx * nums[i], pre_mi * nums[i]});
            int newpre_mi = std::min({nums[i], pre_mx * nums[i], pre_mi * nums[i]});
            ans = std::max({ans, newpre_mx, newpre_mi});

            pre_mx = std::move(newpre_mx);
            pre_mi = std::move(newpre_mi);
        }
        return ans;
    }
};