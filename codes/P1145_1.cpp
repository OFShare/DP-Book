#include <bits/stdc++.h>
using namespace std;

// 根据题目要求模拟
int n, k;

int main() {
  cin >> k;
  n = k + k;
  vector<int> v;
  for (int i = 0; i < n; ++i) v.push_back(i);
  for (int m = k; ; ++m) {
    auto newv = v;
    int start = 0, bad = 0;
    while (newv.size() > k && bad == 0) {
      // 要删除的下标是start, 下标里保存元素是newv[start]
      start = (start + m - 1) % newv.size();
      if (newv[start] >= 0 && newv[start] < k) bad = 1;
      
      // 删除位置start处的元素，然后把[start + 1: ]后面的元素每个都往前移一个，最后pop_back()
      if (start != newv.size() - 1) {
        for (int j = start + 1; j < newv.size(); ++j) {
          newv[j - 1] = newv[j];
        }
      }
      newv.pop_back();
    }
    if (bad == 0) {
      cout << m << "\n";
      break;
    }
  }
}