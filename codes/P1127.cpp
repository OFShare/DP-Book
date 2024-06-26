/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *  做法：将一个单词，比如"abcde"，建立一条从a连向e的有向边，问题转化为，从某个起点出发遍历图中所有边恰好一次的问题。
 *
 *        这个遍历形成的路径，就是欧拉路径（可能是一条路，可能是一条回路）
 *
 *  一个坑点：相同的单词若出现了 k 次就需要输出 k 次
 *
 *           比如输入 3 aa aa aa, 你的程序会输出什么？
 *      5
 *      ert
 *      tyu
 *      ujh
 *      hgt
 *      tre
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int n, in_deg[N], out_deg[N], start1 = -1, start2 = N, found = 0;
vector<pair<string, int> > g[N];
map<string, int> mp;
vector<string> ans;

multiset<string> vis;
void dfs(int u, vector<string> &path) {
    if (found) return ;
    if (path.size() == n) {
        ans = path;
        found = 1;
        return ;
    }
    for (auto &c: g[u]) {
        string word = c.first;
        int v = c.second;
        if (vis.count(word) >= mp[word]) continue;

        vis.insert(word);
        path.push_back(word);
        dfs(v, path);
        // 回溯
        vis.erase(vis.find(word));
        path.pop_back();
    }
}

void solve(int start) {
    vector<string> path;
    dfs(start, path);
    if (found) {
        for (int i = 0, sz = ans.size(); i < sz; ++i) {
            if (i == 0) cout << ans[i];
            else cout << "." << ans[i];
        }
    }
    else {
        cout << "***\n";
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string word;
        cin >> word;

        int u = word[0] - 'a', v = word[word.size() - 1] - 'a';
        g[u].push_back({word, v});
        start2 = std::min({start2, u, v});
        mp[word] += 1;

        // except自环
        if (u != v) {
            out_deg[u] += 1;
            in_deg[v] += 1;
        }
    }

    for (int i = 0; i < N; ++i) std::sort(g[i].begin(), g[i].end());
    for (int i = 0; i < N; ++i) {
        // 一条路的情况
        if (out_deg[i] == in_deg[i] + 1) {
            start1 = i;
            break;
        }
    }
    // 一条路的情况
    if (start1 != -1) solve(start1);
    // 回路的情况
    else solve(start2);
    return 0;
}