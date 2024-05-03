#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, INF = 2e9;
int n, a[N], pre_mx = 0, pre_mi = 0, ans = -INF, total = 0, cnt = 0;

// dp_left_mx（mi）[i]表示考虑前i个位置[0:i], 以某一个位置结束的，的最大值（最小值）
// dp_left_mx（mi）[i]表示考虑后i个位置[i:n), 以某一个位置开始的，的最大值（最小值）
int dp_left_mx[N], dp_right_mx[N];
int dp_left_mi[N], dp_right_mi[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        
        if (a[i] >= 0) cnt += 2;
        total += a[i];
        pre_mx = std::max(pre_mx + a[i], a[i]);
        pre_mi = std::min(pre_mi + a[i], a[i]);
        
        dp_left_mx[i] = std::max((i - 1 >= 1? dp_left_mx[i - 1]: -INF), pre_mx);
        dp_left_mi[i] = std::min((i - 1 >= 1? dp_left_mi[i - 1]: INF), pre_mi);
    }

    pre_mx = 0, pre_mi = 0;
    for (int i = n; i >= 1; --i) {
      pre_mx = std::max(pre_mx + a[i], a[i]);
      pre_mi = std::min(pre_mi + a[i], a[i]);

      dp_right_mx[i] = std::max((i + 1 <= n? dp_right_mx[i + 1]: -INF), pre_mx);
      dp_right_mi[i] = std::min((i + 1 <= n? dp_right_mi[i + 1]: INF), pre_mi);
    }

    // +表示要选取的数
    // 情况一：-------+++++-----++++++----
    for (int i = 1; i < n; ++i) {
      ans = std::max(ans, dp_left_mx[i] + dp_right_mx[i + 1]);
    }

    // 情况二：+++++------+++++------+++++
    // ans = (总和 - 两段最小的-)
    // 注意到要选两段，所以至少应该有2个大于等于0的数
    //（如果只有1个大于等于0的数，会发生什么？这样就选不到两段了
    if (cnt >= 2) {
      for (int i = 1; i < n; ++i) {
        ans = std::max(ans, total - (dp_left_mi[i] + dp_right_mi[i + 1]));
      }
    }
    std::cout << ans << "\n";
    return 0;
}