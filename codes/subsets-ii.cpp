class Solution {
public:
    using MAP = std::map<int, int>;
    // <元素, 个数>
    MAP mp;
    vector<vector<int>> ans;
    void dfs(MAP::iterator it, vector<int> v) {
        if (it == mp.end()) {
            ans.push_back(v);
            return ;
        }
        // cnt 表示当前元素选几个
        for (int cnt = 0; cnt <= it -> second; ++cnt) {
            auto newv = v;
            auto newit = it;
            for (int i = 0; i < cnt; ++i) {
                newv.push_back(it -> first);
            }
            dfs(++newit, newv);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (auto &num: nums) mp[num] += 1;
        vector<int> v;
        dfs(mp.begin(), v);
        return ans;
    }
};