#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int mp[N], n, x;

int LIS(const vector<int> &v) {
  vector<int> dp;
  for (auto &c: v) {
    auto it = lower_bound(dp.begin(), dp.end(), c);
    if (it == dp.end()) dp.push_back(c);
    else *it = c;
  }
  return dp.size();
}

int main() {  
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    mp[x] = i;
  }
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    v.push_back(mp[x]);
  }
  cout << LIS(v);
  return 0;
}