/*
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 * 做法：定义minDays(n)表示吃掉n个橘子，的最少天数。
 * 
 * 转移：我们总是可以吃掉几个橘子，使得n % 2 == 0 or n % 3 == 0
 *       1. minDays(n) -> minDays(n / 2)
 *       2. minDays(n) -> minDays(n / 3)，可以看出状态的变化是log级别的
 *
 *
 */
class Solution {
public:
    map<int, int> dp;
    int minDays(int n) {
        if (n == 1) return 1;
        if (n == 2 || n == 3) return 2;
        if (dp.count(n)) return dp[n];

        int ret = n;
        if (n % 2 == 0) ret = std::min(ret, minDays(n / 2) + 1);
        else ret = std::min(ret, minDays(n - n % 2) + n % 2);

        if (n % 3 == 0) ret = std::min(ret, minDays(n / 3) + 1);
        else ret = std::min(ret, minDays(n - n % 3) + n % 3);

        return dp[n] = ret;
    }
};