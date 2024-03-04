##### 如何理解"状态"

- 动态规划一般有以下三种要素：状态的定义，状态的转移，状态的边界。其中动态规划中的“状态”是一个抽象的概念，理解抽象的概念总是比较“虚”，所以我们将尝试将抽象的状态具体化，以实际的例子出发来加以理解。下面是几个具体的状态的定义：
  - 定义状态 $f(x) = 3x^2 + 2x + 11$
  - 定义状态$f(i)表示前i个数的前缀和$
  - ...
  - 定义状态$f(i, j)表示前i个数中选取j个数的方案数$
  - 定义状态$f(i, j, k)表示从节点i走到节点j最多走k步的方案数$

- 我们可以将上面$f$括号里的变量看作一个个具体的状态，状态是来描述问题的、或者说刻画一个局面，一个大问题可能可以分解成几个小问题，也就是状态之间可能可以互相转移，那接下来我们就来谈谈状态的转移。

##### 如何理解“状态的转移”

- 状态的转移也是一种抽象的概念，我们依然从具体的例子理解
  - 在数列{$a_n$}中，$a_1$ = 3，$a_{n+1}$ = $a_n$ + $\frac{1}{n * (n + 1)}$，在这里${a_n}$和${a_{n + 1}}$的关系，就是一种转移。其中状态${a_{n + 1}}$由状态$a_n$转移而来。
  - 比如$f(0) = 0$，$f(1) = 1$, $f(x) = f(x - 1) + f(x - 2)$，状态$f(x)$由状态$f(x - 1)$和状态$f(x - 2$转移而来。
  - 比如 $f[i][j] = max(f[i−1][j],f[i−1][j−w[i]]+c[i])(j>=w[i])$，状态$f[i][j]$由状态$f[i−1][j]$和状态$f[i−1][j−w[i]]$转移而来。
  - ...
- 如果我们把状态看作图的节点，状态之间的转移看作一条有向边，那么就构成我们常说的有向无环图（DAG）。
<div align=center >
    <img alt="xxxx" src="./pics/dag.jpg" style="zoom:30%" />
    <p> 图一 DAG </p>
</div>

##### 如何理解”状态的边界“

- 在数列{$a_n$}中，$a_1$ = 3，$a_{n+1}$ = $a_n$ + $\frac{1}{n * (n + 1)}$，这里$a_1$ = 3 就是边界。
- 比如$f(0) = 0$，$f(1) = 1$, $f(x) = f(x - 1) + f(x - 2)$，这里$f(0) = 0$，$f(1) = 1$就是边界。
- 在上面的图一中，节点$a$就是整个DAG图的起点也就是"边界"，可以看到我们一旦知道了"起点"就可以推导出图中所有节点的值。

##### 如何理解"递归、回溯、记忆化搜索”

- 其实这三个概念"递归、回溯、记忆化搜索"是相互关联的， 我们依旧可以从上面的图一DAG图找到对应的概念。
- 递归：如果我们要解决$问题e$，那么我们先去解决$问题d$、$问题c$、$问题a$，解决$问题d$..., 这里就是一个"递归"的处理概念，将大问题分解为一个个小问题，小问题依旧是相同的处理逻辑，直到分解为最小的问题。最小的问题，往往对应"边界"，在上图中就是$节点a$。
- 回溯：当我们处理$问题e$时，递归的先去处理$问题d$，等到$问题d$处理完后，回到$问题e$时，这就是"回溯"。记住我们递归去处理$问题d$时修改了一些变量，回溯到$问题e$时我们需要把修改的变量重新修改回它们原来的值。
- 记忆化搜索：图一中我们会多次处理$问题c$，$问题d$依赖它，$问题c$也依赖它。所以我们可以在第一次处理$问题c$时，将$问题c$的处理结果保存起来，下次再碰到直接返回即可，这就是"记忆"的意思。


##### 精选题目精讲
- 有了上面的概念，接下来我们将通过大量的习题，加深理解。
- 递归练习题001：[爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)
  - 题目描述
    ```
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
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
    ```
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
    - 等等，上面我们使用的动态规划的方法，本题的一个递归的实现如下：
      ```cpp
      class Solution {
      public:
        int climbStairs(int n) {
            if (n == 1) return 1;
            if (n == 2) return 2;
            return climbStairs(n - 1) + climbStairs(n - 2);
        } 
      };
      ```
    - 如果我们把处理过的记录下来，便是记忆化了，本题的一个记忆化搜索的实现如下：
      ```cpp
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
      ```
    - 在"人人为我" 的写法中，$状态i$只与$状态i - 1$和$状态i - 2$有关，所以我们并不需要存放$状态i - 3, i - 4$,..., 这样可以节约大量的内存，只需少量几个变量即可，这就是我们常说的"滚动数组"优化。
      ```cpp
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
      ```
  - 至此，我们通过[爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)这道例题，讲解了大量的概念，和与之对应的代码实现。希望能更好的帮助初学者。当然基于"人人为我"的递推式，还可以把递推式变形成"矩阵快速幂"，但这已不属于初学者的范畴，不过在后面的"动态规划的优化"的相关章节会陆续讲解这类比较套路的DP优化。
- 递归练习题002：[求 f(x,n)](https://www.luogu.com.cn/problem/B2147)
  - 题目描述
    - 已知 $f(x,n)=\sqrt{n+\sqrt{(n-1)+\sqrt{(n-2)+\sqrt{...+2+\sqrt{1+x}}}}}$。
    - 计算 $f$ 的值。
  - 题目样例
    ```
    输入：x = 4.2 n = 10
    输出：3.68
    ```
  - 题目解析
    ```
    上面这个等式可以看作一个"状态"，式子里的x因为没啥变化，好似常量。
    那么相等于题目给出了"状态"，我们需要找到状态之间的转移，从而把大问题拆解为一个更小的问题。
    很显然，下面的等式成立，即我们找到了一种状态之间的转移。
    ```
  - $$f(x,n)=\sqrt{n + f(x, n - 1)}$$
  - "状态的边界"：$f(x,1)=\sqrt{1+x}$，这就是"最小的问题"，为什么我们要把大问题逐渐拆解为一个个更小的问题？其中原因就在这，因为"最小的问题"我们总是很容易解决。
  - 代码实现
    - 在实现中，dfs的函数声明，就可以看作我们对"状态"的一种在代码层面的表示，函数里面的代码就是对"状态"如何转移的一种描述。
      ```cpp
      #include <bits/stdc++.h>
      using namespace std;

      float dfs(float x, float n) {
        if (n == 1) return std::sqrt(1 + x);
        return std::sqrt(n + dfs(x, n - 1));
      }

      int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
          
        float x, n;
        cin >> x >> n;
        cout << fixed << setprecision(2) << dfs(x, n) << '\n';
        return 0;
      }
      ```
- 递归练习题003：[再求 f(x,n)](https://www.luogu.com.cn/problem/B2148)
  - 题目描述
    - $f(x,n)=\dfrac{x}{n+\dfrac{x}{(n-1)+\dfrac{x}{(n-2)+\dfrac{\vdots}{\cdots+\dfrac{x}{1+x}}}}}$
    - 用递归函数求解。
  - 题目样例
    ```
    输入：x = 1 n = 2
    输出：0.40
    ```
  - 题目解析
    ```
    本题和上一题基本一摸一样，同样都是给出了状态，我们需要找到状态之间的转移。
    显然显然，下面的等式成立。
    ```
  - $$f(x,n)=\dfrac{x}{n+f(x,n-1)}$$
  - 状态的边界：$f(x,1)=\dfrac{x}{1+x}$
  - 代码实现
    - 代码如下
      ```cpp
      #include <bits/stdc++.h>
      using namespace std;

      float dfs(float x, float n) {
        if (n == 1) return x / (1 + x);
        return x / (n + dfs(x, n - 1));
      }

      int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
          
        float x, n;
        cin >> x >> n;
        cout << fixed << setprecision(2) << dfs(x, n) << '\n';
        return 0;
      }
      ```
- 递归练习题004：[二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)
  - 题目描述
    ```
    给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
    ```
  - 题目样例
    - <div align=center >
        <img alt="aa" src="./pics/pre_order.jpg" style="zoom:0%"/>
        <p> 二叉树 </p>
      </div>
    - 输入：root = [1,null,2,3]
    - 输出：[1,2,3]
  - 题目解析
    - 定义状态：$dfs(TreeNode* root)$ 表示根节点root的前序遍历。
    - 有了状态，我们需要找到状态之间的转移，对于根节点的左孩子和右孩子形成的子树，它们依旧是原问题的一个子问题，对于子问题我们同样可以用"状态"描述，见如下代码。
    - 递归的边界：空树我们返回空即可。
  - 代码实现
    - 二叉树的前序遍历
      ```cpp
      class Solution {
      public:
          std::vector<int> ans;
          void dfs(TreeNode* root) {
              if (root == NULL) return ;
              ans.push_back(root -> val);    
              dfs(root -> left);
              dfs(root -> right);
          }                                              

          vector<int> preorderTraversal(TreeNode* root) {
              if (root == NULL) return {};
              dfs(root);
              return ans;
          }
      };
      ```
- 递归练习题005：[二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/description/)
  - 题目描述
    ```
    给你一个二叉树的根节点root，按任意顺序，返回所有从根节点到叶子节点的路径。
  ```
    
  - 题目样例

    - <div align=center >
      <img alt="aa" src="./pics/paths.jpg" style="zoom:0%"/>
      <p>  </p>
      </div>

    - ```
      输入：root = [1,2,3,null,5]
      输出：["1->2->5","1->3"]
      ```

  - 题目解析

    - 容易知道，对于**树**上的任意两个节点u，v 它们之间的路径是唯一的。
    - 本题我们总是从根节点到其他节点，所以在定义状态时没必要对根节点增加一维。所以我们可以这样定义状态，定义状态**dfs(TreeNode* cur)**表示从根节点到当前节点的路径。

  - 代码实现

    - 在下面的实现中，cur和path，一起构成状态。表示当前在cur节点，根节点到cur节点的路径为path（并不包含cur节点的值）。

    - 拿上面的样例，举个例子，比如当前cur在节点5，那么此时path保存的节点为{1, 2}而不是{1, 2, 5}，当前节点5并没有保存在path里。

    - 有了状态，接下来是转移，转移显然就是递归的去跑当前节点的左右孩子节点。当其左右孩子节点都跑完后，我们需要"还原现场"，也即大家口中的"回溯"。既然要"还原现场"，那么我们肯定得知道原来的现场是什么，就是还没进入dfs函数内部的状态，那就是cur和path。在dfs函数内部我们对path做了修改，path.push_back()，所以还原就是path.pop_back()。

    - 在这里，可能很多初学者会疑惑，我们dfs(cur -> left)，dfs(cur -> right)也修改了path呀。其实这还不是不理解"递归"的表现，当dfs(cur -> left)函数执行完后，它也会还原当初进入dfs(cur -> left)时的状态，dfs(cur -> right)同理，所以当下面的代码dfs(cur -> left)和dfs(cur -> right)执行完后，唯一对path做了修改的就只是前面操作的path.push_back()，所以我们最后path.pop_back()也就还原了。

    - 多说一句，对于绝大多数初学者，"递归"，"回溯"基本上就是学习路上最大的拦路虎，有的初学者要花费几周甚至几个月才能理解其中的奥秘。希望大家好好理解，相信你也能够理解计算机中"递归"的美。

      ```cpp
      class Solution {
      public:
          vector<string> path, ans;
          void dfs(TreeNode* cur) {
              if (cur == nullptr) return;
              path.push_back(std::to_string(cur -> val));
              if (cur -> left == nullptr && cur -> right == nullptr) {
                  string t;
                  for (int i = 0, len = path.size(); i < len; ++i) {
                      if (i == 0) t += path[i];
                      else t += "->" + path[i]; 
                  }
                  ans.push_back(t);
              }
              dfs(cur -> left);
              dfs(cur -> right);
              path.pop_back();
          }
          vector<string> binaryTreePaths(TreeNode* root) {
              dfs(root);
              return ans;
          }
      };
      ```

  - 由于计算机中**树**这种结构天然有递归的结构，所以对于初学者练习递归有很大的帮助，下面我找了一些递归练习题，帮助大家加深理解，不过就仅给出参考代码了。

  - 在初学递归练习中，一定要清楚 "状态"是什么，"状态的转移"是什么, "状态的边界"是什么，最后才用代码描述出来。

  - 递归练习题 
    | 题目   | 参考代码 | 简要说明 |
    |:-------:|:-------:|:-------:|
    | [二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/) | x | 略 |
    | [二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/) | x     | 文本6 |
    | [二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/) | x     | 文本6 |
    | [二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) | x     | 文本6 |
    | [N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/) | x     | 文本6 |
    | [N 叉树的前序遍历](https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description/) | x     | 文本6 |
    | [N 叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/) | x     | 文本6 |
    
    