class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::map<int, int> mp;
        for (auto &c: nums) mp[c] += 1;

        // 排序后dp，考虑前i个元素[0:i]，remove表示删除第i个元素时, 能获得的最大点数; keep表示保留第i个元素时, 能获得的最大点数
        int remove = 0, keep = 0, ans = -1e9;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int value = (it->first) * (it->second);
            if (it == mp.begin()) {
                remove = 0;
                keep = value;
            }
            else {
                auto newit = it;
                --newit;
                int new_remove = std::max(remove, keep);
                
                int new_keep = std::max({value, value + remove});
                if (newit -> first + 1 != it -> first) {
                    new_keep = std::max(new_keep, value + keep);
                }
                remove = std::move(new_remove);
                keep = std::move(new_keep);
            }

            ans = std::max({ans, remove, keep});
        }
        return ans;
    }
};