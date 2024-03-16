class Solution {
public:
  std::vector<int> ans;
    void dfs(TreeNode* root) {
        if (root == NULL) return ;

        ans.push_back(root -> val);    
        dfs(root -> left);
        dfs(root -> right);
  }                                              
    vector<int> preorderTraversal(TreeNode* root) {
      if (root == NULL) return {};

        dfs(root);
        return ans;
    }
};