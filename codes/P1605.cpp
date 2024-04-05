#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 2;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, t, sx, sy, fx, fy, vis[N][N], broken[N][N], ans;

void dfs(int x, int y) {
  if (x == fx && y == fy) {
    ans += 1;
    return ;
  }
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    // 先判断(newx, newy)是否在方格内，再判断不是障碍物点且没被访问
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] + broken[newx][newy] == 0) {
      vis[x][y] = 1;
      dfs(newx, newy);
      // 回溯
      vis[x][y] = 0;
    }
  }
}
int main() {
  cin >> n >> m >> t;
  cin >> sx >> sy >> fx >> fy;
  while (t--) {
    int x, y;
    cin >> x >> y;
    broken[x][y] = 1;
  }
  dfs(sx, sy);
  cout << ans;
  return 0;
}