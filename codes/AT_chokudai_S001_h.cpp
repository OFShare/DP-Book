#include <bits/stdc++.h>
using namespace std;

// dp[i]表示从左往右扫描数组时，最长递增子序列长度为i+1时，这个子序列结尾的最小值
vector<int> dp;

int n, x;

int main() {

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    auto it = std::lower_bound(dp.begin(), dp.end(), x);
    
    if (it == dp.end()) dp.push_back(x);
    else *it = x;
  }
  cout << dp.size() << "\n";
  return 0;
}