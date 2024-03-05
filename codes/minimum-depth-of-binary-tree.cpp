class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ans = 1e9;
        if (root -> left) ans = std::min(ans, minDepth(root -> left) + 1);
        if (root -> right) ans = std::min(ans, minDepth(root -> right) + 1);
        return ans == 1e9? 1: ans;
    }
};