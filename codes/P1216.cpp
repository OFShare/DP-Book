// 我为人人的递推写法
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int r, a[N][N], dp[N][N], ans = 0;

int main() {
  cin >> r;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= i; ++j)
      cin >> a[i][j];
      
  dp[1][1] = a[1][1];
  for (int i = 1; i <= r - 1; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
      dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
    }
  }
  for (int j = 1; j <= r; ++j) ans = std::max(ans, dp[r][j]);
  cout << ans << "\n";
  return 0;
}


// 人人为我，无滚动数组优化
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int r, a[N][N], dp[N][N], ans = 0;

int main() {
  cin >> r;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= i; ++j)
      cin >> a[i][j];
      
  dp[1][1] = a[1][1];
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = std::max({dp[i - 1][j] + a[i][j], dp[i - 1][j - 1] + a[i][j]});
    }
  }
  for (int j = 1; j <= r; ++j) ans = std::max(ans, dp[r][j]);
  cout << ans << "\n";
  return 0;
}


// 人人为我，滚动数组优化，注意dp数组第一维的大小是2，状态里全部加上"&"就可以简单的实现滚动数组优化了，这也是如何改写为滚动数组优化的技巧。
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int r, a[N][N], dp[2][N], ans = 0;

int main() {
  cin >> r;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= i; ++j)
      cin >> a[i][j];
      
  dp[1 & 1][1] = a[1][1];
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i & 1][j] = std::max({dp[i - 1 & 1][j] + a[i][j], dp[i - 1 & 1][j - 1] + a[i][j]});
    }
  }
  for (int j = 1; j <= r; ++j) ans = std::max(ans, dp[r & 1][j]);
  cout << ans << "\n";
  return 0;
}


// 记忆化搜索一
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int r, a[N][N], dp[N][N], ans = 0;

// dp[i][j]表示以位置(i, j)出发能获得的最大路径和
int dfs(int i, int j) {
  if (i == r + 1) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = std::max({dfs(i + 1, j) + a[i][j], dfs(i + 1, j + 1) + a[i][j]});
}

int main() {
  cin >> r;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= i; ++j)
      cin >> a[i][j];
  
  std::memset(dp, -1, sizeof dp);
  cout << dfs(1, 1) << "\n";
  return 0;
}


// 记忆化搜索二
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int r, a[N][N], dp[N][N], ans = 0;

// dp[i][j]表示以位置(i, j)结束能获得的最大路径和
int dfs(int i, int j) {
  if (i == 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = std::max({dfs(i - 1, j - 1) + a[i][j], dfs(i - 1, j) + a[i][j]});
}

int main() {
  cin >> r;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= i; ++j)
      cin >> a[i][j];
  
  std::memset(dp, -1, sizeof dp);
  for (int j = 1; j <= r; ++j) ans = std::max(ans, dfs(r, j));
  cout << ans << "\n";
  return 0;
}