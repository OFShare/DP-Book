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
    /*
        做法：枚举点 u，然后 BFS，在BFS的过程中，如果发现有两条路径都到达了 v，更新答案
        代码里vector<int> fa记录，节点u的来时的节点
    */
    static const int N = 1e3 + 5, INF = 1e9;
    vector<int> g[N];
    int bfs(int source, const int &n) {
        vector<int> d(n + 5, -1);
        vector<int> fa(n + 5, -1);
        queue<int> que;
        que.push(source);
        d[source] = 0;

        int ret = INF;
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (auto &v: g[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    que.push(v);
                    fa[v] = u;
                }
                else if (v != fa[u]) {
                    ret = std::min(ret, d[u] + d[v] + 1);
                }
            }
        }
        return ret;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for (auto &c: edges) {
            int u = c[0], v = c[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = std::min(ans, bfs(i, n));
        }
        return ans >= INF? -1: ans;
    }
};