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
    // 对于给定的一颗树的inorder, postorder: 
    //     1. 找到其根
    //     2. 找到其左子树的中序遍历（left_inorder），找到其左子树的后序遍历（right_postorder）,然后递归构造其左子树
    //     3. 找到其右子树的中序遍历（right_inorder），找到其右子树的后序遍历（right_postorder）,然后递归构造其右子树

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        assert(postorder.size() == inorder.size());
        int root = postorder[postorder.size() - 1], n = inorder.size();
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
            vector<int> left_postorder(postorder.begin(), postorder.begin() + sz1);
            RootPtr -> left = buildTree(left_inorder, left_postorder);
        }
        if (sz2 > 0) {
            vector<int> right_postorder(postorder.begin() + sz1, postorder.end() - 1);
            RootPtr -> right = buildTree(right_inorder, right_postorder);
        }
        return RootPtr;
    }
};