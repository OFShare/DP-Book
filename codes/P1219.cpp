#include <bits/stdc++.h>
using namespace std;

using pii = std::pair<int, int>;
int n, cnt = 0;
vector<vector<int> > ans;
void dfs(int i, vector<pii> &v) {
  if (i == n + 1) {
    cnt += 1;
    // 保存前3个解
    if (cnt <= 3) {
      vector<int> tmp;
      for (auto &c: v) tmp.push_back(c.second);
      ans.push_back(tmp);
    }
    return ;
  }
  // 尝试在第i行j列填一个棋子(i, j)
  // 由于是在第i行填棋子, 肯定和前面的行不同, 自然满足每行至多有一个棋子
  // 检查和前面的棋子不在同一列(j != y)
  // 检查和前面的棋子不在同一对角线, 即斜率不为1or-1
  // 斜率为1(i - x) == (j - y) * 1，斜率为-1(i - x) == (j - y) * -1
  for (int j = 1; j <= n; ++j) {
    bool ok = 1;
    for (auto &c: v) {
      int x = c.first, y = c.second;
      if (j == y || (i - x) == (j - y) * 1 || (i - x) == (j - y) * -1) {
        ok = 0;
        break;
      }
    }
    // 如果能在(i, j)填棋子
    if (ok) {
      v.push_back({i, j});
      dfs(i + 1, v);
      v.pop_back();
    }
  }
}
int main() {
  cin >> n;
  vector<pii> v;
  dfs(1, v);
  for (auto &v: ans) {
    for (auto &c: v) {
      cout << c << " ";
    }
    cout << "\n";
  }
  cout << cnt;
  return 0;
}