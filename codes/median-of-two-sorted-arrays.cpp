class Solution {
public:
    // 中位数：转化成寻找两个有序数组中的第k小的数
    // k -> k/2 -> k/4 -> ...
    // 每次排除k/2个元素
    int dfs(int L1, int R1, int L2, int R2, int k, const vector<int>& nums1, const vector<int>& nums2) {
        // 递归边界一：第k小的数在nums2中
        if (L1 > R1) return nums2[L2 + k - 1];
        // 递归边界二：第k小的数在nums1中
        if (L2 > R2) return nums1[L1 + k - 1];
        // 递归边界三：两者取小
        if (k == 1) return std::min(nums1[L1], nums2[L2]);

        int mid1 = std::min(L1 + k / 2 - 1, R1);
        int mid2 = std::min(L2 + k / 2 - 1, R2);
        // 排除k/2个数字后，在剩下的范围内继续搜（k - k/2）小的数
        if (nums1[mid1] < nums2[mid2]) return dfs(mid1 + 1, R1, L2, R2, k - (mid1 - L1 + 1), nums1, nums2);
        return dfs(L1, R1, mid2 + 1, R2, k - (mid2 - L2 + 1), nums1, nums2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // 奇数
        if ((n1 + n2) % 2) return dfs(0, n1 - 1, 0, n2 - 1, (n1 + n2 + 1) / 2, nums1, nums2);
        // 偶数
        else {
            int a = dfs(0, n1 - 1, 0, n2 - 1, (n1 + n2 ) / 2, nums1, nums2);
            int b = dfs(0, n1 - 1, 0, n2 - 1, (n1 + n2 ) / 2 + 1, nums1, nums2);
            return 1.0 * (a + b) / 2;
        }
    }
};