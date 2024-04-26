#include <bits/stdc++.h>
using namespace std;

const int N = 32768 + 5;
int t, n;
vector<int> nums;

// 25 = 4^2 + 3^2和25 = 3^2 + 4^2表示同一种方案，所以我们可以规定选出的数是不下降排列的。
// 由于nums数组本身是不下降的，所以下面的DP自然就符合"选出的数是不下降排列的"。

// dp[i][j][k]表示前i个元素[1: i], 凑成和为j，且一共选出来k个元素的，方案数.
int dp[2][N][5];

int main() {
  nums.push_back(-1);
  // 预处理<=N范围内的所有i * i
  for (int i = 1; 1LL * i * i <= N; ++i) nums.push_back(i * i);
  int len = nums.size() - 1;

  // DP  
  dp[0 & 1][0][0] = 1;
  for (int i = 1; i <= len; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k <= 4; ++k) {
        // 枚举第i个元素，nums[i]使用几个
        int d = nums[i];
        // 必须重置为0
        dp[i & 1][j][k] = 0;
        for (int cnt = 0; cnt <= k; ++cnt) {
          if (j - cnt * d >= 0)
            dp[i & 1][j][k] += dp[i - 1 & 1][j - cnt * d][k - cnt];
        }
      }
    }
  }
  
  cin >> t;
  while (t--) {
    cin >> n;
    cout << dp[len & 1][n][1] + dp[len & 1][n][2] + dp[len & 1][n][3] + dp[len & 1][n][4] << "\n";
  }
  return 0;
}