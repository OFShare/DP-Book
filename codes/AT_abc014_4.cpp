/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */

// 做法比较直接，本题构成的环与最近公共祖先有关，用<倍增 + 二分>求LCA
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 60 + 1;
int n, q, depth[N], dp[N][M];
vector<int> g[N];
map<pair<int, int>, int> mp;

void dfs(int u, int fa) {
    if (fa == -1) {
        for (int i = 0; i < M; ++i) dp[u][i] = u;
    }
    else {
        dp[u][0] = fa;
        for (int i = 1; i < M; ++i) {
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
        }
    }
    
    for (auto &v: g[u]) {
        if (v != fa) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int jump(int u, int step) {
    int ret = u;
    for (int i = 0; i < M; ++i) {
        // 这里注意一定得是1LL << i，如果写成1 << i会溢出
        if ((1LL << i) & step) {
            ret = dp[ret][i];
        }
    }
    return ret;
}

int lca(int u, int v) {
    if (mp.count({u, v})) return mp[{u, v}];
    if (mp.count({v, u})) return mp[{v, u}];
    if (depth[u] > depth[v]) return mp[{u, v}] = lca(v, u);
    int newv = jump(v, depth[v] - depth[u]);
    
    if (u == newv) return u;
    int L = 0, R = 1e9;
    for (int i = 0; i < 50; ++i) {
        if (L == R || L + 1 == R) break;
        int mid = L + (R - L) / 2;
        if (jump(u, mid) == jump(newv, mid)) R = mid;
        else L = mid + 1;
    }
    if (jump(u, L) == jump(newv, L)) return mp[{u, newv}] = mp[{u, v}] = jump(u, L);
    return mp[{u, newv}] = mp[{u, v}] = jump(u, R);
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << depth[u] - depth[lca(u, v)] + depth[v] - depth[lca(u, v)] + 1 << "\n";
    }
    return 0;
}