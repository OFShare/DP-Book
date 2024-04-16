#include <bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// up[i][j]表示从(i, j)这个位置向上出发，1的个数，同理down, Left, Right
int n, a[N][N], up[N][N], down[N][N], Left[N][N], Right[N][N];

void dfs(int x, int y, const int &color) {
  a[x][y] = color;
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && a[newx][newy] == 0) {
      dfs(newx, newy, color);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> a[i][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      up[i][j] = up[i - 1][j] + (a[i][j] == 1? 1: 0);
      Left[i][j] = Left[i][j - 1] + (a[i][j] == 1? 1: 0);
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      down[i][j] = down[i + 1][j] + (a[i][j] == 1? 1: 0);
      Right[i][j] = Right[i][j + 1] + (a[i][j] == 1? 1: 0);
    }
  }
  // 检查0这个点是否在闭合圈内，如果在闭合圈内，从位置(x, y)向4个方向出发一定都可以遇到1
  // 然后从(x, y) dfs染色即可
  int found = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (found) break;
      if (a[i][j] == 0 && up[i][j] > 0 && down[i][j] > 0 && Left[i][j] > 0 && Right[i][j] > 0) {
        dfs(i, j, 2);
        found = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}