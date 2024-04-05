class Solution {
public:
    int ans = 0;
    void dfs(int i, unordered_set<int> &v, const int &n) {
        if (i == n + 1) {
            ans += 1;
            return ;
        }
        // 枚举第i个位置填哪个数
        for (int num = 1; num <= n; ++num) {
            if (v.count(num) == 0 && (num % i == 0 || i % num == 0)) {
                v.insert(num);
                dfs(i + 1, v, n);
                v.erase(num);
            }
        }
    }
    int countArrangement(int n) {
        unordered_set<int> v;
        dfs(1, v, n);
        return ans;
    }
};