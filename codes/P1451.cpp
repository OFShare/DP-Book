#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5, START = 10;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, a[N][N];
void dfs(int x, int y, const int &color) {
  a[x][y] = color;
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= m) {
      if (a[newx][newy] >= 1 && a[newx][newy] <= 9)
        dfs(newx, newy, color);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j < m; ++j) {
      if (str[j] == '0') a[i][j + 1] = 0;
      else a[i][j + 1] = 1;
    }
  }
  int color = START;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] >= 1 && a[i][j] <= 9)
        dfs(i, j, ++color);
  cout << color - START << "\n";
  return 0;
}