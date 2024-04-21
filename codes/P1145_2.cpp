#include <bits/stdc++.h>
using namespace std;

int n, k;
// 维护状态<start, len>，下一个要删除的位置为：start = (start + m - 1) % len

// n = 6, m = 5
// 0 1 2 3 4 5, 一开始<start = 0, len = 6>，下一个要删除的位置为：start = (0 + m - 1) % 6 = 4, 还剩下位置0 1 2 3 ? 5，然后重写映射为0 1 2 3 4
// 0 1 2 3 4, <start = 4, len = 5>, 下一个要删除的位置为：start = (4 + m - 1) % 5 = 3, 还剩下位置0 1 2 ? 4，然后重写映射为0 1 2 3
// 0 1 2 3, <start = 3, len = 4>, 下一个要删除的位置为：start = (3 + m - 1) % 4 = 3, 还剩下位置0 1 2 ?，然后重写映射为0 1 2

// 由于我们总是把坏人删掉，所以好人的位置在等价映射前后一直是没变的，0 <= 好人id < k

int main() {
  cin >> k;
  n = k + k;
  for (int m = k; ; ++m) {
    // 检查m是否符合要求
    int start = 0, len = n, bad = 0;
    while (len > k && bad == 0) {
      // 要kill人的id
      start = (start + m - 1) % len;
      if (start < k) bad = 1;
      len -= 1;
    }
    if (bad == 0) {
      cout << m << "\n";
      break;
    }
  }
  return 0;
}