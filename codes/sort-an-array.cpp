class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 边界
        if (nums.size() <= 1) return nums;
        int n = nums.size();
        vector<int> left, right;
        for (int i = 0; i < n / 2; ++i) left.push_back(nums[i]);
        for (int i = n / 2; i < n; ++i) right.push_back(nums[i]);
        
        left = sortArray(left);
        right = sortArray(right);

        vector<int> ans;
        int i = 0, j = 0;
        while (1) {
            if (i >= left.size() && j >= right.size()) break;
            int mi = 1e9;
            if (i < left.size()) mi = std::min(mi, left[i]);
            if (j < right.size()) mi = std::min(mi, right[j]);
            ans.push_back(mi);

            if (i < left.size() && mi == left[i]) ++i;
            else ++j;
        }
        return ans;
    }
};