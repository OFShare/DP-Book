#include <bits/stdc++.h>
using namespace std;

const int N = 15 + 2;
int n, vis[N];
float x[N], y[N], ans = 1e9;

float distance(int u, int v) {
  return std::sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

// 状态<u, dis, cnt, vis>表示当前走到节点u，走过的距离为dis，走过哪些点的个数为cnt，走过哪些点保存在vis
void dfs(int u, float dis, int cnt) {
  // 边界
  if (cnt == n) {
    ans = std::min(ans, dis);
    return ;
  }
  // 剪枝
  if (dis > ans) return ;
  for (int v = 1; v <= n; ++v) {
    if (vis[v] == 0) {
      vis[v] = 1;
      dfs(v, dis + distance(u, v), cnt + 1);      
      vis[v] = 0;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  
  vis[0] = 1;
  dfs(0, 0, 0);
  cout << setprecision(2) << fixed << ans << endl;
  return 0;
}