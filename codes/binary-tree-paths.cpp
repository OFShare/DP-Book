class Solution {
public:
    vector<string> path, ans;
    void dfs(TreeNode* cur, vector<string> &path) {
        if (cur == nullptr) return;
        path.push_back(std::to_string(cur -> val));
        // 叶子节点
        if (cur -> left == nullptr && cur -> right == nullptr) {
            string t;
            for (int i = 0, len = path.size(); i < len; ++i) {
                if (i == 0) t += path[i];
                else t += "->" + path[i]; 
            }
            ans.push_back(t);
        }
        dfs(cur -> left, path);
        dfs(cur -> right, path);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, path);
        return ans;
    }
};