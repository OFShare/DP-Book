##### 递归例题

- 下面是书上的一些递归例题，对于初学者例题越简单越好

- |                             题目                             |                           参考代码                           |             简要说明              |
  | :----------------------------------------------------------: | :----------------------------------------------------------: | :-------------------------------: |
  | [二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/) | [maximum-depth-of-binary-tree.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-depth-of-binary-tree.cpp) |               入门                |
  | [二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) | [minimum-depth-of-binary-tree.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/minimum-depth-of-binary-tree.cpp) |               入门                |
  | [N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/) | [maximum-depth-of-n-ary-tree.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-depth-of-n-ary-tree.cpp) |               入门                |
  | [二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/) |                                                              |               入门                |
  | [N 叉树的前序遍历](https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description/) | [n-ary-tree-preorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/n-ary-tree-preorder-traversal.cpp) |               入门                |
  |     [求 f(x,n)](https://www.luogu.com.cn/problem/B2147)      |                                                              |               入门                |
  |    [再求 f(x,n)](https://www.luogu.com.cn/problem/B2148)     |                                                              |               入门                |
  |        [子集](https://leetcode.cn/problems/subsets/)         |                                                              |    枚举第i个元素【选 or 不选】    |
  |     [子集 II](https://leetcode.cn/problems/subsets-ii/)      |                                                              | 枚举第i个元素 【选几个】，STL语法 |
  |  [组合总和](https://leetcode.cn/problems/combination-sum/)   |                                                              |                                   |
  | [组合总和 II](https://leetcode.cn/problems/combination-sum-ii/) |                                                              |                                   |
  | [组合总和 III](https://leetcode.cn/problems/combination-sum-iii/) |                                                              |                                   |
  |      [组合](https://leetcode.cn/problems/combinations/)      |                                                              |                                   |
  |     [全排列](https://leetcode.cn/problems/permutations/)     |                                                              |             回溯初步              |
  | [二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/description/) |                                                              |             回溯初步              |
  |                                                              |                                                              |                                   |
  | [二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/) | [binary-tree-inorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-inorder-traversal.cpp) |               入门                |
  | [二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/) | [binary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-postorder-traversal.cpp) |               入门                |
  |                                                              |                                                              |                略                 |
  |                                                              |                                                              |                略                 |
  |                                                              |                                                              |                略                 |
  |                                                              |                                                              |                                   |
  | [N 叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/) | [n-ary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/n-ary-tree-postorder-traversal.cpp) |                略                 |

##### 递归练习题

- 如下

- |                             题目                             |                           参考代码                           | 简要说明 |
  | :----------------------------------------------------------: | :----------------------------------------------------------: | :------: |
  | [二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/) | [binary-tree-inorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-inorder-traversal.cpp) |   入门   |
  | [二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/) | [binary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/binary-tree-postorder-traversal.cpp) |   入门   |
  | [N 叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/) | [n-ary-tree-postorder-traversal.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/n-ary-tree-postorder-traversal.cpp) |    略    |

  

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