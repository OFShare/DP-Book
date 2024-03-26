<div align=center >
  <font face="黑体" size=7>动态规划的思考艺术（第一卷）</font>
 </div>

##### 写在前面的话

- 我的高中位于一个小县城，直到我进入大学之前，我从未听说过"编程"这个词。很巧的是，我在大学选择了计算机专业，这是我第一次接触到计算机编程。我清楚地记得，在大二的时候，我第一次学习了数据结构。是的，你没有看错，尽管我是计算机专业的学生，但我在大一的整个学年都在享受大学生活。这是很多新来的大学生的常态，他们经历了高三的压力，终于考上了大学，怎能不好好享受一下呢？现在回想起来，我确实浪费了很多时间，我希望这能给正在阅读这篇文章的同学们敲响警钟。我记得当时在课堂上第一次接触到递归，我完全懵了。在此之前，我学习了基本的循环语句，条件语句等基本语法，我以为我可以理解任何程序，只要我一行一行地看下去。但现在我发现，事实并非如此，竟然还有函数自己调用自己，我完全不能理解。直到很长一段时间后，我才真正理解了递归，理解了递归的美。基于我的经验，我深知初学者应该如何开始学习，我认为初学者应该首先完全理解递归和回溯，然后再学习动态规划就会得心应手。因此，这本书的第一部分，专门针对初学者，帮助他们掌握递归和回溯的精髓。我希望这本书能为初学者提供一些指导。很久以前，我就有写一本书的想法，也希望能为这个世界留下一些痕迹。于是，这本书就这样诞生了。让我们一起来探索递归的美妙吧！
- “什么？你说那个天生废灵根的宗门弃子修成了至尊境界。”
- 人生如此复杂，机会多得像稠密图，我们没理由认输。尽管我们走不了最短路，但图仍是连通图，TLE之前，没有一个节点叫失败。
- 人生就像动态规划，你的一个又一个阶段是由上天安排的，而你，决定的是在这一阶段可以由上一阶段的哪些状态转移而来。越勤奋，越幸运，并不代表这一次你决策的方向有多么优秀，却代表着现在的这一个状态能够续写多少可能的结果。

##### 如何理解"状态"

- 动态规划在具体实现时一般有以下三种要素：状态的定义，状态的转移，状态的边界。其中动态规划中的“状态”是一个抽象的概念，理解抽象的概念总是比较“虚”，所以我们将尝试把抽象的状态具体化，以实际的例子出发来加以理解。下面是几个具体的状态的定义：
  - 定义状态$f(i)表示前i个数的前缀和$
  - 定义状态$f(i, j)表示前i个数中选取j个数的方案数$
  - 定义状态$f(i, j, k)表示从节点i走到节点j最多走k步的花费最小值$
  - ...

- 我们可以将上面$f$括号里的变量看作一个个具体的状态，状态是来描述问题的、或者说刻画一个局面，一个大问题往往可以分解成几个小问题，也就是状态之间可以互相转移，那接下来我们就来谈谈状态的转移。

##### 如何理解“状态的转移”

