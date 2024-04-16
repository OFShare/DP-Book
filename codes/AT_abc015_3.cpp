#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 2;
int n, m, a[N][N], found = 0;

// 状态：f(i, value)表示前i行（未包括第i行），每行选的一个值它们的异或值为value
// 转移：从第i行，选一个数出来
void dfs(int i, int value) {
  if (found) return ;
  if (i == n + 1) {
    if (value == 0) found = 1;
    return ;
  }
  for (int j = 1; j <= m; ++j) {
    dfs(i + 1, value ^ a[i][j]);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];

  dfs(1, 0);
  if (found) cout << "Found\n";
  else cout << "Nothing\n";
  return 0;
}