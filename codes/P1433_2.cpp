#include <bits/stdc++.h>
using namespace std;

const int N = 15 + 2, INF = 1e9;
int n, visited[N][1 << N];
float x[N], y[N], dp[N][1 << N];

float distance(int u, int v) {
  return std::sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

// 从<u, vis>节点u出发，已经访问过的点的集合为vis，访问完所有节点，的最小距离
float dfs(int u, int vis) {
  if (vis == (1 << (n + 1)) - 1) return 0;
  if (visited[u][vis]) return dp[u][vis];
  
  float ret = INF;
  // 枚举下一个未访问的点v
  for (int v = 1; v <= n; ++v) {
    if (((1 << v) & vis) == 0) {
      ret = std::min(ret, dfs(v, vis + (1 << v)) + distance(u, v));
    }
  }
  visited[u][vis] = 1;
  return dp[u][vis] = ret;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  
  cout << setprecision(2) << fixed << dfs(0, 1) << endl;
  return 0;
}