- 状态的转移也是一种抽象的概念，我们依然从具体的例子理解
  - 在数列{$a_n$}中，$a_1$ = 3，$a_{n+1}$ = $a_n$ + $\frac{1}{n * (n + 1)}$，在这里${a_n}$和${a_{n + 1}}$的关系，就是一种转移。其中状态${a_{n + 1}}$由状态$a_n$转移而来。
  - 比如$f(0) = 0$，$f(1) = 1$, $f(x) = f(x - 1) + f(x - 2)$，状态$f(x)$由状态$f(x - 1)$和状态$f(x - 2$转移而来。
  - 比如 $f(i, j) = max(f(i - 1, j), f(i - 1, j - w(i)) + v(i)) (j >= w(i))$，状态$f(i, j)$由状态$f(i - 1, j)$和状态$f(i - 1, j - w(i))$转移而来。
  - ...
- 如果我们把状态看作图的节点，状态之间的转移看作一条有向边，那么就构成我们常说的有向无环图（DAG）。
<div align=center >
    <img alt="xxxx" src="../pics/dag.jpg" style="zoom:50%" />
    <p> 图一 DAG </p>
</div>



##### 如何理解”状态的边界“

- 在数列{$a_n$}中，$a_1$ = 3，$a_{n+1}$ = $a_n$ + $\frac{1}{n * (n + 1)}$，这里$a_1$ = 3 就是边界（或者说起点）。
- 比如$f(0) = 0$，$f(1) = 1$, $f(x) = f(x - 1) + f(x - 2)$，这里$f(0) = 0$，$f(1) = 1$就是边界。
- 在上面的图一中，节点$a$就是整个DAG图的起点也就是"边界"，可以看到我们一旦知道了"起点"就可以推导出图中所有节点的值。
  - PS：状态的边界，边界可以是起点，也可以是终点。在具体实现中，我们往往更关注起点。在以后不特殊说明，都指代起点。
  - PS：状态的边界，往往对应"最小的问题"，是我们最容易解决的问题。

##### 如何理解"递归、回溯、记忆化搜索”

- 其实这三个概念"递归、回溯、记忆化搜索"是相互关联的， 我们依旧可以从上面的图一DAG图中找到对应的概念。
- 递归：如果我们要解决$问题e$，那么我们先去解决$问题d$、$问题c$、$问题a$，解决$问题d$..., 这里就是一个"递归"的处理概念，将大问题分解为一个个小问题，小问题依旧是相同的处理逻辑，直到分解为最小的问题。最小的问题，往往对应"边界"，在上图中就是$节点a$。
- 回溯：当我们处理$问题e$时，递归的先去处理$问题d$，等到$问题d$处理完后，回到$问题e$时，这就是"回溯"。
  - 记住我们递归去处理$问题d$时修改了一些变量，回溯到$问题e$时我们需要把修改的变量重新修改回它们原来的值，保持在回到$问题e$​时的状态不变。
- 记忆化搜索：图一中我们会多次处理$问题c$，$问题d$依赖它，$问题e$也依赖它。所以我们可以在第一次处理$问题c$时，将$问题c$的处理结果保存起来，下次再碰到直接返回即可，这就是"记忆"的意思。
  - 以上就是在实现动态规划时的一些理论知识，计算机学科是一门注重实践的科目，所以我们需要通过练习大量的习题加深对动态规划的理解。
  - 学习动态规划之前，我们需要确保自己已经理解"递归"了，接下来我们就先从一些简单的递归问题开始。
    - 由于计算机中**树**这种结构天然有递归的结构（如果我们把一颗有根树，节点u和其孩子节点v连一条有向边，这棵树自然就是DAG图了）所以对于初学者练习递归有很大的帮助，下面我找了一些递归练习题，帮助大家加深理解。
    - 在初学递归练习中，一定要清楚 "状态"是什么，"状态的转移"是什么，"状态的边界"是什么，最后才用代码描述出来。

##### 递归题目精讲

- 例题A_001：[二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

    - 题目描述

        ```
        给定一个二叉树root，返回其最大深度。
        二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。
        ```

    - 题目样例

      <div align=center >
      <img alt="aa" src="../pics/maximum-depth-of-binary-tree.jpg" style="zoom:0%"/>
      <p> 样例 </p>
      </div>

      ```
      输入：root = [3,9,20,null,null,15,7]
      输出：3
      ```

    - 题目解析

      ```
      状态的定义：f(u)表示从当前节点u出发，到最远叶子节点的最长路径上的节点数。
      状态的转移：当前节点u的状态，可以由其孩子节点v，转移而来。（数学形式上的表达见下）
      状态的边界：叶子节点or空节点。
      ```

      - 状态的转移：$f(u)=\max \{f(v) + 1\}, v 是 u的孩子节点$
      - 状态的边界：
        - $f(u) = 0, u是叶子节点下面的空节点$
        - $f(u) = 1, u是叶子节点$

    - 代码实现

      - 如下

        ```cpp
        class Solution {
        public:
            int maxDepth(TreeNode* root) {
                if (!root) return 0;
                return std::max(maxDepth(root -> left), maxDepth(root -> right) ) + 1;
            }
        };
        ```

- 例题A_002：[二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

  - 题目描述

    ```
    给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
    说明：叶子节点是指没有子节点的节点。
    ```

  - 题目样例

    <div align=center >
    <img alt="aa" src="../pics/maximum-depth-of-binary-tree.jpg" style="zoom:0%"/>
    <p> 样例 </p>
    </div>

    ```
    输入：root = [3,9,20,null,null,15,7]
    输出：2
    ```

  - 题目解析

    ```
    状态的定义：f(u)表示从当前节点u出发，到最近叶子节点的最短路径上的节点数量。
    状态的转移：当前节点u的状态，可以由其孩子节点v，转移而来。
    状态的边界：叶子节点or空节点。
    ```

    - 状态的转移：$f(u)=\min \{f(v) + 1\}, v 是 u的孩子节点$
    - 状态的边界：
      - $f(u) = 0, u是叶子节点下面的空节点$
      - $f(u) = 1, u是叶子节点$

  - 代码实现

    - 如下

      ```cpp
      class Solution {
      public:
          int minDepth(TreeNode* root) {
              if (!root) return 0;
              int ans = 1e9;
              if (root -> left) ans = std::min(ans, minDepth(root -> left) + 1);
              if (root -> right) ans = std::min(ans, minDepth(root -> right) + 1);
              return ans == 1e9? 1: ans;
          }
      };
      ```

- 例题A_003：[N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/)

  - 题目描述

    ```
    给定一个N叉树，找到其最大深度。
    最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
    ```

  - 题目样例

    <div align=center >
    <img alt="aa" src="../pics/maximum-depth-of-n-ary-tree.png" style="zoom:0%"/>
    <p> 样例 </p>
    </div>

    ```
    输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    输出：5
    ```

  - 题目解析
    
    ```
    状态的定义：f(u)表示从当前节点u出发，到最远叶子节点的最长路径上的节点数。
    状态的转移：当前节点u的状态，可以由其孩子节点v，转移而来。
  状态的边界：叶子节点or空节点。
    ```
    
    - 状态的转移：$f(u)=\max \{f(v) + 1\}, v 是 u的孩子节点$
    - 状态的边界：
      - $f(u) = 0, u是叶子节点下面的空节点$
      - $f(u) = 1, u是叶子节点$
    
  - 代码实现

    - 如下

      ```cpp
      class Solution {
      public:
          int maxDepth(Node* root) {
              if (!root) return 0;
              int ans = 1;
              for (auto &child: root -> children) ans = std::max(ans, maxDepth(child) + 1);
              return ans;
          }
      };
      ```

- 例题A_004：[二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)

  - 题目描述

    ```
    给你二叉树的根节点root，返回它节点值的前序遍历（根-左子树-右子树）。
    ```

  - 题目样例

    <div align=center >
    <img alt="aa" src="../pics/pre_order.jpg" style="zoom:0%"/>
    <p> 二叉树 </p>
    </div>

    ```
    输入：root = [1,null,2,3]
    输出：[1,2,3]
    ```

  - 题目解析

    ```
    状态的定义：f(u)表示根节点u的前序遍历。
    状态的转移：当前节点u的状态，可以由其孩子节点v，转移而来。对于根节点的左孩子和右孩子形成的子树，它们依旧是原问题的一个子问题。
    状态的边界：空树我们返回空即可
    ```

    - 状态的转移：$f(u) = val(u) + f(L) + f(R), L是左孩子节点，R是右孩子节点，val(u)是当前u节点的值$
    - 状态的边界：$f(u) = 空，u是叶子节点下面的空节点$

  - 代码实现
    
    - 如下
      
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

- 例题A_005：[N 叉树的前序遍历](https://leetcode.cn/problems/n-ary-tree-preorder-traversal/)

  - 题目描述

    ```
    给定一个n叉树的根节点root，返回其节点值的前序遍历。
    ```

  - 题目样例

    <div align=center >
    <img alt="aa" src="../pics/n-ary-tree-preorder-traversal.png" style="zoom:0%"/>
    <p> N叉树样例 </p>
    </div>

    ```
    输入：root = [1,null,3,2,4,null,5,6]
    输出：[1,3,5,6,2,4]
    ```

  - 题目分析

    ```
    状态的定义：f(u)表示根节点u的前序遍历。
    状态的转移：当前节点u的状态，可以由其孩子节点v，转移而来。
    状态的边界：空树我们返回空即可
    ```

    - 状态的转移：$f(u) = val(u) + f(L1) + f(L2) + f(L3) + ..., L1, L2, L3, ...是u节点从左往右依次标号的的孩子节点$
    - 状态的边界：$f(u) = val(u)，u是叶子节点，val(u)是当前u节点的值$

  - 代码实现

    - 如下

      ```cpp
      class Solution {
      public:
          std::vector<int> ans;
          void dfs(Node* root) {
              ans.push_back(root -> val);
              for (const auto &child: root -> children) dfs(child);
          }
          vector<int> preorder(Node* root) {
              if (!root) return ans;
              dfs(root);
              return ans;
          }
      };
      ```

- 例题A_006：[求 f(x,n)](https://www.luogu.com.cn/problem/B2147)
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
    上面这个等式可以看作一个"状态"，式子里的x因为没啥变化，看作似常量。
    那么相当于题目给出了"状态"，我们需要找到状态之间的转移，从而把大问题拆解为一个更小的问题。
    很显然，下面的等式成立，即我们找到了一种状态之间的转移。
    ```
    
    - 状态的转移：$f(x,n)=\sqrt{n + f(x, n - 1)}$
    
    - 状态的边界：$f(x,1)=\sqrt{1+x}$，这就是"最小的问题"，为什么我们要把大问题逐渐拆解为一个个更小的问题？其中原因就在这，因为"最小的问题"我们总是很容易解决。
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
  
- 例题A_007：[再求 f(x,n)](https://www.luogu.com.cn/problem/B2148)
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
    显然下面的等式成立。
    ```
    
    - 状态的转移：$f(x,n)=\dfrac{x}{n+f(x,n-1)}$
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
  
- 例题A_008：[子集](https://leetcode.cn/problems/subsets/)

  - 题目描述

    ```
    给你一个整数数组nums，数组中的元素互不相同，返回该数组所有可能的子集。
    1<= nums.length <= 10
    ```

  - 题目样例

    ```
    输入：nums = [1,2,3]
    输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    ```

  - 题目解析

    ```
    状态的定义：f(i, v)表示前i个数里已经选了哪些数v（还没选择第i个数）。
    状态的转移：下一个数即第i个数选 or 不选。
    状态的边界：已经考虑完所有数的时候。
    ```

    - 状态的转移：$f(i, v) \rightarrow f(i + 1, newv), 根据第i个数选or不选转移到i+1去$
    - 状态的边界：$f(n, v), n == nums.size()$
  
  - 代码实现
    
    - 如下
      
      ```cpp
      class Solution {
    public:
          vector<vector<int>> ans;
          void dfs(int i, vector<int> v, const vector<int>& nums) {
              if (i == nums.size()) {
                  ans.push_back(v);
                  return ;
              }
              // 不选第i个数
              dfs(i + 1, v, nums);
              // 选第i个数
              v.push_back(nums[i]);
              dfs(i + 1, v, nums);
          }
          vector<vector<int>> subsets(vector<int>& nums) {
              vector<int> v;
              dfs(0, v, nums);
              return ans;
          }
      };
      ```
  
- 例题A_009：[子集 II](https://leetcode.cn/problems/subsets-ii/)

  - 题目描述

    ```
    给你一个整数数组nums，其中可能包含重复元素，请你返回该数组所有可能的子集。
    1 <= nums.length <= 10
    ```

  - 题目样例

    ```
    输入：nums = [1,2,2]
    输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
    ```

  - 题目解析

    ```
    本题和上一题唯一的区别就是含有重复的元素，不过本质和上一题没啥太大区别（举一反三的能力）。
    上一题由于每个元素都不重复，即每个元素要么选0个，要么选1个。
    这一题由于有重复，即每个元素要么选0个，要么选1个，要么选2个，要么选3个，依次类推。
    
    状态的定义：f(i, v)表示前i个数里已经选了哪些数v（还没选择第i个数）。
    状态的转移：下一个数即第i个数一次性选多少个。
    状态的边界：已经考虑完所有数的时候。
    ```

    - 状态的转移：$f(i, v) \rightarrow f(i + 1, newv), 根据第i个数选几个转移到i+1去$
    - 状态的边界：$f(n, v)，n == mp.end()$

  - 代码实现

    - 如下，当然你把这份代码提交到上一题依旧是可以过上一题的

    - 代码里有STL map, 迭代器iterator，自动类型推导auto的语法，如果不熟悉，借机学习下

      ```cpp
      class Solution {
      public:
          using MAP = std::map<int, int>;
          // <元素, 个数>
          MAP mp;
          vector<vector<int>> ans;
          void dfs(MAP::iterator it, vector<int> v) {
              if (it == mp.end()) {
                  ans.push_back(v);
                  return ;
              }
              // cnt 表示当前元素选几个
              for (int cnt = 0; cnt <= it -> second; ++cnt) {
                  auto newv = v;
                  auto newit = it;
                  for (int i = 0; i < cnt; ++i) {
                      newv.push_back(it -> first);
                  }
                  dfs(++newit, newv);
              }
          }
          vector<vector<int>> subsetsWithDup(vector<int>& nums) {
              for (auto &num: nums) mp[num] += 1;
              vector<int> v;
              dfs(mp.begin(), v);
              return ans;
          }
      };
      ```

- 例题A_010：[组合总和](https://leetcode.cn/problems/combination-sum/)

  - 题目描述

    ```
    给定一个候选人编号的无重复元素集合candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。
    candidates中的每个数字在每个组合中可以使用无限次。
    ```

  - 题目样例

    ```
    输入：candidates = [2,3,6,7], target = 7
    输出：[[2,2,3],[7]]
    解释：
    2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
    7 也是一个候选， 7 = 7 。
    仅有这两种组合。
    ```

  - 题目解析

    ```
    状态的定义：f(i, v, sum)表示前i个数里，已经选了哪些数v（不包含第i个数），这些数的和为sum。
    状态的转移：考虑第i个数选多少次。
    状态的边界：已经考虑完所有数的时候。
    ```

    - 状态的定义：$f(i, v, sum) \rightarrow f(i + 1, newv, newsum), 根据第i个元素选几个转移到i+1去$
    - 状态的边界：$f(n, v, sum), n == 数组大小$

  - 代码实现

    - 如下

      ```cpp
      class Solution {
      public:
          vector<vector<int>> ans;
          void dfs(int i, vector<int> v, int sum, const vector<int>& candidates, const int &target) {
              // 递归的边界
              if (i == candidates.size()) {
                  if (sum == target) ans.push_back(v);
                  return ;
              }
              // 枚举第i个数选几个
              for (int cnt = 0; ; ++cnt) {
                  if (sum + cnt * candidates[i] > target) break;
                  vector<int> newv = v;
                  for (int k = 0; k < cnt; ++k) newv.push_back(candidates[i]);
                  dfs(i + 1, newv, sum + cnt * candidates[i], candidates, target);
              }
          }
          vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
              vector<int> v;
              dfs(0, v, 0, candidates, target);
              return ans;
          }
      };
      ```

- 例题A_011：[组合总和 II](https://leetcode.cn/problems/combination-sum-ii/)

  - 题目描述

    ```
    给定一个候选人编号的集合candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合。
    candidates中的每个数字在每个组合中只能使用一次，注意candidates中有相同的数。
    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    ```

  - 题目样例

    ```
    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    输出:
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
    ```

  - 题目解析

    ```
    状态的定义：f(i, v, sum)表示前i个数里，已经选了哪些数v（不包含第i个数），这些数的和为sum。
    状态的转移：考虑第i个数选多少次。
    状态的的边界：已经考虑完所有数的时候。
    ```

    - 状态的定义：$f(i, v, sum) \rightarrow f(i + 1, newv, newsum), 根据第i个元素选几个转移到i+1去$
    - 状态的边界：$f(n, v, sum), n == 数组大小$

  - 代码实现

    - 如下

    - 考虑前i个数的时候，是a数组里的前i个数哟，并非candidates

      ```cpp
      class Solution {
      public:
          static const int N = 50 + 5;
          vector<vector<int>> ans;
          // 记录每个数出现的个数，比如a[7]=4, 表示7这个数字出现了4次。
          int a[N];
          void dfs(int i, vector<int> v, int sum, const int &target) {
              if (i >= N) {
                  if (sum == target) ans.push_back(v);
                  return ;
              }
              // 枚举第i个数选了多少个
              for (int cnt = 0; cnt <= a[i]; ++cnt) {
                  if (sum + cnt * i > target) break;
                  vector<int> newv = v;
                  for (int k = 0; k < cnt; ++k) newv.push_back(i);
                  dfs(i + 1, newv, sum + cnt * i, target);
              }
          }
          vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
              for (auto &c: candidates) a[c] += 1;
              vector<int> v;
              dfs(0, v, 0, target);
              return ans;
          }
      };
      ```

- 例题A_012：[组合总和 III](https://leetcode.cn/problems/combination-sum-iii/)

  - 题目描述

    ```
    找出所有相加之和为n的k个数的组合，且满足下列条件：
      - 只使用数字1到9
      - 每个数字最多使用一次 
    返回所有可能的有效组合的列表。
    ```

  - 题目样例

    ```
    输入: k = 3, n = 7
    输出: [[1,2,4]]
    解释:
    1 + 2 + 4 = 7
    没有其他符合的组合了。
    ```

  - 题目解析

    ```
    状态的定义：f(v, sum)表示使用了那些数字v（递增排序），其和为sum
    状态的转移：枚举使用下一个数字，且比上一个数字大
    状态的边界：所有数字都考虑完了
    ```

    - 状态的定义：$f(v, sum) \rightarrow f(newv, newsum), 根据下一个数字选谁转移$
    - 状态的边界：$f(v, sum), v.size() == k$
    - 状态的剪枝：
      - $由于可选的数字都是正数，一旦sum超过n，后面再选就没意义了$
      - $v.size() > k, 选的数字超过k个了，后面再选就没意义了$

  - 代码实现

    - 如下

      ```cpp
      class Solution {
      public:
          vector<vector<int>> ans;
          void dfs(vector<int> v, int sum, const int &k, const int &n) {
              // 剪枝
              if (v.size() > k || sum > n) return ;
              // 递归的边界
              if (v.size() == k && sum == n) {
                  ans.push_back(v);
                  return ;
              }
              // 枚举使用下一个数, v里的数字严格递增存放
              for (int num = v.back() + 1; num <= 9; ++num) {
                  auto newv = v;
                  newv.push_back(num);
                  dfs(newv, sum + num, k, n);
              }
          }
          vector<vector<int>> combinationSum3(int k, int n) {
              for (int num = 1; num <= 9; ++num) {
                  vector<int> v = {num};
                  dfs(v, num, k, n);
              }
              return ans;
          }
      };
      ```

- 例题A_013：[组合](https://leetcode.cn/problems/combinations/)

  - 题目描述

    ```
    给定两个整数n和k，返回范围[1, n]中所有可能的k个数的组合。
    你可以按任何顺序返回答案。
    ```

  - 题目样例

    ```
    输入：n = 4, k = 2
    输出：
    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]
    ```

  - 题目解析

    ```
    状态的定义：f(v)表示使用了那些数字v（递增排序）
    状态的转移：枚举使用下一个数字，且比上一个数字大
    状态的边界：所有数字都考虑完了
    ```

    - 状态的转移：$f(v) \rightarrow f(newv)，根据下一个数字选谁转移，且选的数比上一个数大$
    - 状态的边界：$f(v), v.size() == k$

  - 代码实现

    - 如下

      ```cpp
      class Solution {
      public:
          vector<vector<int>> ans;
          void dfs(vector<int> v, const int &n, const int &k) {
              if (v.size() > k) return ;
              if (v.size() == k) ans.push_back(v);
              for (int num = v.back() + 1; num <= n; ++num) {
                  auto newv = v;
                  newv.push_back(num);
                  dfs(newv, n, k);
              }
          }
          vector<vector<int>> combine(int n, int k) {
              for (int num = 1; num <= n; ++num) {
                  vector<int> v = {num};
                  dfs(v, n, k);
              }
              return ans;
          }
      };
      ```

- 例题A_014：[全排列](https://leetcode.cn/problems/permutations/)

  - 题目描述

    ```
    给定一个不含重复数字的数组nums，返回其所有可能的全排列。你可以按任意顺序返回答案。
    ```

  - 题目样例

    ```
    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    ```

  - 题目解析

    ```
    状态的定义：f(vis, v)表示当前使用了哪些数字vis，其排列为v
    状态的转移：枚举下一个未使用的数字
    状态的边界：所有数字都考虑完了
    ```

    - 状态的转移：$f(vis, v) \rightarrow f(newvis, newv), \ 根据下一个未选择的数字转移$
    - 状态的边界：$f(vis, v), vis.size() == n$

  - 代码实现

    - 如下

      ```cpp
      class Solution {
      public:
          static const int N = 6 + 2;
          vector<vector<int>> ans;
          void dfs(set<int> vis, vector<int> v, const vector<int>& nums) {
              int n = nums.size();
              if (vis.size() == n) {
                  ans.push_back(v);
                  return ;
              }
              for (int i = 0; i < n; ++i) {
                  if (vis.count(i) == 0) {
                      auto newvis = vis;
                      auto newv = v;
                      newvis.insert(i);
                      newv.push_back(nums[i]);
                      dfs(newvis, newv, nums);
                  }
              }
          }
          vector<vector<int>> permute(vector<int>& nums) {
              int n = nums.size();
              set<int> vis;
              vector<int> v;
              dfs(vis, v, nums);
              return ans;
          }
      };
      ```

- 例题A_015：[二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/description/)

  - 题目描述
    ```
    给你一个二叉树的根节点root，按任意顺序，返回所有从根节点到叶子节点的路径。
    ```
    
  - 题目样例

    <div align=center >
        <img alt="aa" src="../pics/paths.jpg" style="zoom:0%"/>
        <p>  </p>
      </div>

    ```
    输入：root = [1,2,3,null,5]
    输出：["1->2->5","1->3"]
    ```

  - 题目解析
    
      ```
    容易知道，对于树上的任意两个节点u，v ，它们之间的路径是唯一的（简单路径）。
    本题我们总是从根节点到其他节点，所以在定义状态时没必要对根节点增加一维。所以我们可以这样定义状态：
    
    状态的定义：f(cur, path)表示从根节点到当前节点cur的路径path（并不包含当前节点的值）
    状态的转移：添加当前节点cur的值到路径里去，然后继续递归其孩子节点
    状态的边界：叶子节点
    ```
    
    - 状态的转移：$f(cur, path) \rightarrow f(child, newpath), child是cur的孩子节点$
    - 状态的边界：$f(cur, path), cur是叶子节点$
    
  - 代码实现

    - 在下面的实现中，cur和path，一起构成状态。表示当前在cur节点，根节点到cur节点的路径为path（并不包含cur节点的值）。

    - 拿上面的样例，举个例子，比如当前cur在节点5，那么此时path保存的节点为{1, 2}而不是{1, 2, 5}，当前节点5并没有保存在path里。

    - 有了状态，接下来是转移，转移显然就是递归的去跑当前节点的左右孩子节点。当其左右孩子节点每次跑完后，我们都需要"还原现场"，也即大家口中的"回溯"。既然要"还原现场"，那么我们肯定得知道原来的现场是什么，就是还没进入dfs函数内部的状态，那就是cur和path。在dfs函数内部我们对path做了修改，path.push_back()，所以还原就是path.pop_back()。

    - 在这里，可能很多初学者会疑惑，我们dfs(cur -> left)，dfs(cur -> right)也修改了path呀。其实这还是不理解"递归"的表现，当dfs(cur -> left)函数执行完后，它也会还原当初进入dfs(cur -> left)时的状态，dfs(cur -> right)同理，所以当下面的代码dfs(cur -> left)和dfs(cur -> right)执行完后，唯一对path做了修改的就只是前面操作的path.push_back()，所以我们最后path.pop_back()也就还原了。

    - 多说一句，对于绝大多数初学者，"递归"，"回溯"基本上就是学习路上最大的拦路虎，有的初学者要花费几周甚至几个月才能理解其中的奥秘。希望大家好好理解，相信你也能够理解计算机中"递归"的美。

    - 显式回溯：注意path传的是引用哟

        ```cpp
        class Solution {
        public:
            vector<string> path, ans;
            void dfs(TreeNode* cur, vector<string> &path) {
                if (cur == nullptr) return;
                path.push_back(std::to_string(cur -> val));
                // 叶子节点
                if (cur -> left == nullptr && cur -> right == nullptr) {
                    string t;
                    for (int i = 0, len = path.size(); i < len; ++i) {
                        if (i == 0) t += path[i];
                        else t += "->" + path[i]; 
                    }
                    ans.push_back(t);
                }
                dfs(cur -> left, path);
                dfs(cur -> right, path);
                path.pop_back();
            }
            vector<string> binaryTreePaths(TreeNode* root) {
                dfs(root, path);
                return ans;
            }
      };
      ```
      
    - 隐式回溯：path传的是值复制哟，全程不需要pop_back()

        ```cpp
        class Solution {
        public:
            vector<string> path, ans;
            void dfs(TreeNode* cur, vector<string> path) {
                if (cur == nullptr) return;
                // 叶子节点
                if (cur -> left == nullptr && cur -> right == nullptr) {
                    auto newpath = path;
                    newpath.push_back(std::to_string(cur -> val));
                    string t;
                    for (int i = 0, len = newpath.size(); i < len; ++i) {
                        if (i == 0) t += newpath[i];
                        else t += "->" + newpath[i]; 
                    }
                    ans.push_back(t);
                    return ;
                }
                auto newpath1 = path;
                newpath1.push_back(std::to_string(cur -> val));
                dfs(cur -> left, newpath1);
        
                auto newpath2 = path;
                newpath2.push_back(std::to_string(cur -> val));
                dfs(cur -> right, newpath2);
            }
            vector<string> binaryTreePaths(TreeNode* root) {
                dfs(root, path);
                return ans;
            }
        };
        ```

        

- 例题A_016：[迷宫](https://www.luogu.com.cn/problem/P1605)

    - 题目描述

        ```
        给定一个N*M方格的迷宫，迷宫里有T处障碍，障碍处不可通过。
        在迷宫中移动有上下左右四种方式，每次只能移动一个方格。数据保证起点上没有障碍。
        给定起点坐标和终点坐标，每个方格最多经过一次，问有多少种从起点坐标到终点坐标的方案。
        1<= N, M <= 5
        ```

    - 题目样例

        ```
        第一行为三个正整数N,M,T，分别表示迷宫的长宽和障碍总数。
        第二行为四个正整数SX, SY(起点坐标), FX, FY(终点坐标) 
        接下来T行, 每行两个正整数，表示障碍点的坐标。
        
        输入
        2 2 1
        1 1 2 2
        1 2
        输出
        1
        ```

    - 题目解析

        ```
        状态的定义：f(vis, x, y)表示哪些点坐标已经被访问过了vis（并不包含当前节点）, 当前在坐标(x, y)处
        状态的转移：枚举下一个可以访问的坐标
        状态的边界：从当前坐标出发已没有可以访问的坐标or找到终点坐标了
        ```

        - 状态的转移：$f(vis, x, y) \rightarrow f(newvis, newx, newy)$
        - 状态的边界：$xxx$

    - 代码实现

        - 如下，我们把vis放在全局变量里

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            
            const int N = 5 + 2;
            const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
            int n, m, t, sx, sy, fx, fy, vis[N][N], broken[N][N], ans;
            
            void dfs(int x, int y) {
              // 边界
              if (x == fx && y == fy) {
                ans += 1;
                return ;
              }
              for (int i = 0; i < 4; ++i) {
                int newx = x + dx[i], newy = y + dy[i];
                // 先判断(newx, newy)是否在方格内，再判断不是障碍物点且没被访问
                if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] + broken[newx][newy] == 0) {
                  vis[x][y] = 1;
                  dfs(newx, newy);
                  // 回溯
                  vis[x][y] = 0;
                }
              }
            }
            int main() {
              cin >> n >> m >> t;
              cin >> sx >> sy >> fx >> fy;
              while (t--) {
                int x, y;
                cin >> x >> y;
                broken[x][y] = 1;
              }
              dfs(sx, sy);
              cout << ans;
              return 0;
            }
            ```

- 例题A_017：[01迷宫](https://www.luogu.com.cn/problem/P1141)

    - 题目描述

        ```
        有一个仅由数字0与1组成的n×n格迷宫。若你位于一格0上，那么你可以移动到相邻4格中的某一格1上，同样若你位于一格1上，那么你可以移动到相邻4格中的某一格0上。你的任务是：对于给定的迷宫，询问从某一格开始能移动到多少个格子（包含自身）
        ```

    - 题目样例

        ```
        第一行为两个正整数n,m
        下面n行, 每行n个字符, 字符只可能是0或1, 字符之间没有空格。
        接下来m行, 每行两个用空格分隔的正整数i, j, 询问从这一格（i, j）开始能移动到多少格。
        
        输入
        2 2
        01
        10
        1 1
        2 2
        输出
        4
        4
        ```

    - 题目解析

        ```
        "从某一格开始能移动到多少个格子"类似于洪水覆盖(flood fill), 我们可以使用dfs标记每个联通块, 每个联通块里格子所能到的数量都是相等的，等于联通块的大小。
        状态的定义：f(x, y, color, number)表示从某个格子出发, 走到坐标(x, y)处，已经标记颜色color的格子有number个（当前节点还未被标记）
        状态的转移：枚举下一个可以访问的坐标
        状态的边界：从当前坐标出发已没有可以访问的坐标
        ```

        - 状态的转移：$f(x, y, color, number) \rightarrow f(newx, newy, color, number + 1)$
        - 状态的边界：$f(x, y, color, number), 没有可以访问的坐标了$
        - 时间复杂度：$每个格子只会被标记（染色）一次且只访问一次，所以总的时间复杂度为O(n ^ 2)$

    - 代码实现

        - 如下，注意number传的是引用哟

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            
            const int N = 1e3 + 5;
            const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
            // 由于a初始值只有0或1, 后面我们对数组a的标记（染色）可以直接从2开始
            int n, m, a[N][N], mp[N * N];
            
            void dfs(int x, int y, int color, int &number) {
              int expected = 1 - a[x][y];
              // 标记当前节点
              a[x][y] = color;
              number += 1;
              for (int i = 0; i < 4; ++i) {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && a[newx][newy] == expected) {
                  dfs(newx, newy, color, number);
                }
              }
            }
            int main() {
              cin >> n >> m;
              for (int i = 1; i <= n; ++i) {
                string str;
                cin >> str;
                for (int j = 0, sz = str.size(); j < sz; ++j) {
                  if (str[j] == '0') a[i][j + 1] = 0;
                  else a[i][j + 1] = 1;
                }
              }
              // 尝试从每个点坐标出发开始标记（染色）
              int color = 1, number = 0;
              for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                  if (a[i][j] < 2) {
                    dfs(i, j, ++color, number);
                    mp[color] = number;
                    number = 0;
                  }
                }
              }
              while (m--) {
                int i, j;
                cin >> i >> j;
                cout << mp[a[i][j]] << "\n";
              }
              return 0;
            }
            ```

- 例题A_018：[自然数的拆分问题](https://www.luogu.com.cn/problem/P2404)

    - 题目描述

        ```
        任何一个大于1的自然数n，总可以拆分成若干个小于n的自然数之和。现在给你一个自然数n，要求你求出n的拆分成一些数字的和。每个拆分后的序列中的数字从小到大排序。然后你需要输出这些序列，其中字典序小的序列需要优先输出。2≤n≤8。
        ```

    - 题目样例

        ```
        输入
        7
        输出
        1+1+1+1+1+1+1
        1+1+1+1+1+2
        1+1+1+1+3
        1+1+1+2+2
        1+1+1+4
        1+1+2+3
        1+1+5
        1+2+2+2
        1+2+4
        1+3+3
        1+6
        2+2+3
        2+5
        3+4
        ```

    - 题目解析

        ```
        状态的定义：f(n, v)表示前面的拆分序列为v，还剩下大小为n的数字需要拆分
        状态的转移：枚举下一个数
        状态的边界：不可再拆分的时候
        ```

        - 状态的转移：$f(n, v) \rightarrow f(n - x, newv), x >= v.back()$
        - 状态的边界：$f(0, v), 剩下的数字为0，已拆分完$

    - 代码实现

        - 如下，枚举的时候x是从小到大的，自然符合字典序小优先的要求

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            
            int n;
            void dfs(int n, vector<int> &v) {
              // 递归的边界
              if (n == 0) {
                for (int i = 0, sz = v.size(); i < sz; ++i) {
                  if (i == 0) cout << v[i];
                  else cout << "+" << v[i];
                }
                cout << "\n";
                return ;
              }
              // 枚举下一个数
              for (int x = v.back(); x <= n; ++x) {
                v.push_back(x);
                dfs(n - x, v);
                v.pop_back();
              }
            }
            int main() {
              cin >> n;
              vector<int> v;
              for (int x = 1; x < n; ++x) {
                v.push_back(x);
                dfs(n - x, v);
                v.pop_back();
              }
              return 0;
            }
            ```

- 例题A_019：[图的 m 着色问题](https://www.luogu.com.cn/problem/P2819)

    - 题目描述

        ```
        给定无向连通图G和m种不同的颜色, 用这些颜色为图G的各顶点着色，每个顶点着一种颜色。如果有一种着色法使 
        G中每条边的2个顶点着不同颜色，则称这个图是m可着色的，求一共有多少不同的着色法。n <= 100, 保证答案不超过20000
        ```

    - 题目样例

        ```
        第1行有3个正整数n,k,m，表示给定的图G有n个顶点和k条边，m种颜色。接下来的k行中，每行有2个正整数u,v表示图G的一条边(u,v)。
        
        输入
        5 8 4
        1 2
        1 3
        1 4
        2 3
        2 4
        2 5
        3 4
        4 5
        输出
        48
        ```

    - 题目解析

        ```
        考虑按顶点编号从小到大依次对每个点染色，从第1个点开始，依次填入和前面不冲突的数，直到到第n+1一个点时表示这种方法可行。
        
        状态的定义：f(u, color)表示当前染色到第u个点（当前节点还未染色），其前面的节点[1, u - 1]都已染好色保存在color中
        状态的转移：枚举当前节点u染什么色
        状态的边界：所有节点都已染好色
        ```

        - 状态的转移：$f(u, color) \rightarrow f(u + 1, \{color + i\}), 枚举当前节点染色为i$
        - 状态的边界：$f(u, color), u == n + 1$

    - 代码实现

        ```cpp
        #include <bits/stdc++.h>
        using namespace std;
        const int N = 100 + 5;
        vector<int> g[N];
        int color[N], n, k, m, ans = 0;
        // 一个坑点，图可能存在孤立的点
        bool check(int u) {
          for (auto &v: g[u]) {
            if (color[u] == color[v]) return 0;
          }
          return 1;
        }
        void dfs(int u) {
          if (u == n + 1) {
            ans += 1;
            return ;
          }
          for (int i = 1; i <= m; ++i) {
            color[u] = i;
            if (!check(u)) continue;
            dfs(u + 1);
          }
          color[u] = 0;
        }
        int main() {
          cin >> n >> k >> m;
          for (int i = 1; i <= k; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
          }
          dfs(1);
          cout << ans << "\n";
          return 0;
        }
        ```

- 例题A_020：[求细胞数量](https://www.luogu.com.cn/problem/P1451)

    - 题目描述

        ```
        一矩形阵列由数字0到9组成，数字1到9代表细胞，细胞的定义为沿细胞数字上下左右若还是细胞数字则为同一细胞，求给定矩形阵列的细胞个数。
        ```
        
    - 题目样例

        ```
        第一行两个整数代表矩阵大小n和m。1≤n,m≤100
        接下来n行，每行一个长度为m的只含字符0到9的字符串，代表这个n×m的矩阵。
        
        输入
        4 10
        0234500067
        1034560500
        2045600671
        0000000089
        输出
        4
        ```

    - 题目解析

        ```
        属于同一个细胞的数字都染成相同的颜色，每次从未被染色的数字(>=1)出发搜索。
        
        状态的定义：f(x, y, color)表示从某一个位置出发，当前走到位置(x, y)处，涂色为color
        状态的定义：枚举下一个可以染色的位置
        状态的边界：没有可染色的位置了
        ```

        - 状态的转移：$f(x, y, color) \rightarrow f(newx, newy, color), 枚举下一个可以染色的位置$
        - 状态的边界：$f(x, y, color), 没有下一个位置可以染色了$
        - 时间复杂度：$每个位置最多被染色一次，所以总的时间复杂度O(N * M)$
        
    - 代码实现：

        - 如下，染色编号从START开始计数

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            
            const int N = 1e2 + 5, START = 10;
            const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
            int n, m, a[N][N];
            void dfs(int x, int y, const int &color) {
              a[x][y] = color;
              for (int i = 0; i < 4; ++i) {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx >= 1 && newx <= n && newy >= 1 && newy <= m) {
                  if (a[newx][newy] >= 1 && a[newx][newy] <= 9)
                    dfs(newx, newy, color);
                }
              }
            }
            int main() {
              cin >> n >> m;
              for (int i = 1; i <= n; ++i) {
                string str;
                cin >> str;
                for (int j = 0; j < m; ++j) {
                  if (str[j] == '0') a[i][j + 1] = 0;
                  else a[i][j + 1] = 1;
                }
              }
              int color = START;
              for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                  if (a[i][j] >= 1 && a[i][j] <= 9)
                    dfs(i, j, ++color);
              cout << color - START << "\n";
              return 0;
            }
            ```

- 例题A_021：[装箱问题](https://www.luogu.com.cn/problem/P1049)

    - 题目描述

        ```
        有一个箱子容量为V，同时有n个物品，每个物品有一个体积。现在从n个物品中，任取若干个装入箱内（也可以不取），使箱子的剩余空间最小。输出这个最小值。0 <= n <= 30, 1 <= V <= 20000。
        ```

    - 题目样例

        ```
        第一行共一个整数V，表示箱子容量。
        第二行共一个整数n，表示物品总数。
        接下来n行，每行有一个正整数，表示第i个物品的体积。
        
        输入
        24
        6
        8
        3
        12
        7
        9
        7
        输出
        0
        ```

    - 题目解析

        ```
        状态的定义：f(i, volume)表示前i个物品（第i个物品还未被选择），体积为volume
        状态的转移：枚举第i个物品选or不选
        状态的边界：所有物品都考虑完了
        ```

        - 状态的转移：
          - $f(i, volume) \rightarrow f(i + 1, volume + 0), 不选第i个物品$
          - $f(i, volume) \rightarrow f(i + 1, volume + v(i)), 选第i个物品$
        - 状态的边界：
          - $f(i, volume), i == n + 1, 所有物品都已考虑完$
        - 时间复杂度：$每个物品都可选or可不选, 所以总的时间复杂度为O(2 ^ N)$

    - 代码实现

        - 如下

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            const int N = 30 + 5;
            int V, n, v[N], ans;
            void dfs(int i, int volume) {
              // 剪枝
              if (volume > V) return ;
              // 边界
              if (i == n + 1) {
                ans = std::min(ans, V - volume);
                return ;
              }
              // 不选
              dfs(i + 1, volume + 0);
              // 选
              dfs(i + 1, volume + v[i]);
            }
            int main() {
              cin >> V >> n;
              for (int i = 1; i <= n; ++i)
                cin >> v[i];
              ans = V;
              dfs(1, 0);
              cout << ans;
              return 0;
            }
            ```

- 例题A_022：[部落卫队](https://www.luogu.com.cn/problem/P1692)

    - 题目描述

        ```
        原始部落byteland中的居民们为了争夺有限的资源，经常发生冲突。几乎每个居民都有他的仇敌。部落酋长为了组织一支保卫部落的队伍，希望从部落的居民中选出最多的居民入伍，并保证队伍中任何2个人都不是仇敌。给定byteland部落中居民间的仇敌关系，编程计算组成部落卫队的最佳方案。若有多种方案可行，输出字典序最大的方案。
        ```

    - 题目样例

        ```
        输入：第1行有2个正整数n和m，表示 byteland 部落中有n个居民，居民间有m个仇敌关系
             接下来的m行中，每行有2个正整数u和v，表示居民u与居民v是仇敌。
        
        输出：第1行是部落卫队的人数；第2行是卫队组成Xi, Xi=0表示居民i不在卫队中，Xi=1表示居民i在卫队中。
        
        输入
        7  10
        1  2
        1  4
        2  4
        2  3
        2  5
        2  6
        3  5
        3  6
        4  5
        5  6
        输出
        3
        1 0 1 0 0 0 1
        ```

    - 题目解析

        ```
        状态的定义：f(i, v)表示前i个居民（还未考虑第i个居民），目前已选出的居民编号为v
        状态的转移：枚举第i个居民的选择
        状态的边界：所有居民都考虑完了
        ```

        - 状态的转移：
          - $f(i, v) \rightarrow f(i + 1, \{v + i\}), 选第i个居民$
          - $f(i, v) \rightarrow f(i + 1, v), 不选第i个居民$
        - 状态的边界：
          - $f(i, v), i == n + 1, 所有居民都已考虑完了$

    - 代码实现

        - 如下，在状态转移时先考虑选再考虑不选，这样先搜索到的自然就是字典序大的方案。

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            
            const int N = 1e2 + 5;
            int n, m, a[N][N], ans_cnt;
            vector<int> ans;
            
            void dfs(int i, vector<int> &v) {
              // 边界
              if (i == n + 1) {
                if (v.size() > ans_cnt) {
                  ans_cnt = v.size();
                  ans = v;
                }
                return ;
              }
              bool ok = 1;
              for (auto &c: v) {
                if (a[c][i] == 1 || a[i][c] == 1) {
                  ok = 0;
                }
              }
              // 选第i个
              if (ok) {
                v.push_back(i);
                dfs(i + 1, v);
                v.pop_back();
              }
              // 不选第i个
              dfs(i + 1, v);
            }
            int main() {
              cin >> n >> m;
              for (int i = 1; i <= m; ++i) {
                int u, v;
                cin >> u >> v;
                a[u][v] = a[v][u] = 1;    
              }
              vector<int> v;
              dfs(1, v);
              cout << ans.size() << "\n";
              for (int i = 1; i <= n; ++i) {
                bool found = 0;
                for (auto &c: ans) {
                  if (i == c) {
                    found = 1;
                    break;
                  }
                }
                if (found) cout << 1 << " ";
                else cout << 0 << " ";
              }
              return 0;
            }
            ```

- 例题A_023：[八皇后 Checker Challenge](https://www.luogu.com.cn/problem/P1219)

    - 题目描述

        ```
        一个如下的6×6的跳棋棋盘，有六个棋子被放置在棋盘上，使得每行、每列，每条对角线（包括两条主对角线的所有平行线）上至多有一个棋子。
        
        上面的布局可以用序列2 4 6 1 3 5来描述，第i个数字表示在第i行的相应位置（列）有一个棋子。这只是棋子放置的一个解。请编一个程序找出所有棋子放置的解。并把它们以上面的序列方法输出，解按字典顺序排列。请输出前3个解。最后一行是解的总个数。
        ```

    - 题目样例

        <div align=center >
            <img alt="xxxx" src="../pics/queen.png" style="zoom:0%" />
        </div>

        ```
        输入：一个正整数n，表示棋盘是n×n大小的。6≤n≤13
        输出：前三行为前三个解，每个解的两个数字之间用一个空格隔开。第四行只有一个数字，表示解的总数。
        输入
        6
        输出
        2 4 6 1 3 5
        3 6 2 5 1 4
        4 1 5 2 6 3
        4
        ```

    - 题目解析

        ```
        我们一行一行的填棋子，如果当前填到第i行，那么我们只要知道前i行填的棋子分别在哪儿，我们就可以确定填第i行的棋子了，所以我们如下设计状态。
        状态的定义：f(i, v)表示前i行（还未填第i行的棋子），填了哪些棋子v
        状态的转移：在第i行填一个棋子，且和前面的棋子不冲突（不在同行、同列、同对角线上）
    状态的边界：填完所有行了    
        ```
        
        - 状态的转移：$f(i, v) \rightarrow f(i + 1, newv), 在第i行填一个棋子且和前面填的棋子不冲突$
        - 状态的边界：$f(i, v), i == n + 1, 填完所有行了$
        
    - 代码实现

        - 如下, 由于我们是一行一行且列也是从小到大填的棋子，自然满足题目要求的字典序排序

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            
            using pii = std::pair<int, int>;
            int n, cnt = 0;
            vector<vector<int> > ans;
            void dfs(int i, vector<pii> &v) {
              if (i == n + 1) {
                cnt += 1;
                // 保存前3个解
                if (cnt <= 3) {
                  vector<int> tmp;
                  for (auto &c: v) tmp.push_back(c.second);
                  ans.push_back(tmp);
                }
                return ;
              }
              // 尝试在第i行j列填一个棋子(i, j)
              // 由于是在第i行填棋子, 肯定和前面的行不同, 自然满足每行至多有一个棋子
              // 检查和前面的棋子不在同一列(j != y)
              // 检查和前面的棋子不在同一对角线, 即斜率不为1or-1
              // 斜率为1：(i - x) == (j - y) * 1，斜率为-1：(i - x) == (j - y) * -1
              for (int j = 1; j <= n; ++j) {
                bool ok = 1;
                for (auto &c: v) {
                  int x = c.first, y = c.second;
                  if (j == y || (i - x) == (j - y) * 1 || (i - x) == (j - y) * -1) {
                    ok = 0;
                    break;
                  }
                }
                // 如果能在(i, j)填棋子
                if (ok) {
                  v.push_back({i, j});
                  dfs(i + 1, v);
                  v.pop_back();
                }
              }
            }
            int main() {
              cin >> n;
              vector<pii> v;
              dfs(1, v);
              for (auto &v: ans) {
                for (auto &c: v) {
                  cout << c << " ";
                }
                cout << "\n";
              }
              cout << cnt;
              return 0;
            }
            ```

- 例题A_024：[判断二分图](https://leetcode.cn/problems/is-graph-bipartite/)

    - 题目描述

        ```
        给定一个无向图（这个图可能不是连通图），如果图是二分图，返回true；否则，返回false 。
        二分图定义：如果能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，就将这个图称为二分图 。
        ```

    - 题目样例

        <div align=center >
            <img alt="xxxx" src="../pics/is-graph-bipartite1.jpg" style="zoom:0%" />
            <img alt="xxxx" src="../pics/is-graph-bipartite1.jpg" style="zoom:0%" />
        </div>

        ```
        上面左边的图
        输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
        输出：false
        解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。
        
        上面右边的图
        输入：graph = [[1,3],[0,2],[1,3],[0,2]]
        输出：true
        解释：可以将节点分成两组:{0, 2}和{1, 3}。
        ```

    - 题目解析

        ```
        我们任选一个从未染过色的节点出发，尝试将这个节点的联通块黑白染色，如果能成，说明这个联通块是二分图。
        
        状态的定义：f(u, color)表示从当前节点u出发（当前节点还未染色），对节点u所在的联通块能否染色为二分图
        状态的转移：继续染色节点u的相邻节点
        状态的边界：没有可以继续染色的节点了
        ```

        - 状态的转移：$f(u, color) \rightarrow f(v, 1 - color), v是u的相邻节点$
        - 状态的边界：$f(u, color), 相邻节点v都已染好色了$
        - 时间复杂度：$每个节点一旦染完色后颜色就定了，所以每个节点做多染色一次，时间复杂度为O(N)$

    - 代码实现

        - 如下

            ```cpp
            class Solution {
            public:
                // vis[u] 的取值-1（从未被访问过）, 0（被访问过染色为白）, 1（被访问过染色为黑）
                int vis[105];
                // 从当前节点u出发（当前节点染色为color），能否染色为二分图
                int dfs(int u, int color, const vector<vector<int>>& g) {
                    vis[u] = color;
                    for (auto &v: g[u]) {
                        if (vis[v] == vis[u]) return 0;
                        else if (vis[v] == -1 && !dfs(v, 1 - color, g)) return 0;
                    }
                    return 1;
                }
                bool isBipartite(vector<vector<int>>& graph) {
                    int n = graph.size();
                    std::memset(vis, -1, sizeof vis);
                    for (int i = 0; i < n; ++i)
                        if (vis[i] == -1 && !dfs(i, 0, graph))
                            return 0;
                    return 1;
                }
            };
            ```

- 例题A_025：[汉诺塔问题](https://leetcode.cn/problems/hanota-lcci/)

    - 题目描述

      ```
      在经典汉诺塔问题中，有3根柱子及N个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
      (1) 每次只能移动一个盘子;
      (2) 盘子只能从柱子顶端滑出移到下一根柱子;
      (3) 盘子只能叠在比它大的盘子上。
      请编写程序，用栈将所有盘子从第一根柱子移到最后一根柱子。
      你需要原地修改栈
      ```

    - 题目样例

      ```
       输入：A = [2, 1, 0], B = [], C = []
       输出：C = [2, 1, 0]
      ```

    - 题目解析

      ```
      状态的定义：f(A, B, c)表示将A柱子里的圆盘，借助B柱子，移到C柱子
      状态的转移：考虑先将A柱子里顶端的一个圆盘，暂存移动到B柱子里；然后将剩下的A柱子里的圆盘移动到C；最后将暂存在B柱子里的圆盘移动到C柱子，就完成了整个过程
      状态的边界：A柱子里的圆盘空了，即都被移动完了
      ```

      - 状态的转移：$f(A, B, C) \rightarrow 第一步 + f(newa, newb, newc) + 第三步, 考虑A柱子里顶端的一个圆盘进行转移$
      - 状态的边界：$f(A, B, C), A.empty() == true, A柱子里的圆盘都移完了$

    - 代码实现

      - 如下

        ```cpp
        class Solution {
        public:
            void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
                // 边界
                if (A.empty()) return ;
                // 第一步：将A里顶端的一个先移到B上
                B.push_back(A.back());
                A.pop_back();
        
                // 第二步：将剩下A里的移到C
                hanota(A, B, C);
        
                // 第三步：将开始移到B上的移到C
                C.push_back(B.back());
                B.pop_back();
            }
        };
        ```

- 例题A_026：[优美的排列](https://leetcode.cn/problems/beautiful-arrangement/)

    - 题目描述

      ```
      假设有从1到n的n个整数(1 <= n <= 15)。用这些整数构造一个数组perm（下标从1开始），只要满足下述条件之一，该数组就是一个优美的排列：
      perm[i]能够被i整除
      i能够被perm[i]整除
      给你一个整数n，返回可以构造的优美排列的数量。
      ```

    - 题目样例

      ```
      输入：n = 2
      输出：2
      解释：
      第 1 个优美的排列是 [1,2]：
          - perm[1] = 1 能被 i = 1 整除
          - perm[2] = 2 能被 i = 2 整除
      第 2 个优美的排列是 [2,1]:
          - perm[1] = 2 能被 i = 1 整除
          - i = 2 能被 perm[2] = 1 整除
      ```

    - 题目解析

      ```
      状态的定义：f(i, v)表示构造前i个整数perm（第i个位置还未填），使用了哪些数v
      状态的转移：枚举第i个位置填哪个数
      状态的边界：填完所有数了
      ```

      - 状态的转移：$f(i, v) \rightarrow f(i + 1, newv), 枚举第i个位置填哪个数$
      - 状态的边界：$f(i, v), v.size() == n, 填完所有数了$

    - 代码实现

      - 如下

        ```cpp
        class Solution {
        public:
            int ans = 0;
            void dfs(int i, unordered_set<int> &v, const int &n) {
                if (i == n + 1) {
                    ans += 1;
                    return ;
                }
                // 枚举第i个位置填哪个数, v保存的前面填了哪些数
                for (int num = 1; num <= n; ++num) {
                    if (v.count(num) == 0 && (num % i == 0 || i % num == 0)) {
                        v.insert(num);
                        dfs(i + 1, v, n);
                        v.erase(num);
                    }
                }
            }
            int countArrangement(int n) {
                unordered_set<int> v;
                dfs(1, v, n);
                return ans;
            }
        };
        ```

- 例题A_027：[漂亮数组](https://leetcode.cn/problems/beautiful-array/)

    - 题目描述

        ```
        如果长度为n的数组nums满足下述条件，则认为该数组是一个漂亮数组 ：
        
        nums是由范围[1, n]的整数组成的一个排列。
        对于每个0 <= i < j < n，均不存在下标k（i < k < j）使得 2 * nums[k] == nums[i] + nums[j]。
        给你整数n(n<=1000)，返回长度为n的任一漂亮数组。本题保证对于给定的n至少存在一个有效答案。
        ```

    - 题目样例

        ```
        输入：n = 4
        输出：[2,1,4,3]
        
        输入：n = 5
        输出：[3,1,2,5,4]
        ```

    - 题目解析

        ```
        注意到2 * nums[k]肯定是一个偶数，如果nums[i] + nums[j]是奇数那他们就永远不会相等了，这提示我们可以把数组分为两部分，左边部分都是偶数，右边部分都是奇数。然后左、右两部分分别递归构造为漂亮数组。
        
        状态的定义：f(n)表示将[1,2,...,n]的排列构造成漂亮数组。
        状态的转移：将1到n的排列分为两部分，左边部分全是偶数，右边部分全是奇数，然后左右两部分分别递归构造为漂亮数组。
        状态的边界：f(1) = 1
        
        举例 n = 5
        左部分：2，4   右部分：1，3，5
        f(n/2) = f(5/2) = f(2), 由状态的定义的可知f(2)表示{1，2}组成的漂亮数组
        2 * f(n/2)就是2 * {1， 2} = {2，4}，也就是左边部分的漂亮数组。
            
        同理
        f(n - n/2) = f(3), 由状态的定义可知f(3)表示{1，2，3}组成的漂亮数组
        2 * f(n - n/2) - 1 = 2 * {1，2，3} - 1 = {1，3，5}，也就是由边部分的漂亮数组。
            
        所以f(n) = 2*f(n/2) + (2*f(n - n/2) - 1)
        ```
        
        - 状态的转移：$f(n) = 2 * f(n/2) + (2 * f(n - n/2) - 1)，+表示把左右两部分拼接起来$
        - 状态的边界：$f(1) = {1}$      
        
    - 代码实现
    
        - 如下
    
            ```cpp
        class Solution {
            public:
                vector<int> beautifulArray(int n) {
                    // 边界
                    if (n == 1) return {1};
                  
                    vector<int> ans;
                    auto left = beautifulArray(n / 2);
                    auto ritht = beautifulArray(n - n / 2);
                    for (auto &c: left) ans.push_back(c * 2);
                    for (auto &c: ritht) ans.push_back(c * 2 - 1);
                    return ans;
                }
            };
            ```
    
- 例题A_028：[破冰游戏](https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/)

    - 题目描述

        ```
        社团共有num位成员参与破冰游戏，编号为0 ~ num-1。成员们按照编号顺序围绕圆桌而坐。社长抽取一个数字 target，从0号成员起开始计数，排在第target位的成员离开圆桌，且成员离开后从下一个成员开始计数。请返回游戏结束时最后一位成员的编号。1 <= num <= 10^5
        ```

    - 题目样例

        ```
        输入：num = 7, target = 4
        输出：1
        
        输入：num = 12, target = 5
        输出：0
        ```

    - 题目解析

        ```
        状态的定义：f(n)表示{0,1,2,...n-1}按照题目玩法后最后一位成员的编号。
        状态的转移：删除第target位后，剩下的数字怎么用状态表示出来，看下面的举例。
        状态的边界：f(1) = 0
        
        举例：n = 7, target = 4
        f(7) = {0, 1, 2, 3, 4, 5, 6}表示按照题目玩法后最后一位成员的编号，删除第target位后变为4，5，6，0，1，2看作4，5，6，7，8，9，也就是{4，5，6，0，1，2}接着游戏玩到最后的成员编号等于f(7)
        
        f(6) = {0, 1, 2, 3, 4, 5}表示按照题目玩法后最后一位成员的编号
        
        (f(6) + target) % 7 = {4, 5, 6, 7, 8, 9} % 7 = {4，5，6，0，1，2}
        
        所以f(7) = (f(6) + target) % 7
        
        即f(n) = (f(n - 1) + target) % n
        ```
        
        - 状态的转移：$f(n) = (f(n - 1) + target) \ \% \ n$
        - 状态的边界：$f(1) = 0$
        
    - 代码实现

        - 如下

            ```cpp
            class Solution {
            public:
                int iceBreakingGame(int num, int target) {
                    if (num == 1) return 0;
                    return (iceBreakingGame(num - 1, target) + target) % num;
                }
            };
            ```

- 例题A_029：[消除游戏](https://leetcode.cn/problems/elimination-game/)

    - 题目描述

        ```
        列表arr由在范围[1, n]中的所有整数组成，并按严格递增排序。请你对arr应用下述算法：
        
        从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
        重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
        不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
        给你整数n，返回arr最后剩下的数字。1 <= n <= 10^9
        ```

    - 题目样例

        ```
        输入：n = 9
        输出：6
        解释：
        arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        arr = [2, 4, 6, 8]
        arr = [2, 6]
        arr = [6]
        ```

    - 题目解析

        ```
        状态的定义: f1(n)表示{1,2,..,n}的所有整数，从左到右先删，再从右到左，再从左到右，依次循环删下去，最后剩下的一个数字。
                  f2(n)表示{1,2,..,n}的所有整数，从右到左先删，再从左到右，再从右到左，依次循环删下去，最后剩下的一个数字。
        状态的转移：不管先从左到右删除还是从右到左删除数字，剩下的数字看怎么用状态表示出来。
        状态的边界：f1(1) = f2(1) = 1
        
        举例:
        f1(9) = {1, 2, 3, 4, 5, 6, 7, 8, 9} => 从左到右删完后变为 {2, 4, 6, 8} = 2 * f2(4)
        f1(8) = {1, 2, 3, 4, 5, 6, 7, 8}    => 从左到右删完后变为 {2, 4, 6, 8} = 2 * f2(4)
        
        所以：f1(n) = 2 * f2(n / 2)，n不管奇偶都成立
        
        同理
        f2(5) = {1, 2, 3, 4, 5} => 从右到左删完后变为 {2, 4} = 2 * f1(2)
        f2(4) = {1, 2, 3, 4}    => 从右到左删完后变为 {1, 3} = 2 * f1(2) - 1
        
        所以：f2(n) = 2 * f1(n / 2) - 0, n为奇数
        所以：f2(n) = 2 * f1(n / 2) - 1, n为偶数
        ```

        - 状态的转移
          - $f1(n) = 2 * f2(n / 2)$
          - $f2(n) = 2 * f1(n / 2) - 0, n为奇数$
          - $f2(n) = 2 * f1(n / 2) - 1, n为偶数$
        - 状态的边界
          - $f1(1) = f2(1) = 1$
        - 时间复杂度
          - $每次n都是除2,减少一半的规模，所以时间复杂度为O(logN)$

    - 代码实现

        - 如下, dfs1函数对应的就是f1, dfs2函数对应的就是f2

            ```cpp
            class Solution {
            public:
                int dfs1(int n) {
                    if (n == 1) return 1;
                    return 2 * dfs2(n / 2);
                }
                int dfs2(int n) {
                    if (n == 1) return 1;
                    return 2 * dfs1(n / 2) - (n % 2 == 0? 1: 0);
                }
                int lastRemaining(int n) {
                    return dfs1(n);
                }
            };
            ```

- 例题A_030：[排序数组](https://leetcode.cn/problems/sort-an-array/)

    - 题目描述

        ```
        给你一个整数数组nums，请你将该数组升序排列。1 <= nums.length <= 5 * 10^4
        ```

    - 题目样例

        ```
        输入：nums = [5,2,3,1]
        输出：[1,2,3,5]
        
        输入：nums = [5,1,1,2,0,0]
        输出：[0,0,1,1,2,5]
        ```

    - 题目解析

        ```
        如果将数组分为左右两半，左边的递归排好序，右边的递归排好序，然后左右两边再合并为一起排好序，就对整个数组排好序了，这就是经典的归并排序。
        
        状态的定义：f(nums)表示将nums排好序
        状态的转移：f(left) + f(right), 将nums分为两半分别递归排序，再合并。
        状态的边界：只剩一个元素，本身就是排好序了的
        ```

        - 状态的转移：$f(nums) \rightarrow f(left) + f(right)，+表示将左右两部分再线性合并$
        - 状态的边界：$f(nums), nums.size() <= 1$
        - 时间复杂度：由于归并排序每次都将当前待排序的序列折半成两个子序列递归调用，然后再合并两个有序的子序列，而每次合并两个有序的子序列需要O(n)的时间复杂度，所以我们可以列出归并排序运行时间T(n)的递归表达式：
          - $T(N) = 2 * T(N / 2) + O(N)$
          - 根据**主定理**（解上面的递归式方程）我们可以得出归并排序的时间复杂度为$O(NlogN)$

    - 代码实现

        - 如下, 下面这种实现不是对原数组原地操作，所以会复制大量的内存。

            ```cpp
            class Solution {
            public:
                vector<int> sortArray(vector<int>& nums) {
                    // 边界
                    if (nums.size() <= 1) return nums;
                    int n = nums.size();
                    vector<int> left, right;
                    for (int i = 0; i < n / 2; ++i) left.push_back(nums[i]);
                    for (int i = n / 2; i < n; ++i) right.push_back(nums[i]);
                    
                    left = sortArray(left);
                    right = sortArray(right);
            
                  	// 线性合并左右两部分, i和j是指向left和right的双指针
                    vector<int> ans;
                    int i = 0, j = 0;
                    while (1) {
                        if (i >= left.size() && j >= right.size()) break;
                        int mi = 1e9;
                        if (i < left.size()) mi = std::min(mi, left[i]);
                        if (j < right.size()) mi = std::min(mi, right[j]);
                        ans.push_back(mi);
            
                        if (i < left.size() && mi == left[i]) ++i;
                        else ++j;
                    }
                    return ans;
                }
            };
            ```

- 例题A_031：[寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)

    - 题目描述

        ```
        给定两个大小分别为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的中位数。
        
        算法的时间复杂度应该为O(log (m+n)) 。
        ```
        
    - 题目样例

        ```
        输入：nums1 = [1,3], nums2 = [2]
        输出：2.00000
        解释：合并数组 = [1,2,3] ，中位数 2
        
        输入：nums1 = [1,2], nums2 = [3,4]
        输出：2.50000
        解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
        ```

    - 题目解析

        ```
        求两个正序数组的中位数 => 转换为 求两个正序数组的第k小的数
        
        状态的定义：f(L1, R1, L2, R2, k, nums1, nums2)表示在有序数组nums1中的[L1, R1]范围内，有序数组nums2中的[L2, R2]范围内，寻找第k小的数。
        状态的转移：mid1 = L1 + k/2, mid2 = R2 + k/2, num1和nums2分别取出最小的k/2个元素，比较nums1[mid1]和nums[mid2]，如果nums1[mid1] < nums2[mid2]说明nums1里的[L1, mid1]的数肯定不会是答案，可以排除掉，在剩下的范围继续搜，同理num1[mid] > nums[mid]。
        状态的边界：看下面的代码注释
        ```

        - 状态的转移:
          - $f(L1, R1, L2, R2, k, nums1, nums2) \rightarrow f(newL1, R1, L2, R2, k', nums1, nums2), 排除nums1里的前k/2个元素$
          - $f(L1, R1, L2, R2, k, nums1, nums2) \rightarrow f(L1, R1, newL2, R2, k', nums1, nums2), 排除nums2里的前k/2个元素$
        - 时间复杂度：
          - $每次排除k/2个元素，所以时间复杂度为O(logK)，k = (nums1.size() + nums2.size()) / 2$

    - 代码实现

        - 如下，转换为求前第k小（大）的这种技巧很常见

            ```cpp
            class Solution {
            public:
                // 中位数：转化成寻找两个有序数组中的第k小的数
                // k -> k/2 -> k/4 -> ...
                // 每次排除k/2个元素
                int dfs(int L1, int R1, int L2, int R2, int k, const vector<int>& nums1, const vector<int>& nums2) {
                    // 递归边界一：第k小的数在nums2中
                    if (L1 > R1) return nums2[L2 + k - 1];
                    // 递归边界二：第k小的数在nums1中
                    if (L2 > R2) return nums1[L1 + k - 1];
                    // 递归边界三：两者取小
                    if (k == 1) return std::min(nums1[L1], nums2[L2]);
            
                    int mid1 = std::min(L1 + k / 2 - 1, R1);
                    int mid2 = std::min(L2 + k / 2 - 1, R2);
                    // 排除k/2个数字后，在剩下的范围内继续搜（k - k/2）小的数
                    if (nums1[mid1] < nums2[mid2]) return dfs(mid1 + 1, R1, L2, R2, k - (mid1 - L1 + 1), nums1, nums2);
                    return dfs(L1, R1, mid2 + 1, R2, k - (mid2 - L2 + 1), nums1, nums2);
                }
                double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
                    int n1 = nums1.size(), n2 = nums2.size();
                    // 奇数
                    if ((n1 + n2) % 2) return dfs(0, n1 - 1, 0, n2 - 1, (n1 + n2 + 1) / 2, nums1, nums2);
                    // 偶数
                    else {
                        int a = dfs(0, n1 - 1, 0, n2 - 1, (n1 + n2 ) / 2, nums1, nums2);
                        int b = dfs(0, n1 - 1, 0, n2 - 1, (n1 + n2 ) / 2 + 1, nums1, nums2);
                        return 1.0 * (a + b) / 2;
                    }
                }
            };
            ```

##### 写在后面的话

- 希望大家在完成第一部分的学习后，已经深入理解并掌握了递归的概念，并能领略到其在计算机科学中的独特魅力。作为一门强调实践的学科，我鼓励大家亲自动手编程，根据自己的理解独立完成例题的代码编写，并进行提交。至此，第一部分的学习内容已经全部讲解完毕，希望大家在学习过程中能够乐在其中！