// "人人为我" 写法
class Solution {
public:
  static const int N = 45 + 5;
  int dp[N];
  int climbStairs(int n) {
      dp[1] = 1;
      dp[2] = 2;
      for (int i = 3; i <= n; ++i) {
          dp[i] = dp[i - 1] + dp[i - 2];
      }
      return dp[n];
  }
};

// "我为人人" 写法
// 状态i 一次性爬一步就到了状态i + 1, 一次性爬二步就到了状态i + 1
class Solution {
public:
  static const int N = 45 + 5;
  int dp[N];
  int climbStairs(int n) {
      dp[1] = 1;
      dp[2] = 1;
      for (int i = 1; i <= n; ++i) {
          dp[i + 1] += dp[i];
          dp[i + 2] += dp[i];
      }
      return dp[n];
  }
};

// "人人为我"的"滚动数组"优化
class Solution {
public:
  int climbStairs(int n) {
      if (n == 1) return 1;
      if (n == 2) return 2;
      int i1 = 1, i2 = 2, curi;
      for (int i = 3; i <= n; ++i) {
          curi = i1 + i2;
          i1 = i2;
          i2 = curi;
      }
      return curi;
  }
};

// 记忆化搜索
class Solution {
public:
  static const int N = 45 + 5;
  int dp[N];
  int climbStairs(int n) {
      if (n == 1) return 1;
      if (n == 2) return 2;
      if (dp[n] != 0) return dp[n];
      return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
  }
};