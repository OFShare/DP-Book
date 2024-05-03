#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e3 + 5;
int n, m, a[N][N], up[N][N];
ll ans = 0;

// 枚举上边界，下边界，再跑一遍类似最大子段和，时间复杂度O(N ^ 3)
// 其实不用枚举上边界？这样时间复杂度降为O(N ^ 2)

/*
    1
  1 1
1 1 1 
1 1 1 1

2 3 4 1

total维护可以当子矩阵左上角的点的个数，比如上面的样例，当从左往右枚举到4时，total = 2 + 3 = 5，由于4比3大，可以直接入栈，同时更新total = 9

当最后面的1要入栈时，弹出4，3，2，更新total = 4，入栈为{1, 4}表示有4个高度都为1的在栈里

*/
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];

            if (a[i][j] == 1) up[i][j] = up[i - 1][j] + 1;
            else up[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        // height, cnt
        std::deque<std::array<int, 2> > que;
        ll total = 0;
        for (int j = 1; j <= m; ++j) {
            int cnt = 1;
            while (!que.empty() && que.back()[0] > up[i][j]) {
                total -= (que.back()[0] - up[i][j]) * que.back()[1];
                cnt += que.back()[1];
                que.pop_back();
            }
            
            total += up[i][j];
            // 统计右下角（i, j）的子矩阵数量
            ans += total;
            que.push_back({up[i][j], cnt});
        }
    }
    cout << ans << "\n";
    return 0;
}