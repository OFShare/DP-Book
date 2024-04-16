<div align=center >
  <font face="黑体" size=7>动态规划的思考艺术（第一卷题单）</font>
 </div>


##### 递归例题

- 这是[动态规划的思考艺术（第一卷）](https://ofshare.github.io/2024-03-23-hello-algorithm/)的例题题单，方便大家直接练习。当然对于初学者例题一开始越简单越好。

- 状态的定义一般用$f(...)$表示，在代码具体实现时函数一般用$dfs(...)$表示，状态的存放一般用数组$dp(...)$表示。

- 函数的声明：$int \ dfs(int \ i, \ int \ sum, \ const \ int \ \&n, \ const \ vector\!<\!int\!> \ \&nums)$，凡是用**const  + &**表示的变量，都与状态的转移无关。

- 对于绝大多数初学者，$递归$，$回溯$基本上就是学习路上最大的拦路虎，有的初学者要花费几周甚至几个月才能理解其中的奥秘。希望大家好好理解，相信你也能够理解计算机中递归的美。

- |                             题目                             |                           参考代码                           |                           简要说明                           |
  | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
  | [二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/) | [maximum-depth-of-binary-tree.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-depth-of-binary-tree.cpp) | $入门，f(u)表示从当前节点u出发，到最远叶子节点的最长路径上的节点数$ |
  | [二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) | [minimum-depth-of-binary-tree.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/minimum-depth-of-binary-tree.cpp) | $入门，f(u)表示从当前节点u出发，到最近叶子节点的最短路径上的节点数量$ |
  | [N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/) | [maximum-depth-of-n-ary-tree.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-depth-of-n-ary-tree.cpp) | $入门，f(u)表示从当前节点u出发，到最远叶子节点的最长路径上的节点数$ |
  | [二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/) | [binary-tree-preorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-preorder-traversal.cpp) |              $入门，f(u)表示根节点u的前序遍历$               |
  | [N 叉树的前序遍历](https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description/) | [n-ary-tree-preorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/n-ary-tree-preorder-traversal.cpp) |              $入门，f(u)表示根节点u的前序遍历$               |
  |     [求 f(x,n)](https://www.luogu.com.cn/problem/B2147)      | [B2147.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/B2147.cpp) |                            $入门$                            |
  |    [再求 f(x,n)](https://www.luogu.com.cn/problem/B2148)     | [B2148.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/B2148.cpp) |                            $入门$                            |
  |                                                              |                                                              |                                                              |
  |        [子集](https://leetcode.cn/problems/subsets/)         | [subsets.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/subsets.cpp) | $入门，f(i, v)表示前i个数里已经选了哪些数v（还没选择第i个数）枚举第i个元素【选 or 不选】$ |
  |     [子集 II](https://leetcode.cn/problems/subsets-ii/)      | [subsets-ii.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/subsets-ii.cpp) |       $入门，同上，枚举第i个元素 【选几个】，STL语法$        |
  |  [组合总和](https://leetcode.cn/problems/combination-sum/)   | [combination-sum.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/combination-sum.cpp) | $入门，f(i, v, sum)表示前i个数里，已经选了哪些数v（不包含第i个数），这些数的和为sum$ |
  | [组合总和 II](https://leetcode.cn/problems/combination-sum-ii/) | [combination-sum-ii.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/combination-sum-ii.cpp) |             $同上，只是候选集合里的数只能用一次$             |
  | [组合总和 III](https://leetcode.cn/problems/combination-sum-iii/) | [combination-sum-iii.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/combination-sum-iii.cpp) | $入门，f(v, sum)表示使用了那些数字v（递增排序），其和为sum$  |
  |      [组合](https://leetcode.cn/problems/combinations/)      | [combinations.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/combinations.cpp) |         $入门，f(v)表示使用了那些数字v（递增排序）$          |
  |     [全排列](https://leetcode.cn/problems/permutations/)     | [permutations.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/permutations.cpp) |    $入门，f(vis, v)表示当前使用了哪些数字vis，其排列为v$     |
  | [二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/description/) | [binary-tree-paths.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-paths.cpp) | $入门，显式回溯/隐式回溯，f(cur, path)表示从根节点到当前节点cur的路径path（并不包含当前节点的值）$ |
  |                                                              |                                                              |                                                              |
  |        [迷宫](https://www.luogu.com.cn/problem/P1605)        | [P1605.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1605.cpp) | $入门，f(vis, x, y)表示哪些点坐标已经被访问过了vis（并不包含当前节点）, 当前在坐标(x, y)处$ |
  |       [01迷宫](https://www.luogu.com.cn/problem/P1141)       | [P1141.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1141.cpp) | $入门，f(x, y, color, number)表示从某个格子出发走到坐标(x, y)处，已经标记颜色color的格子有number个（当前节点还未被标记）$ |
  |  [自然数的拆分问题](https://www.luogu.com.cn/problem/P2404)  | [P2404.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P2404.cpp) | $入门，f(n, v)表示前面的拆分序列为v，还剩下大小为n的数字需要拆分$ |
  |  [图的 m 着色问题](https://www.luogu.com.cn/problem/P2819)   | [P2819.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P2819.cpp) | $入门，f(u, color)表示当前染色到第u个点（当前节点还未染色），其前面的节点[1, u - 1]都已染好色保存在color中$ |
  |     [求细胞数量](https://www.luogu.com.cn/problem/P1451)     | [P1451.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1451.cpp) | $入门，f(x, y, color)表示从某一个位置出发，当前走到位置(x, y)处，涂色为color$ |
  |      [装箱问题](https://www.luogu.com.cn/problem/P1049)      | [P1049.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1049.cpp) | $入门，f(i, volume)表示前i个物品（第i个物品还未被选择），体积为volume$ |
  |      [部落卫队](https://www.luogu.com.cn/problem/P1692)      | [P1692.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1692.cpp) | $入门，f(i, v)表示前i个居民（还未考虑第i个居民），目前已选出的居民编号为v$ |
  | [八皇后 Checker Challenge](https://www.luogu.com.cn/problem/P1219) | [P1219.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1219.cpp) | $入门，f(i, v)表示前i行（还未填第i行的棋子），填了哪些棋子v$ |
  |                                                              |                                                              |                                                              |
  | [判断二分图](https://leetcode.cn/problems/is-graph-bipartite/) | [is-graph-bipartite.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/is-graph-bipartite.cpp) | $入门，f(u, color)表示从当前节点u出发（当前节点还未染色），对节点u所在的联通块能否染色为二分图$ |
  |   [汉诺塔问题](https://leetcode.cn/problems/hanota-lcci/)    | [hanota-lcci.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/hanota-lcci.cpp) | $入门，f(A, B, c)表示将A柱子里的圆盘，借助B柱子，移到C柱子$  |
  | [优美的排列](https://leetcode.cn/problems/beautiful-arrangement/) | [beautiful-arrangement.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/beautiful-arrangement.cpp) | $入门，f(i, v)表示构造前i个整数perm（第i个位置还未填），使用了哪些数v$ |
  |  [漂亮数组](https://leetcode.cn/problems/beautiful-array/)   | [beautiful-array.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/beautiful-array.cpp) |      $中等，f(n)表示将[1,2,...,n]的排列构造成漂亮数组$       |
  | [破冰游戏](https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/) | [LCR187.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/LCR187.cpp) | $中等，等价映射变换，f(n)表示{0,1,2,...n-1}按照题目玩法后最后一位成员的编号$ |
  |  [消除游戏](https://leetcode.cn/problems/elimination-game/)  | [elimination-game.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/elimination-game.cpp) | $中等，f1(n)表示{1,2,..,n}的所有整数，从左到右先删，再从右到左，再从左到右，依次循环删下去，最后剩下的一个数字$ |
  |   [排序数组](https://leetcode.cn/problems/sort-an-array/)    | [sort-an-array.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/sort-an-array.cpp) |               $入门，f(nums)表示将nums排好序$                |
  | [寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/) | [median-of-two-sorted-arrays.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/median-of-two-sorted-arrays.cpp) | $中等，f(L1, R1, L2, R2, k, nums1, nums2)表示在有序数组nums1中的[L1, R1]范围内，有序数组nums2中的[L2, R2]范围内，寻找第k小的数$ |

##### 递归练习题

- 如下，只给出参考代码

- |                             题目                             |                           参考代码                           | 简要说明 |
  | :----------------------------------------------------------: | :----------------------------------------------------------: | :------: |
  | [二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/) | [binary-tree-inorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-inorder-traversal.cpp) |  $入门$  |
  | [二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/) | [binary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-postorder-traversal.cpp) |  $入门$  |
  | [N 叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/) | [n-ary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/n-ary-tree-postorder-traversal.cpp) |  $入门$  |
| [二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/) | [lowest-common-ancestor-of-a-binary-tree.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/lowest-common-ancestor-of-a-binary-tree.cpp) |          |
  |     [图像渲染](https://leetcode.cn/problems/flood-fill/)     | [flood-fill.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/flood-fill.cpp) |          |
  | [岛屿的周长](https://leetcode.cn/problems/island-perimeter/) | [island-perimeter.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/island-perimeter.cpp) |          |
  | [边界着色](https://leetcode.cn/problems/coloring-a-border/)  | [coloring-a-border.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/coloring-a-border.cpp) |          |
  |  [Lake Counting S](https://www.luogu.com.cn/problem/P1596)   | [P1596.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1596.cpp) |          |
  |      [填涂颜色](https://www.luogu.com.cn/problem/P1162)      | [P1162.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1162.cpp) |          |
  | [UCV2013H - Slick](https://www.luogu.com.cn/problem/SP15436) |                                                              |          |
  | [AT_abc015_3](https://www.luogu.com.cn/problem/AT_abc015_3)  | [AT_abc015_3.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/AT_abc015_3.cpp) |          |
  | [可能的二分法](https://leetcode.cn/problems/possible-bipartition/) |                                                              |          |
  |      [新汉诺塔](https://www.luogu.com.cn/problem/P1242)      |                                                              |          |
  |       [约瑟夫](https://www.luogu.com.cn/problem/P1145)       |                                                              |          |
  |  [最短的桥](https://leetcode.cn/problems/shortest-bridge/)   |                                                              |          |
  | [连通网络的操作次数](https://leetcode.cn/problems/number-of-operations-to-make-network-connected/) |                                                              |          |
  |   [螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)    |                                                              |          |
  |   [互质树](https://leetcode.cn/problems/tree-of-coprimes/)   |                                                              |          |
  
