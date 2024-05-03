class Solution {
public:
    static const int N = 1e2 + 5, MOD = 1e9 + 7, INF = 1e9;
    // dp[x][y]表示从起点走到（第x行，第y列）时，最大值
    // cnt[x][y]表示从起点走到（第x行，第y列）时，得到最大值时，的方案数
    // 转移：填表法(x，y)可以由(x + 1, y)，(x, y + 1)，(x + 1, y + 1)转移而来
    
    int dp[N][N], cnt[N][N], n;
    void dfs(int x, int y, const vector<string>& board) {
        if (!(x >= 0 && x < n && y >= 0 && y < n)) return ;
        if (board[x][y] == 'X') return ;
        if (board[x][y] == 'S') return ;
        if (dp[x][y] > -INF) return ;
        dfs(x + 1, y, board);
        dfs(x, y + 1, board);
        dfs(x + 1, y + 1, board);

        int num = board[x][y] >= '1' && board[x][y] <= '9'? board[x][y] - '0': 0;
        int mx = std::max({dp[x + 1][y], dp[x][y + 1], dp[x + 1][y + 1]}) + num, c = 0;
        if (dp[x + 1][y] + num == mx) c = (c + cnt[x + 1][y]) % MOD;
        if (dp[x][y + 1] + num == mx) c = (c + cnt[x][y + 1]) % MOD;
        if (dp[x + 1][y + 1] + num == mx) c = (c + cnt[x + 1][y + 1]) % MOD;
        dp[x][y] = mx, cnt[x][y] = c;
        return ;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        // std::memset(dp, -0x3f, sizeof dp);
        for (int i = 0; i < n + 5; ++i)
            for (int j = 0; j < n + 5; ++j)
                dp[i][j] = -INF;

        dp[n - 1][n - 1] = 0, cnt[n - 1][n - 1] = 1;
        dfs(0, 0, board);
        if (dp[0][0] < 0) return {0, 0};
        return {dp[0][0], cnt[0][0]};
    }
};