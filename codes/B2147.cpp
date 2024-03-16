#include <bits/stdc++.h>
using namespace std;

float dfs(float x, float n) {
  if (n == 1) return std::sqrt(1 + x);
  return std::sqrt(n + dfs(x, n - 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
    
  float x, n;
  cin >> x >> n;
  cout << fixed << setprecision(2) << dfs(x, n) << '\n';
  return 0;
}