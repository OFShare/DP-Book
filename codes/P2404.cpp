#include <bits/stdc++.h>
using namespace std;

int n;
void dfs(int n, vector<int> &v) {
  // 递归的边界
  if (n == 0) {
    for (int i = 0, sz = v.size(); i < sz; ++i) {
      if (i == 0) cout << v[i];
      else cout << "+" << v[i];
    }
    cout << "\n";
    return ;
  }
  for (int x = v.back(); x <= n; ++x) {
    v.push_back(x);
    dfs(n - x, v);
    v.pop_back();
  }
}
int main() {
  cin >> n;
  vector<int> v;
  for (int x = 1; x < n; ++x) {
    v.push_back(x);
    dfs(n - x, v);
    v.pop_back();
  }
  return 0;
}