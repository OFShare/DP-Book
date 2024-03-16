class Solution {
public:
    vector<string> path, ans;
    void dfs(TreeNode* cur) {
        if (cur == nullptr) return;
        path.push_back(std::to_string(cur -> val));
        if (cur -> left == nullptr && cur -> right == nullptr) {
            string t;
            for (int i = 0, len = path.size(); i < len; ++i) {
                if (i == 0) t += path[i];
                else t += "->" + path[i]; 
            }
            ans.push_back(t);
        }
        dfs(cur -> left);
        dfs(cur -> right);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};