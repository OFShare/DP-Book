/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */
 
class Solution {
public:
    int LIS(const vector<int> &a) {
        vector<int> dp;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            auto it = std::upper_bound(dp.begin(), dp.end(), a[i]);
            if (it == dp.end()) dp.push_back(a[i]);
            else *it = a[i];
        }
        return dp.size();
    }
    // 观察到：分组之后，求LIS
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> v;
            int j = i;
            while (j < n) {
                v.push_back(arr[j]);
                j += k;
            }
            ans += v.size() - LIS(v);
        }
        return ans;
    }
};