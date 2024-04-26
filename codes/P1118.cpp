#include <bits/stdc++.h>
using namespace std;

/* 杨辉三角
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

/*
n = 5时，最后的系数为1 4 6 4 1, 对应杨辉三角的第4行（从0开始

a     b     c     d      e
  a+b   b+c   c+d     d+e
   a+2b+c b+2c+d  c+2d+e
    a+3b+3c+d b+3c+3d+e
        a+4b+6c+4d+e
*/

const int N = 12 + 5;
// 杨辉三角
int n, sum, found, c[N][N], vis[N];
vector<int> ans;

void dfs(int i, int s, vector<int> &path) {
  // 剪枝
  if (s > sum || found) return ;
  if (i == n) {
    if (s == sum) {
      found = 1;
      ans = path;
    }
    return ;
  }
  for (int num = 1; num <= n; ++num) {
    if (vis[num] == 0) {
      vis[num] = 1;
      path.push_back(num);
      // c[n - 1][i] * num, 也就是这一位在最后的答案里的权重
      dfs(i + 1, s + c[n - 1][i] * num, path);
      // 回溯
      path.pop_back();
      vis[num] = 0;
    }
  }
}

int main() {
  // 递推预处理杨辉三角
  c[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) c[i][j] = 1;
      else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  cin >> n >> sum;
  
  vector<int> path;
  dfs(0, 0, path);
  if (found) {
    for (auto &c: ans) cout << c << " ";
  }
  return 0;
}