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

const int N = 1e5 + 5, MOD = 1e9 + 7;
std::vector<int> g[N];
int n, k, ans;

// dfs一步一步确定每个节点可以染色的种类数（最后乘起来就是答案），且当前节点u可以染色的种类数已确定。
// 由于只要和距离<=2的节点染色不同，那么对于树上任何一个节点u，影响节点u的染色的节点个数不多（u的父亲节点，u的父亲的父亲节点，u的兄弟节点们）
void dfs(int u, int fa, int depth) {
    int up = (depth == 0? 1: 2);
    int brothers = 0;
    for (auto &v: g[u]) {
        if (v != fa) {
            ans = (1LL * ans * (k - up - brothers)) % MOD;
            brothers += 1;

            dfs(v, u, depth + 1);
        }
    }
}

int main() {
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

    ans = k;
    dfs(1, -1, 0);
	cout << ans << "\n";
    return 0;
}