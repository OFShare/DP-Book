#include <bits/stdc++.h>
using namespace std;

const int N = 6 + 2;
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int T, n, m, ans, a[N][N], vis[N][N];

// 如果(x, y)被选，那相邻8个格子都不能有选的
bool check(int x, int y) {
  for (int i = 0; i < 8; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy])
      return 0;
  }
  return 1;
}

// dfs的过程是一个格子一个格子，从左到右从上到下 进行的
// 状态：<x, y, sum， vis>表示走到了（x, y）坐标，目前和为sum（不包括当前坐标(x, y)），访问过的坐标保存在vis里
// 转移：对于当前坐标（x, y）选还是不选
void dfs(int x, int y, int sum) {
  // 边界，走到了(n + 1, 1)的位置
  if (x == n + 1) {
    if (sum > ans) ans = sum;
    return ;
  }
  // 本行走完了，该走下一行了
  if (y == m + 1) return dfs(x + 1, 1, sum);
  // 不选(x, y)
  dfs(x, y + 1, sum);
  // 选(x, y), 那就得确保满足已经选了的元素没有和它相邻的
  if (check(x, y)) {
    vis[x][y] = 1;
    dfs(x, y + 1, sum + a[x][y]);
    vis[x][y] = 0;
  }
}

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
          cin >> a[i][j];

    ans = 0;    
    dfs(1, 1, 0);
    cout << ans << "\n";
  }
  return 0;
}