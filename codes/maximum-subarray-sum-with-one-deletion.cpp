// 解法一
class Solution {
public:
    static const int N = 1e5 + 5, INF = 1e9;
    // dp_left[i]表示前i个元素[0:i]，以第i个位置结尾的，最大连续和
    // dp_right[i]表示后i个元素[i:n)，以第i个位置结尾的，最大连续和
    
    // 答案之一：左边连续最大和 + (删除位置) + 右边连续最大和

    int dp_left[N], dp_right[N];
    int maximumSum(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        int n = arr.size(), ans = -INF;
        for (int i = 0; i < n; ++i)
            dp_left[i] = std::max(arr[i], (i - 1 >= 0? dp_left[i - 1]: 0) + arr[i]);

        for (int i = n - 1; i >= 0; --i)
            dp_right[i] = std::max(arr[i], dp_right[i + 1] + arr[i]);
        
        for (int i = 0; i < n; ++i) {
            int L = i - 1 >= 0? dp_left[i - 1]: 0;
            int R = dp_right[i + 1];
            // 删除第i个位置的元素
            ans = std::max({ans, L + R, (i != 0 ? L: -INF), (i != n - 1? R: -INF)});
            // 不删除
            ans = std::max({ans, dp_left[i], dp_right[i]});
        }
        return ans;
    }
};

// 解法二
class Solution {
public:
    // zero表示考虑前i个元素[0:i], 以第i个位置结尾，恰好删除0个时，的最大值
    // one表示考虑前i个元素[0:i], 以第i个位置结尾，恰好删除1个时，的最大值（值得注意的是虽然以i个元素结尾，但是第i个元素可能并没有被选）

    // 可能大家会习惯性定义，以第i个元素结尾，的最大值。在这个状态定义下，由于以i个元素结尾，看起来就是第i个元素必须取了。
    // 其实我们关心的是以第i个位置结尾时，向左连续的，最大值。而第i个位置上的元素取or删除，是我们的决策。
    // 所以以第i个位置结尾时定义状态就清晰多了
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), zero = -1e9, one = -1e9, ans = -1e9;
        for (int i = 0; i < n; ++i) {
            int new_zero = std::max(arr[i], zero + arr[i]);
            int new_one = std::max(one + arr[i], zero + 0);

            zero = std::move(new_zero);
            one = std::move(new_one);
            ans = std::max({ans, zero, one});
        }
        return ans;
    }
};