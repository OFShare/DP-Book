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
    int color[N], found_circle = 0, tag = 0;

    // 从节点u出发，都染色为tag，如果有环，肯定会碰到染为同一色tag的，回溯时需要把color[v]设为-1，表示此节点已访问过。
    // 简单的说，color[u] = 0表示该节点从未访问过，color[u] = tag表示正在进行dfs访问，color[u] = -1表示该节点已访问过
    // 时间复杂度：每个节点只会被染色2次，所以总的时间复杂度为O(N)
    void dfs(int u, int tag) {
        color[u] = tag;
        for (auto &v: g[u]) {
            if (color[v] == tag) {
                found_circle = true;
                return ;
            }
            else if (color[v] == 0) {
                dfs(v, tag);
                color[v] = -1;
            }
        }
        color[u] = -1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto &c: prerequisites) {
            int u = c[1], v = c[0];
            g[u].push_back(v);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == 0) {
                dfs(i, ++tag);
                if (found_circle) return 0;
            }
        }
        return 1;
    }
};