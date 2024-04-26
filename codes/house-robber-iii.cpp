/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    // 以root为根的子树，<偷，不偷>时，的最大值
    std::array<int, 2> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};
        auto ret1 = dfs(root -> left);
        auto ret2 = dfs(root -> right);
        
        int steal = root -> val + ret1[1] + ret2[1], non_steal = std::max(ret1[0], ret1[1]) + std::max(ret2[0], ret2[1]);
        ans = std::max(steal, non_steal);
        return {steal, non_steal};
    }
    int rob(TreeNode* root) {
        dfs(root);
        return ans;
    }
};