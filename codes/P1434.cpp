#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int R, C, ans, a[N][N], dp[N][N];

// dp[x][y]表示从坐标（x, y）出发，能走的最长的距离
int dfs(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  int ret = 1;
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= R && newy >= 1 && newy <= C && a[newx][newy] < a[x][y])
      ret = std::max(ret, dfs(newx, newy) + 1);
  }
  return dp[x][y] = ret;
}

int main() {
  cin >> R >> C;
  for (int i = 1; i <= R; ++i)
    for (int j = 1; j <= C; ++j)
      cin >> a[i][j];
  
  std::memset(dp, -1, sizeof dp);
  for (int i = 1; i <= R; ++i)
    for (int j = 1; j <= C; ++j)
      ans = std::max(ans, dfs(i, j));
  
  cout << ans << "\n";
  return 0;
}