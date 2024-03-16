class Solution {
public:
    static const int N = 6 + 2;
    vector<vector<int>> ans;
    void dfs(set<int> vis, vector<int> v, const vector<int>& nums) {
        int n = nums.size();
        if (vis.size() == n) {
            ans.push_back(v);
            return ;
        }
        for (int i = 0; i < n; ++i) {
            if (vis.count(i) == 0) {
                auto newvis = vis;
                auto newv = v;
                newvis.insert(i);
                newv.push_back(nums[i]);
                dfs(newvis, newv, nums);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        set<int> vis;
        vector<int> v;
        dfs(vis, v, nums);
        return ans;
    }
};