class Solution {
public:
    static const int N = 2e3 + 5;
    vector<int> g[N];
    int color[N];
    // 状态的定义：从当前节点u出发且当前节点染色为c，能否二分图染色。
    // 状态的转移：尝试将节点u的相邻节点v，染色为1 - c。
    // 时间复杂度：每个节点只要被染色以后，从它出发的情况就定了，即每个节点最多访问一次，所以总的时间复杂度为O(V + E)
    int dfs(int u, int c) {
        color[u] = c;
        for (auto &v: g[u]) {
            if (color[v] == -1) {
                if (!dfs(v, 1 - c)) return 0;
            }
            else {
                if (color[u] == color[v]) return 0;
            }
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for (auto &c: dislikes) {
            int u = c[0], v = c[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        std::memset(color, -1, sizeof color);
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1 && !dfs(i, 0)) return 0;
        }
        return 1;
    }
};