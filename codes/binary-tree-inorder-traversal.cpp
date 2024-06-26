class Solution {
public:
    std::vector<int> ans;
    void dfs(TreeNode* root) {
        if (root == NULL) return ;
        dfs(root -> left);
        ans.push_back(root -> val);
        dfs(root -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        dfs(root);
        return ans;
    }
};