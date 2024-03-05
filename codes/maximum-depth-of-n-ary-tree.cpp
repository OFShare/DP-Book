class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int ans = 1;
        for (auto &child: root -> children) ans = std::max(ans, maxDepth(child) + 1);
        return ans;
    }
};