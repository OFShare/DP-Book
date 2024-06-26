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
    static const int N = 100 + 5;
    vector<int> g[N];
    set<int> dp[N];

    set<int> dfs(int u) {
        if (!dp[u].empty()) return dp[u];
        set<int> ret = {u};
        for (auto &v: g[u]) {
            for (auto &c: dfs(v)) {
                ret.insert(c);
            }
        }
        return dp[u] = ret;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for (auto &c: prerequisites) {
            int u = c[0], v = c[1];
            g[u].push_back(v);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (dp[i].empty()) {
                dp[i] = dfs(i);
            }
        }

        vector<bool> ans;
        for (auto &c: queries) {
            int u = c[0], v = c[1];
            if (dp[u].count(v)) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};