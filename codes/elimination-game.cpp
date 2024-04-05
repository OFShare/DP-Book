class Solution {
public:
    int dfs1(int n) {
        if (n == 1) return 1;
        return 2 * dfs2(n / 2);
    }
    int dfs2(int n) {
        if (n == 1) return 1;
        return 2 * dfs1(n / 2) - (n % 2 == 0? 1: 0);
    }
    int lastRemaining(int n) {
        return dfs1(n);
    }
};