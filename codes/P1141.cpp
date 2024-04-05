#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// 由于a初始值只有0或1, 后面我们对数组a的标记（染色）可以直接从2开始
int n, m, a[N][N], mp[N * N];

void dfs(int x, int y, int color, int &number) {
  int expected = 1 - a[x][y];
  // 标记当前节点
  a[x][y] = color;
  number += 1;
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && a[newx][newy] == expected) {
      dfs(newx, newy, color, number);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string str;
    cin >> str;
    for (int j = 0, sz = str.size(); j < sz; ++j) {
      if (str[j] == '0') a[i][j + 1] = 0;
      else a[i][j + 1] = 1;
    }
  }
  // 尝试从每个点坐标出发开始标记（染色）
  int color = 1, number = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] < 2) {
        dfs(i, j, ++color, number);
        mp[color] = number;
        number = 0;
      }
    }
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    cout << mp[a[i][j]] << "\n";
  }
  return 0;
}