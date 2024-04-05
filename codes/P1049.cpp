#include <bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
int V, n, v[N], ans;

void dfs(int i, int volume) {
  // 剪枝
  if (volume > V) return ;
  // 边界
  if (i == n + 1) {
    ans = std::min(ans, V - volume);
    return ;
  }
  // 不选
  dfs(i + 1, volume + 0);
  // 选
  dfs(i + 1, volume + v[i]);
}
int main() {
  cin >> V >> n;
  for (int i = 1; i <= n; ++i)
    cin >> v[i];
  ans = V;
  dfs(1, 0);
  cout << ans;
  return 0;
}