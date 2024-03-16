class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, vector<int> v, int sum, const vector<int>& candidates, const int &target) {
        // 递归的边界
        if (i == candidates.size()) {
            if (sum == target) ans.push_back(v);
            return ;
        }
        // 枚举第i个数选几个
        for (int cnt = 0; ; ++cnt) {
            if (sum + cnt * candidates[i] > target) break;
            vector<int> newv = v;
            for (int k = 0; k < cnt; ++k) newv.push_back(candidates[i]);
            dfs(i + 1, newv, sum + cnt * candidates[i], candidates, target);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(0, v, 0, candidates, target);
        return ans;
    }
};