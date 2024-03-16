class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, vector<int> v, const vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(v);
            return ;
        }
        // 不选第i个数
        dfs(i + 1, v, nums);
        // 选第i个数
        v.push_back(nums[i]);
        dfs(i + 1, v, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(0, v, nums);
        return ans;
    }
};