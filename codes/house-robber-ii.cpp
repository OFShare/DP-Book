class Solution {
public:
    const int INF = 1e9;
    // steal表示考虑前i个元素[0:i], 第i个元素偷时，的最大值
    // non_steal表示考虑前i个元素[0:i], 第i个元素不偷时，的最大值
    // flag = 1, 表示偷了首元素; flag = 0, 表示没有偷首元素。是否偷了首元素，只有在考虑末尾元素时，才有用处（处理首尾相连的情况）。
    int robbb(int steal, int non_steal, int flag, const vector<int>& nums) {
        int n = nums.size(), ans = std::max({steal, non_steal});
        for (int i = 1; i < n; ++i) {
            int new_steal = -INF, new_non_steal = -INF;
            if (!(i == n - 1 && flag == 1)) new_steal = nums[i] + non_steal;
            new_non_steal = std::max(non_steal, steal) + 0;

            ans = std::max({new_steal, new_non_steal});
            steal = std::move(new_steal);
            non_steal = std::move(new_non_steal);
        }
        return ans;
    }

    int rob(vector<int>& nums) {
        return std::max(robbb(nums[0], 0, 1, nums), robbb(0, 0, 0, nums));
    }
};