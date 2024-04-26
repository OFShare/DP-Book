class Solution {
public:
    static const int N = 1e5 + 5, M = 50 + 5;
    vector<int> g[N], prime[M], ans;
    int d[N];
    // 状态(u, fa, depth, path)记录走到当前节点u，其父节点为fa，其父节点的深度为depth，
    //                         其所有父节点的nums值保存在path里（相同的nums值，只保存深度最深的）
    //
    // 转移就是，u --> v即更新到u的儿子节点v去.
    void dfs(int u, int fa, int depth, vector<int> &path, const vector<int> &nums) {
        d[u] = depth + 1;
        int index = -1, dis = -1;
        for (auto &c: prime[nums[u]]) {
            int v = path[c];
            if (v != -1) {
                if (dis == -1 || d[v] > dis) {
                    index = v;
                    dis = d[v];
                }
            }
        }
        ans[u] = index;
        
        for (auto &v: g[u]) {
            if (v == fa) continue;
            int old = path[nums[u]];
            path[nums[u]] = u;
            dfs(v, u, depth + 1, path, nums);
            path[nums[u]] = old;
        }
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        for (auto &c: edges) {
            int u = c[0], v = c[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < M; ++j) {
                if (std::gcd(i, j) == 1) prime[i].push_back(j);
            }
        }
        int n = nums.size();
        ans = vector<int>(n, -1);
        auto path = vector<int>(M, -1);
        dfs(0, -1, 0, path, nums);
        return ans;
    }
};