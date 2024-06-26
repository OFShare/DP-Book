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
    做法（由于每个节点 至多 有一条出边）
        先进行dfs1，从每个节点出发，进行染色。每个节点最多被染色一次，且找出环的入口点，存入ans里(同一个环最多只会有一个节点存入ans里)
        再进行dfs2，统计最长环的路径

        时间复杂度：因为每个节点最多被染色一次，所以dfs1的时间复杂度为O(N), dfs2也是O(N), 所以总的时间复杂度为O(N)
    */
    static const int N = 1e5 + 5;
    vector<int> g[N];
    int vis[N];
    vector<int> ans;
    void dfs1(int u, const int &tag) {
        vis[u] = tag;
        for (auto &v: g[u]) {
            if (vis[v] == 0) {
                dfs1(v, tag);
            }
            else if (vis[v] == tag) {
                ans.push_back(v);
                return ;
            }
        }
    }
    int dfs2(int u, int fa, const int &source) {
        if (u == source && fa != -1) return 0;
        int ret = 0;
        for (auto &v: g[u]) {
            ret = 1 + dfs2(v, u, source);
        }
        return ret;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        for (int i = 0; i < n; ++i) {
            int u = i, v = edges[i];
            if (v != -1)
                g[u].push_back(v);
        }

        int tag = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0) {
                dfs1(i, ++tag);
            }
        }
        int ret = -1;
        for (auto &u: ans) {
            ret = std::max(ret, dfs2(u, -1, u));
        }
        return ret;
    }
};