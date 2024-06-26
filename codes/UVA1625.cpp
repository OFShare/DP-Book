/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */

// 做法参考紫书上的题解：dp[i][j]的定义比较特别？它表示考虑s1的前i个字符[1:i]，s2的前j个字符[1:j]，对于最终答案序列的最小贡献.
// 怎么理解这个状态：假设dp[i][j]这i + j个字符构成的序列为X，最终的某个答案序列为Y，经过我们一步一步的从s1或者s2选字符出来添加到X，最后X -> Y.
// 状态的转移：采用刷表法或者叫我为人人法，添加一个字符到X，产生的贡献为 =（dp[i][j] + 添加这个字符的贡献）
// 添加这个字符的贡献：如果某个字符已经出现，但是还没结束，就会产生贡献

#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, M = 26, INF = 1e9;
int T, dp[N][N];
string s1, s2;


int main() {
	cin >> T;
	while (T--) {
		cin >> s1 >> s2;
		s1 = "#" + s1;
		s2 = "#" + s2;
		int n = s1.size() - 1, m = s2.size() - 1;
        std::vector<int> L1(M, 0), R1(M, 0), L2(M, 0), R2(M, 0);
		for (int i = 1, j = n; i <= n; ++i, --j) {
			int c1 = s1[i] - 'A';
			int c2 = s1[j] - 'A';
			L1[c2] = j;
			R1[c1] = i;
		}
		for (int i = 1, j = m; i <= m; ++i, --j) {
			int c1 = s2[i] - 'A';
			int c2 = s2[j] - 'A';
			L2[c2] = j;
			R2[c1] = i;
		}

        // 每次都对全量的dp数组memset会导致TLE
		// std::memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                dp[i][j] = INF;

		dp[0][0] = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				// [1: i+1], [1: j]
				int delt = 0;
				for (int k = 0; k < 26; ++k) {
					if ((L1[k] >= 1 && L1[k] <= i + 1 && (R1[k] > i + 1 || R2[k] > j)) || ((L2[k] >= 1 && L2[k] <= j && (R2[k] > j || R1[k] > i + 1)))) delt += 1;
				}
				dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + delt);

				delt = 0;
				// [1: i], [1: j+1]
				for (int k = 0; k < 26; ++k) {
					if ((L1[k] >= 1 && L1[k] <= i && (R1[k] > i || R2[k] > j + 1)) || ((L2[k] >= 1 && L2[k] <= j + 1 && (R2[k] > j + 1 || R1[k] > i)))) delt += 1;
				}
				dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j] + delt);
			}
		}
		cout << dp[n][m] << "\n";
	}
	return 0;
}