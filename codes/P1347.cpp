/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 26 + 5;
int n, m, vis[N];
vector<int> g[N];

// 逆序保存拓扑序
vector<int> ans;
// -1(从未访问过)，0(正在访问)，1(已访问过)，返回是否可以从节点u拓扑排序（即不存在环）
bool dfs(int u) {
    assert(vis[u] == -1);
    vis[u] = 0;
    for (auto &v: g[u]) {
        if (vis[v] == 0) return 0;
        if (vis[v] == -1 && !dfs(v)) return 0;
    }

    vis[u] = 1;
    ans.push_back(u);
    return 1;
}

// 从节点u出发，能到达哪些节点
set<int> dfs2(int u) {
    set<int> ret = {u};
    for (auto &v: g[u]) {
        for (auto &c: dfs2(v)) {
            ret.insert(c);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int x = 1; x <= m; ++x) {
        string str;
        cin >> str;
        int u = str[0] - 'A';
        int v = str[2] - 'A';
        g[u].push_back(v);

        ans.clear();
        std::memset(vis, -1, sizeof vis);
        // 判断是否矛盾（即是否存在环）
        for (int i = 0; i < n; ++i) {
            if (vis[i] == -1 && !dfs(i)) {
                cout << "Inconsistency found after " << x << " relations.\n";
                return 0;
            }
        }

        // 判断是否可以确定n个元素的关系
        bool found = 1;
        string ans_str = "";
        assert(ans.size() == n);
        for (int i = n - 1; i >= 0; --i) {
            if (dfs2(ans[i]).size() != i + 1) {
                found = 0;
                break;
            }
            ans_str += 'A' + ans[i];
        }
        if (found) {
            cout << "Sorted sequence determined after " << x << " relations: " << ans_str << ".\n";
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined.\n";
    return 0;
}