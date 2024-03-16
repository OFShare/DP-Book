class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> v, const int &n, const int &k) {
        if (v.size() > k) return ;
        if (v.size() == k) ans.push_back(v);
        for (int num = v.back() + 1; num <= n; ++num) {
            auto newv = v;
            newv.push_back(num);
            dfs(newv, n, k);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        for (int num = 1; num <= n; ++num) {
            vector<int> v = {num};
            dfs(v, n, k);
        }
        return ans;
    }
};