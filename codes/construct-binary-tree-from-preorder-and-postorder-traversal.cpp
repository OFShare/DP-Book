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
    // 对于给定的一颗树的preorder, postorder: 
    //     1. 找到其根
    //     2. 找到其左子树的前序遍历（left_preorder），找到其左子树的后序遍历（right_postorder）,然后递归构造其左子树
    //     3. 找到其右子树的前序遍历（right_preorder），找到其右子树的后序遍历（right_postorder）,然后递归构造其右子树

    // 左子树的前序遍历的所有元素，肯定等于，左子树的后续遍历的所有元素，毕竟操作都是同一个左子树只是一个操作是前序一个操作是后序。
    // 下面的实现中set<int> st1就是利用了这一点
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        assert(preorder.size() == postorder.size());
        int root = preorder[0], n = preorder.size();
        set<int> st1;
        for (int i = 1; i < n; ++i) {
            st1.insert(preorder[i]);
            if (st1 == set<int>(postorder.begin(), postorder.begin() + i)) break;
        }

        auto RootPtr = new TreeNode(root);
        int sz1 = st1.size();
        if (sz1 > 0) {
            vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + sz1);
            vector<int> left_postorder(postorder.begin(), postorder.begin() + sz1);
            RootPtr -> left = constructFromPrePost(left_preorder, left_postorder);

            if (n - sz1 - 1 > 0) {
                vector<int> right_preorder(preorder.begin() + 1 + sz1, preorder.end());
                vector<int> right_postorder(postorder.begin() + sz1, postorder.end() - 1);
                RootPtr -> right = constructFromPrePost(right_preorder, right_postorder);
            }
        }
        return RootPtr;
    }
};