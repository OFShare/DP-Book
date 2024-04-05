#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
vector<int> g[N];
int color[N], n, k, m, ans = 0;
// 一个坑点，图可能存在孤立的点
bool check(int u) {
  for (auto &v: g[u]) {
    if (color[u] == color[v]) return 0;
  }
  return 1;
}
void dfs(int u) {
  if (u == n + 1) {
    ans += 1;
    return ;
  }
  for (int i = 1; i <= m; ++i) {
    color[u] = i;
    if (!check(u)) continue;
    dfs(u + 1);
  }
  color[u] = 0;
}
int main() {
  cin >> n >> k >> m;
  for (int i = 1; i <= k; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  cout << ans << "\n";
  return 0;
}