#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, ans = 0;
string a[N];

void dfs(int x, int y, const char &color) {
  a[x][y] = color;
  for (int i = 0; i < 8; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 0 && newx < n && newy >= 0 && newy < m && a[newx][newy] == 'W') {
      dfs(newx, newy, color);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'W') {
        dfs(i, j, '.');
        ans += 1;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}