class Solution {
public:
    std::vector<int> ans;
    void dfs(Node* root) {
        for (const auto &child: root -> children) dfs(child);
        ans.push_back(root -> val);
    }
    vector<int> postorder(Node* root) {
        if (!root) return ans;
        dfs(root);
        return ans;
    }
};