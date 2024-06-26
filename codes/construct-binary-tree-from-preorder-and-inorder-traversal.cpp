/*
 *
 *  欢迎阅读:
 *
 *  https://OFShare.github.io/
 *
 *
 *
 */
 
class Solution {
public:
    // 递归构造，无重复元素减轻了编码实现
    // 一颗二叉树，总是可以分成根 + 左子树 + 右子树
    // 对于给定的一颗树的preorder, inorder: 
    //     1. 找到其根
    //     2. 找到其左子树的先序遍历（left_preorder），找到其左子树的中序遍历（right_inorder）,然后递归构造其左子树
    //     3. 找到其右子树的先序遍历（right_preorder），找到其右子树的中序遍历（right_inorder）,然后递归构造其右子树

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        assert(preorder.size() == inorder.size());
        int root = preorder[0], n = preorder.size();
        vector<int> left_inorder, right_inorder;
        for (int i = 0; i < n; ++i) {
            if (inorder[i] == root) {
                if (i - 1 >= 0) left_inorder = vector<int>(inorder.begin(), inorder.begin() + i);
                if (i + 1 < n ) right_inorder = vector<int>(inorder.begin() + i + 1, inorder.end());
                break;
            }
        }

        auto RootPtr = new TreeNode(root);
        int sz1 = left_inorder.size(), sz2 = right_inorder.size();
        if (sz1 > 0) {
            vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + sz1);
            RootPtr -> left = buildTree(left_preorder, left_inorder);
        }
        if (sz2 > 0) {
            vector<int> right_preorder(preorder.begin() + 1 + sz1, preorder.end());
            RootPtr -> right = buildTree(right_preorder, right_inorder);
        }
        return RootPtr;
    }
};