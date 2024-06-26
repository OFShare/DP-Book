/*
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 * 做法：从起点 -> 终点 or 终点 -> 起点, 这两条路径是可逆等价的。但是如果我们选择从起点 -> 终点，会发现不太好做。如果我们选择从终点 -> 起点，发现可做
 *       
 *       我们定义dfs(target)表示从终点target -> 起点0，最少的花费。
 *       转移：1. 从target一步一步走到起点，花费可以O(1)算出来
 *             2. 借助公交车，在target处可能往左走几步 or 往右走几步，到达新位置new_target, 满足new_target % jump == 0, 然后一步走到new_target / jump处。
 *       
 *       在实现中dfs(target) -> dfs(new_target / jump)，可以看出状态的变化是log级别的
 *
 */

class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;
    std::unordered_map<int, ll> dp;
    ll dfs(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        if (target == 0) return 0;
        if (dp.count(target)) return dp[target];

        ll ret = 1LL * target * inc;
        int m = jump.size();
        for (int i = 0; i < m; ++i) {
            if (target % jump[i] == 0) {
                ret = std::min(ret, dfs(target / jump[i], inc, dec, jump, cost) + cost[i]);
            }
            else {
                int number = target / jump[i];
                int left = target - jump[i] * number;
                int right = (number + 1) * jump[i] - target;
                if ((target - left) / jump[i] < target)
                    ret = std::min(ret, dfs((target - left) / jump[i], inc, dec, jump, cost) + cost[i] + 1LL* inc * left);
                if ((target + right) / jump[i] < target)
                    ret = std::min(ret, dfs((target + right) / jump[i], inc, dec, jump, cost) + cost[i] + 1LL * dec * right);
            }
        }
        return dp[target] = ret;
    }
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        return dfs(target, inc, dec, jump, cost) % MOD;
    }
};