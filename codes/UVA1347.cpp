#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, INF = 1e9;
float x[N], y[N], dp[N][N], ans;
int n;

// dp[i][j]表示有两个人从最左端出发，往最右端走，目前第一个人的位置在i，第二个人的位置在j，且<=max(i, j)的位置，都已被走过，的最小距离
// 转移：枚举下一个人谁走到k = max(i, j) + 1处
// 时间复杂度：O(N ^ 2)

float dis(int i, int j) {
	return std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; ++i)
			cin >> x[i] >> y[i];

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dp[i][j] = INF;

		dp[1][1] = 0;
		ans = INF;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int k = std::max(i, j) + 1;
				// i --> k
				dp[k][j] = std::min(dp[k][j], dp[i][j] + dis(i, k));
				// j --> k
				dp[i][k] = std::min(dp[i][k], dp[i][j] + dis(j, k));

				if (i == n && j < n) ans = std::min(ans, dp[i][j] + dis(j, n));
				if (j == n && i < n) ans = std::min(ans, dp[i][j] + dis(i, n));
			}
		}

		cout << fixed << setprecision(2) << ans << "\n";
	}
	return 0;
}