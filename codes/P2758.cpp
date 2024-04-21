#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int dp[N][N];
string s1, s2;

// dp[i][j]表示将字符串A的前i个字符[0:i]，使用三种操作转换为，字符串B的前j个字符[0:j]，的最少操作数
int dfs(int i, int j) {
  if (i < 0) return j + 1;
  if (j < 0) return i + 1;
  if (dp[i][j] != -1) return dp[i][j];
  int ret = i + j, flag = (s1[i] == s2[j]? 0: 1);
  return dp[i][j] = std::min({dfs(i - 1, j) + 1, dfs(i, j - 1) + 1, dfs(i - 1, j - 1) + flag});
}

int main() {
  cin >> s1 >> s2;
  
  std::memset(dp, -1, sizeof dp);
  cout << dfs(s1.size() - 1, s2.size() - 1) << "\n";
  return 0;
}