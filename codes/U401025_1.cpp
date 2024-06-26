/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

int N, V, w[1000 + 5], c[1000 + 5], dp[100000 + 5];

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        if (u >= w[i]) ret = std::max(ret, dfs(u - w[i]) + c[i]); 
    }
    return dp[u] = ret;
}

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) cin >> w[i] >> c[i];
    
    std::memset(dp, -1, sizeof dp);
    cout << dfs(V) << "\n";
    return 0;
}