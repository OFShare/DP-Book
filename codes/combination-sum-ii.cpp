class Solution {
public:
    static const int N = 50 + 5;
    vector<vector<int>> ans;
    // 记录每个数出现的个数, <值，个数>
    int a[N];
    void dfs(int i, vector<int> v, int sum, const int &target) {
        if (i >= N) {
            if (sum == target) ans.push_back(v);
            return ;
        }
        // 枚举第i个数选了多少个
        for (int cnt = 0; cnt <= a[i]; ++cnt) {
            if (sum + cnt * i > target) break;
            vector<int> newv = v;
            for (int k = 0; k < cnt; ++k) newv.push_back(i);
            dfs(i + 1, newv, sum + cnt * i, target);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto &c: candidates) a[c] += 1;
        vector<int> v;
        dfs(0, v, 0, target);
        return ans;
    }
};