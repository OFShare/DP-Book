class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> v, int sum, const int &k, const int &n) {
        // 剪枝
        if (v.size() > k || sum > n) return ;
        // 递归的边界
        if (v.size() == k && sum == n) {
            ans.push_back(v);
            return ;
        }
        // 枚举使用下一个数, v里的数字严格递增存放
        for (int num = v.back() + 1; num <= 9; ++num) {
            auto newv = v;
            newv.push_back(num);
            dfs(newv, sum + num, k, n);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        for (int num = 1; num <= 9; ++num) {
            vector<int> v = {num};
            dfs(v, num, k, n);
        }
        return ans;
    }
};