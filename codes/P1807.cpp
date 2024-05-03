#include <bits/stdc++.h>
using namespace std;

const int N = 1500 + 5, INF = 1e9;
int n, m, dp[N];
vector<array<int, 2> > g[N];

// dp[u]表示从节点u出发，到达节点n的最长路。
// dp[u] = -INF, 表示从节点u出发，无法到达节点n
int dfs(int u) {
  if (u == n) return 0;
  if (dp[u] != -1) return dp[u];
  int ret = -INF;
  for (auto &c: g[u]) {
    int v = c[0], w = c[1];
    ret = std::max(ret, dfs(v) + w); 
  }
  return dp[u] = ret;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  
  std::memset(dp, -1, sizeof dp);
  int ans = dfs(1);
  if (ans < 0) cout << -1;
  else cout << ans;
  return 0;
}