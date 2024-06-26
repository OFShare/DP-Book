/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */
 
class Solution {
public:
    static const int M = 31;
    int pw[M];
    map<array<int, 3>, int > dp;
    
    int dfs(int i, bool down, int jump, const int &k) {
        if (i >= k + 2) return 0;
        int delt = 0;
        if (i == k) delt = 1;
        if (dp.count({i, down, jump})) return dp[{i, down, jump}];
        
        int ret = dfs(i + pw[jump], 1, jump + 1, k);
        if (down && i != 0) {
            ret += dfs(i - 1, 0, jump, k);
        }
        return dp[{i, down, jump}] = ret + delt;
    }
    int waysToReachStair(int k) {
        pw[0] = 1;
        for (int i = 1; i < M; ++i) {
            pw[i] = pw[i - 1] * 2;
        }
        return dfs(1, 1, 0, k);
    }
};