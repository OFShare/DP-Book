/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 注意这是二叉树，lowestCommonAncestor函数在比较深的节点时返回的是指向p或q的指针，当越往上是返回的是p和q的最近祖先。
    // 只是强调一个递归函数会返回不同的含义
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        auto left = lowestCommonAncestor(root -> left, p, q);
        auto right = lowestCommonAncestor(root -> right, p, q);
        if ((left && right) || (root == p) || (root == q)) return root;
        return left? left: right;
    }
};