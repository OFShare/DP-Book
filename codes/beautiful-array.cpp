class Solution {
public:
    vector<int> beautifulArray(int n) {
        // 边界
        if (n == 1) return {1};

        vector<int> ans;
        auto left = beautifulArray(n / 2);
        auto ritht = beautifulArray(n - n / 2);
        for (auto &c: left) ans.push_back(c * 2);
        for (auto &c: ritht) ans.push_back(c * 2 - 1);
        return ans;
    }
};