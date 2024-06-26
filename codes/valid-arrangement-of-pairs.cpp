/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *  做法：一笔画问题、欧拉路径，保证每条边只会访问一次哦
 *  
 *        在dfs回溯的时候逆序保存边，就能自然得到问题的解。想清楚为啥这样work，可不是那么简单。
 *
 */

class Solution {
public:
    static const int N = 1e5 + 5;
    map<int, vector<int> > g;
    map<int, int> in, out;
    vector<vector<int> > ans;
    void dfs(int u) {
        while (!g[u].empty()) {
            int v = g[u].back();
            g[u].pop_back();

            dfs(v);
            ans.push_back({u, v});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (auto &c: pairs) {
            int u = c[0], v = c[1];
            g[u].push_back(v);

            out[u] += 1;
            in[v] += 1;
        }
        int start = pairs[0][0];
        for (auto &c: pairs) {
            int u = c[0], v = c[1];
            if (out[u] == in[u] + 1) start = u;
            if (out[v] == in[v] + 1) start = v;
        }
        // cout << start << " " << out[start] << " " << in[start] << endl;
        dfs(start);
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};