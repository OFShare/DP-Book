#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N][N], ans_cnt;
vector<int> ans;

void dfs(int i, vector<int> &v) {
  // 边界
  if (i == n + 1) {
    if (v.size() > ans_cnt) {
      ans_cnt = v.size();
      ans = v;
    }
    return ;
  }
  bool ok = 1;
  for (auto &c: v) {
    if (a[c][i] == 1 || a[i][c] == 1) {
      ok = 0;
    }
  }
  // 选第i个
  if (ok) {
    v.push_back(i);
    dfs(i + 1, v);
    v.pop_back();
  }
  // 不选第i个
  dfs(i + 1, v);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    a[u][v] = a[v][u] = 1;    
  }
  vector<int> v;
  dfs(1, v);
  cout << ans.size() << "\n";
  for (int i = 1; i <= n; ++i) {
    bool found = 0;
    for (auto &c: ans) {
      if (i == c) {
        found = 1;
        break;
      }
    }
    if (found) cout << 1 << " ";
    else cout << 0 << " ";
  }
  return 0;
}