class Solution {
public:
    // vis[u] 的取值-1（从未被访问过）, 0（被访问过染色为白）, 1（被访问过染色为黑）
    int vis[105];
    // 从当前节点出发（当前节点染色为color），能否染色为二分图
    int dfs(int u, int color, const vector<vector<int>>& g) {
        vis[u] = color;
        for (auto &v: g[u]) {
            if (vis[v] == vis[u]) return 0;
            else if (vis[v] == -1 && !dfs(v, 1 - color, g)) return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        std::memset(vis, -1, sizeof vis);
        for (int i = 0; i < n; ++i)
            if (vis[i] == -1 && !dfs(i, 0, graph))
                return 0;
        return 1;
    }
};