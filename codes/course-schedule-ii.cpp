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
    static const int N = 2e3 + 5;
    vector<int> g[N];
    // -1(已访问过), 0(从未访问过), 1(正在访问ing)
    int vis[N];
    vector<int> ans;
    int dfs(int u) {
        assert(vis[u] == 0);
        vis[u] = 1;
        int found_circle = 0;
        for (auto &v: g[u]) {
            if ((vis[v] == 0 && dfs(v)) || vis[v] == 1) return found_circle = 1;
        }
        vis[u] = -1;
        ans.push_back(u);
        return found_circle = 0;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto &c: prerequisites) {
            int u = c[1], v = c[0];
            g[u].push_back(v);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (vis[i] == 0 && dfs(i)) return {};
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};