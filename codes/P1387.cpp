#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, ans, a[N][N], dp[N][N], up[N][N], Left[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];
  
  // 有三个状态dp, up, left，都可以在（从上到下，从左到右）一次遍历求得。
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= m; ++y) {
      if (a[x][y] == 0) {
        dp[x][y] = up[x][y] = Left[x][y] = 0;
      }
      else {
        up[x][y] = up[x - 1][y] + 1;
        Left[x][y] = Left[x][y - 1] + 1;
        dp[x][y] = std::min({dp[x - 1][y - 1] + 1, Left[x][y], up[x][y]});
      }
      ans = std::max(ans, dp[x][y]);
    }
  }
  cout << ans << "\n";
  return 0;
}