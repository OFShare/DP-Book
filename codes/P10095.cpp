#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, ll>;

const ll N = 1e18 + 5;
ll t, n;
map<pii, ll> dp;
vector<ll> nums;

// dp[{i, x}]表示nums数组里的前i个元素[0:i]，构成斐波那契数的乘积为x，的方式数量
ll dfs(int i, ll x) {
  if (i < 0) return x == 1? 1: 0;
  if (dp.count({i, x})) return dp[{i, x}];
  ll ret = 0;
  // 选出一个nums[i]
  if (x % nums[i] == 0) ret += dfs(i, x / nums[i]);
  // 跳过nums[i]
  ret += dfs(i - 1, x);
  return dp[{i, x}] = ret;
}

int main() {
  // 先预处理出<=N范围内的所有斐波那契数，虽然看起来N很大，但是在这个范围内的斐波那契数不会太多
  ll a = 1, b = 2, c;
  while (b < N) {
    nums.push_back(b);
    c = a + b;
    a = b;
    b = c;
  }
  // cout << nums.size() << "\n";
  
  cin >> t;
  while (t--) {
    cin >> n;
    cout << dfs(nums.size() - 1, n) << "\n";
  }
  return 0;
}