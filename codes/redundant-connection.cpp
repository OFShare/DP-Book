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
    static const int N = 1e3 + 5;
    vector<int> g[N];
    int vis[N];
    void dfs(int u, int &step, const int &U, const int &V) {
        vis[u] = 1;
        step += 1;
        for (auto &v: g[u]) {
            if (u == U && v == V) continue;
            if (u == V && v == U) continue;
            if (!vis[v]) dfs(v, step, U, V);
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto &c: edges) {
            int u = c[0], v = c[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // 枚举删除那条边，再dfs染色剩下的节点是否都联通
        int n = edges.size();
        for (int i = n - 1; i >= 0; --i) {
            std::memset(vis, 0, sizeof vis);
            int u = edges[i][0], v = edges[i][1];
            int step = 0;
            dfs(u, step, u, v);
            if (step == n) return edges[i];
        }
        return {};
    }
};