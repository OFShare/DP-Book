class Solution {
public:
    std::vector<int> ans;
    void dfs(Node* root) {
        ans.push_back(root -> val);
        for (const auto &child: root -> children) dfs(child);
    }
    vector<int> preorder(Node* root) {
        if (!root) return ans;
        dfs(root);
        return ans;
    }
};