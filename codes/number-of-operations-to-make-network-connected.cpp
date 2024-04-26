// 计算并返回使所有计算机都连通所需的最少操作次数?
// 如果边的个数大于等于n - 1, 肯定存在答案。
// 如果存在答案，答案显然就是联通块的个数减一，联通块的个数用dfs染色实现

class Solution {
public:
    using pii = std::pair<int, int>;
    static const int N = 1e5 + 5;
    vector<int> g[N];
    int c[N];
    // 从u节点开始，将其和它属于同一个联通块的所有节点都染色为color
    void dfs(int u, int color) {
        c[u] = color;
        for (auto &v: g[u]) {
            if (c[v] == 0) dfs(v, color);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;    
        for (auto &c: connections) {
            int u = c[0], v = c[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int color = 0;
        for (int i = 0; i < n; ++i) {
            if (c[i] == 0) {
                dfs(i, ++color);
            }
        }
        return color - 1;
    }
};