##### 递归例题

- 下面是书上的一些递归例题，对于初学者例题越简单越好。

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
  | [破冰游戏](https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/) | [LCR187.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/LCR187.cpp) | $中等，f(n)表示{0,1,2,...n-1}按照题目玩法后最后一位成员的编号$ |
  |  [消除游戏](https://leetcode.cn/problems/elimination-game/)  | [elimination-game.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/elimination-game.cpp) | $中等，f1(n)表示{1,2,..,n}的所有整数，从左到右先删，再从右到左，再从左到右，依次循环删下去，最后剩下的一个数字$ |
  |   [排序数组](https://leetcode.cn/problems/sort-an-array/)    | [sort-an-array.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/sort-an-array.cpp) |               $入门，f(nums)表示将nums排好序$                |
  | [寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/) | [median-of-two-sorted-arrays.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/median-of-two-sorted-arrays.cpp) | $中等，f(L1, R1, L2, R2, k, nums1, nums2)表示在有序数组nums1中的[L1, R1]范围内，有序数组nums2中的[L2, R2]范围内，寻找第k小的数$ |

##### 递归练习题

- 如下

- |                             题目                             |                           参考代码                           | 简要说明 |
  | :----------------------------------------------------------: | :----------------------------------------------------------: | :------: |
  | [二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/) | [binary-tree-inorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-inorder-traversal.cpp) |  $入门$  |
  | [二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/) | [binary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-postorder-traversal.cpp) |  $入门$  |
  | [N 叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/) | [n-ary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/n-ary-tree-postorder-traversal.cpp) |  $入门$  |
|     [图像渲染](https://leetcode.cn/problems/flood-fill/)     |                                                              |          |
  |  [Lake Counting S](https://www.luogu.com.cn/problem/P1596)   |                                                              |          |
  |      [填涂颜色](https://www.luogu.com.cn/problem/P1162)      |                                                              |          |
  | [可能的二分法](https://leetcode.cn/problems/possible-bipartition/) |                                                              |          |
  |      [新汉诺塔](https://www.luogu.com.cn/problem/P1242)      |                                                              |          |
  |       [约瑟夫](https://www.luogu.com.cn/problem/P1145)       |                                                              |          |
  |  [最短的桥](https://leetcode.cn/problems/shortest-bridge/)   |                                                              |          |
  | [连通网络的操作次数](https://leetcode.cn/problems/number-of-operations-to-make-network-connected/) |                                                              |          |
  |   [螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)    |                                                              |          |
  
  

递归练习题001：[爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)

- 题目描述

  ```
  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
  ```

```
- 题目样例
```

  输入：n = 2
  输出：2
  解释：有两种方法可以爬到楼顶。

    1. 1 阶 + 1 阶
    2. 2 阶

```
- 题目解析
```

  状态的定义：我们定义f(i)表示爬到第i阶台阶的方案数.
  f(i - 1) + 再一次性爬一个台阶，就爬到了第i阶台阶
  f(i - 2) + 再一次性爬二个台阶，就爬到了第i阶台阶
  f(i - 3) + 再一次性爬三个台阶，就爬到了第i阶台阶，但是题目规定"每次你可以爬 1 或 2 个台阶"，所以这种不行。
  所以要爬到第i阶台阶的方案数f(i)可以写成如下的等式：
                              f(i) = f(i - 1) + f(i - 2)
  边界：f(1) = 1, f(2) = 2

- 代码实现
  - 在所有的动态规划实现中，大概分了两种，一种可以叫做"人人为我"，另一种叫做"我为人人"（也叫刷表法）。
  - <div align=center >
      <img alt="aa" src="./pics/dagto.png" style="zoom:70%"/>
      <p> "我为人人"示例图 </p>
    </div>
  - "我为人人"：表示根据$状态i$，可以转移到那些状态。
  - "人人为我”：表示$状态i$, 由其他状态转移而来。
  - <div align=center >
      <img alt="aa" src="./pics/dagfrom.png" style="zoom:70%"/>
      <p> "人人为我"示例图 </p>
    </div>
  - 这两种实现方法，本质是一样的，只是在代码层面，有的题目适合"人人为我”写法，有的题目适合"我为人人"写法，当然大多数题目两种写法都可。
  - 下面就以本题目，展示两种写法，加深大家对不同实现的理解。
    ```cpp
    // "人人为我" 写法
    class Solution {
    public:
      static const int N = 45 + 5;
      int dp[N];
      int climbStairs(int n) {
          dp[1] = 1;
          dp[2] = 2;
          for (int i = 3; i <= n; ++i) {
              dp[i] = dp[i - 1] + dp[i - 2];
          }
          return dp[n];
      }
    };
    ```

```cpp
// "我为人人" 写法
// 状态i 一次性爬一步就到了状态i + 1, 一次性爬二步就到了状态i + 1
class Solution {
public:
  static const int N = 45 + 5;
  int dp[N];
  int climbStairs(int n) {
      dp[1] = 1;
      dp[2] = 1;
      for (int i = 1; i <= n; ++i) {
          dp[i + 1] += dp[i];
          dp[i + 2] += dp[i];
      }
      return dp[n];
  }
};
```

等等，上面我们使用的动态规划的方法，本题的一个递归的实现如下：

class Solution {
public:
  int climbStairs(int n) {
      if (n == 1) return 1;
      if (n == 2) return 2;
      return climbStairs(n - 1) + climbStairs(n - 2);
  } 
};

如果我们把处理过的记录下来，便是记忆化了，本题的一个记忆化搜索的实现如下：

class Solution {
public:
  static const int N = 45 + 5;
  int dp[N];
  int climbStairs(int n) {
      if (n == 1) return 1;
      if (n == 2) return 2;
      if (dp[n] != 0) return dp[n];
      return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
  }
};

在"人人为我" 的写法中，$状态i$只与$状态i - 1$和$状态i - 2$有关，所以我们并不需要存放$状态i - 3, i - 4$,..., 这样可以节约大量的内存，只需少量几个变量即可，这就是我们常说的"滚动数组"优化。

// "人人为我", "滚动数组"优化
class Solution {
public:
  int climbStairs(int n) {
      if (n == 1) return 1;
      if (n == 2) return 2;
      int i1 = 1, i2 = 2, curi;
      for (int i = 3; i <= n; ++i) {
          curi = i1 + i2;
          i1 = i2;
          i2 = curi;
      }
      return curi;
  }
};

至此，我们通过[爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)这道例题，讲解了大量的概念，和与之对应的代码实现。希望能更好的帮助初学者。当然基于"人人为我"的递推式，还可以把递推式变形成"矩阵快速幂"，但这已不属于初学者的范畴，不过在后面的"动态规划的优化"的相关章节会陆续讲解这类比较套路的DP优化。