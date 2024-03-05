class Solution {
public:
    std::vector<int> ans;
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root -> left);
        dfs(root -> right);
        ans.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};