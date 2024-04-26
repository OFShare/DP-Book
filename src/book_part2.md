<div align=center >
  <font face="黑体" size=7>动态规划的思考艺术（第二卷）</font>
 </div>

##### 写在前面的话

- 经过第一卷的学习，我们应该已经比较熟悉递归、回溯，现在我们开始接触动态规划。当然，依旧是从简单的、经典的，一些问题入手。
- 动态规划为何常常是算法竞赛的宠儿？可能的一个原因在于，动态规划的问题需要选手在（复杂的）给定题目的描述中，抽象出合理的状态以及高效的状态转移，这表达了选手高超的分析和建模的能力。（动态规划的思想：从复杂的题目背景中抽象出状态表示，然后设计它们之间的转移）
- 状态如果以更加广义的方式理解，其实不仅仅出现在DP里，如贪心时要维护的信息，$bfs$寻找最短路时的状态，滑动窗口维护[L, R)信息时的状态等等，广泛的我们可以把**需要维护的信息**都可以叫状态，状态是我们对问题的抽象表达，维护相关的信息/状态就可以顺利的解决问题了。

##### DP题目精讲

- 例题B_001：[爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)

  - 题目描述

    ```
    假设你正在爬楼梯。需要n阶你才能到达楼顶。每次你可以爬1或2个台阶。你有多少种不同的方法可以爬到楼顶呢？
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
    状态的定义：我们定义f(i)表示爬到第i阶台阶的方案数
    状态的转移：
       f(i - 1) + 再一次性爬一个台阶，就爬到了第i阶台阶
       f(i - 2) + 再一次性爬二个台阶，就爬到了第i阶台阶
       f(i - 3) + 再一次性爬三个台阶，就爬到了第i阶台阶，但是题目规定"每次你可以爬 1 或 2 个台阶"，所以这种不行。
    状态的边界：f(1) = 1, f(2) = 2
    ```

    - 状态的转移：$f(i) = f(i - 1) + f(i - 2)$
    - 状态的边界：$f(1) = 1, f(2) = 2$
    - 时间复杂度：$O(N)$
  - 在递推法实现时，状态的边界往往就是最开始需要初始化的一些状态；而在记忆化搜索时，状态的边界往往是最后递归到才赋值。
  
- 代码实现

  - 在动态规划递推法的实现中大概分了两种，一种可以叫做**人人为我**，另一种叫做**我为人人**, 当然都叫做递推法。

  - 我为人人：表示根据$状态i$，可以转移到那些状态去。

    - 一般来说，$状态i$已经确定

  - 人人为我：表示$状态i$，可以由哪些其他状态转移而来。

    - 一般来说，由哪些状态转移而来的这些状态都已确定。这也是一个常见的DP优化技巧，由于这些要转移而来的状态都已确定，常常可以利用一些数据结构优化转移的时间复杂度，从而降低整体的时间复杂度。

    - 哦对了，我们一直没有讲DP的时间复杂度，DP的时间复杂度一般可归纳为：$O(T) = O(状态数) * O(转移数)$，还记得我们第一卷讲的DAG图吗？所有的动态规划，都可以抽象为一张DAG图，状态数就对应图上所有的节点数目，转移数就对应单个节点的出边，所以DP的时间复杂度也等于$O(V + E), V为DAG图上的节点数，E为DAG图上的边数，且每个节点，每条边都只访问一次$

    - 在多数情况下，递推法的时间复杂度是：$状态总数×每个状态的决策个数×决策时间$。如果不同状态的决策个数不同，需具体问题具体分析。

    - <div align=center >
      <img alt="aa" src="../pics/dagto.png" style="zoom:70%"/>
      <p> 我为人人 示例图 </p>
    </div>
      
    - <div align=center >
    <img alt="aa" src="../pics/dagfrom.png" style="zoom:70%"/>
        <p> 人人为我 示例图 </p>
        </div>

  - 这两种方法本质是一样的，只是在代码实现层面，有的题目适合**人人为我**写法，有的题目适合**我为人人**写法，当然大多数题目两种写法都可。

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

  - 在**人人为我**的写法中，$状态i$只与$状态i - 1$和$状态i - 2$有关，所以我们并不需要存放$状态i - 3, i - 4$,..., 这样可以节约大量的内存，只需少量几个变量即可，这就是我们常说的**滚动数组**优化。

      ```cpp
      // "人人为我"的"滚动数组"优化
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

  - 上面我们使用的都是动态规划里递推的方法，本题的一个递归方法实现如下

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

  - 如果我们把处理过的记录下来，便是记忆化了，本题的一个**记忆化搜索**的实现如下

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

  - 至此，我们通过[爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/)这道例题，讲解了大量的概念，和与之对应的代码实现。希望能更好的帮助初学者。当然基于"人人为我"的递推式，还可以把递推式变形成"矩阵快速幂"，但这已不属于初学者的范畴，不过在后面的"动态规划的优化"的相关章节会陆续讲解这类比较套路的DP优化。

- 例题B_002：[数字三角形 Number Triangles](https://www.luogu.com.cn/problem/P1216)

  - 题目描述

    ```
    观察下面的数字金字塔。写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。
    在下面的样例中，从7->3->8->7->5的路径产生了最大权值。
    ```

    <div align=center >
        <img alt="xxxx" src="../pics/Number_Triangles.png" style="zoom:0%" />
        <p> 数字三角形 </p>
    </div>

  - 题目样例

    ```
    // 输入
    第一个行一个正整数r，表示行的数目。
    后面每行为这个数字金字塔特定行包含的整数。
    5
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
    // 输出
    单独的一行,包含那个可能得到的最大的和
    30
    ```

  - 题目解析一

    ```
    状态的定义：f(i, j)表示从顶部出发，走到坐标(i, j)时能获得的最大值
    状态的转移：从当前坐标(i, j)，要么走向左下方，要么走向右下方
    状态的边界：走到数字三角形的边界
    ```

    - 状态的转移
      -  如下，**我为人人**形式的递推
      - $f(i, \ j) \begin{cases} \rightarrow f(i + 1, \ j)，往左下方走\\ \rightarrow f(i + 1, \ j + 1)，往右下方走\end{cases}$
    - 状态的边界
      - $f(1, \ 1) = a[1][1]$
    - 时间复杂度
      - $O(N ^ 2)$
    - 在递推法实现中，状态的边界就是对应状态的初始化，以后不在说明

  - 代码实现

    - 如下，我为人人的递推写法

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e3 + 5;
      int r, a[N][N], dp[N][N], ans = 0;
      
      int main() {
        cin >> r;
        for (int i = 1; i <= r; ++i)
          for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
            
        dp[1][1] = a[1][1];
        for (int i = 1; i <= r - 1; ++i) {
          for (int j = 1; j <= i; ++j) {
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
            dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
          }
        }
        for (int j = 1; j <= r; ++j) ans = std::max(ans, dp[r][j]);
        cout << ans << "\n";
        return 0;
      }
      ```

  - 题目解析二

    - 这是第二种写法，状态的定义不变，但是转移形式有所变化
    - 状态的转移
      - 如下，**人人为我**形式的递推
      - $f(i, \ j) \begin{cases} \leftarrow f(i - 1, \ j - 1) \ + \ a[i][j]，从左上方而来\\ \leftarrow f(i - 1, \ j) \ + \ a[i][j]，从右上方而来\end{cases}$
    - 状态的边界
          - $f(1, \ 1) = a[1][1]$
    
  - 代码实现

    - 如下，人人为我的递推写法, 由于$f(i, ...)只由f(i - 1, ...)转移而来，所以可以滚动数组优化$，见下面的实现

      ```cpp
      // 人人为我，无滚动数组优化
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e3 + 5;
      int r, a[N][N], dp[N][N], ans = 0;
      
      int main() {
        cin >> r;
        for (int i = 1; i <= r; ++i)
          for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
            
        dp[1][1] = a[1][1];
        for (int i = 1; i <= r; ++i) {
          for (int j = 1; j <= i; ++j) {
            dp[i][j] = std::max({dp[i - 1][j] + a[i][j], dp[i - 1][j - 1] + a[i][j]});
          }
        }
        for (int j = 1; j <= r; ++j) ans = std::max(ans, dp[r][j]);
        cout << ans << "\n";
        return 0;
      }
      ```
      
       ```cpp
      // 人人为我，滚动数组优化，注意dp数组第一维的大小是2，状态里全部加上"&"就可以简单的实现滚动数组优化了，这也是如何改写为滚动数组优化的技巧.
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e3 + 5;
      int r, a[N][N], dp[2][N], ans = 0;
      
      int main() {
        cin >> r;
        for (int i = 1; i <= r; ++i)
          for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
            
        dp[1 & 1][1] = a[1][1];
        for (int i = 1; i <= r; ++i) {
          for (int j = 1; j <= i; ++j) {
            dp[i & 1][j] = std::max({dp[i - 1 & 1][j] + a[i][j], dp[i - 1 & 1][j - 1] + a[i][j]});
          }
        }
        for (int j = 1; j <= r; ++j) ans = std::max(ans, dp[r & 1][j]);
        cout << ans << "\n";
        return 0;
      }
       ```
    
  - 题目解析三
  
      - 我们知道所有的动态规划都可以抽象成一个有向无环图（即DAG图），有时这个DAG图是显式的，有时是隐式的。
      - **DAG模型**：DAG图上的动态规划如计算最长路、最短路或路径计数问题，由于DAG最长（短）路的特殊性，有两种“对称”的状态定义方式。
        - 状态一：$设f(X)表示从状态X出发的最长路（最短路、方案数...）$，转移时考虑状态X能转移到哪些状态，刷表法（也就是递推法里的我为人人）
        - 状态二：$设f(X)表示以状态X结束的最长路（最短路、方案数...）$，转移时考虑状态X由哪些状态转移而来，填表法（也就是递推法里的人人为我）
        - 状态的定义里一个是起点，一个是终点。
  
  - 代码实现
  
    - DAG模型常常用记忆化搜索的方式实现，由于加了记忆化每个状态节点只会被计算一次，所以时间复杂度也为$O(N ^ 2)$
  
    - 状态的定义：$f(i, \ j)表示以位置(i, \ j)出发能获得的最大路径和$
  
    - 状态的转移：$f(i, \ j) \begin{cases} \rightarrow f(i + 1, \ j)，往左下方走\\ \rightarrow f(i + 1, \ j + 1)，往右下方走\end{cases}$
  
      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e3 + 5;
      int r, a[N][N], dp[N][N], ans = 0;
      
      // dp[i][j]表示从位置(i, j)出发能获得的最大路径和
      int dfs(int i, int j) {
        if (i == r + 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = std::max({dfs(i + 1, j) + a[i][j], dfs(i + 1, j + 1) + a[i][j]});
      }
      
      int main() {
        cin >> r;
        for (int i = 1; i <= r; ++i)
          for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
        
        std::memset(dp, -1, sizeof dp);
        cout << dfs(1, 1) << "\n";
        return 0;
      }
      ```
  
    - 状态的定义：$f(i, \ j)表示以位置(i, \ j)结束能获得的最大路径和$
  
    - 状态的转移：$f(i, \ j) \begin{cases} \leftarrow f(i - 1, \ j - 1) \ + \ a[i][j]，从左上方而来\\ \leftarrow f(i - 1, \ j) \ + \ a[i][j]，从右上方而来\end{cases}$

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e3 + 5;
      int r, a[N][N], dp[N][N], ans = 0;
      
      // dp[i][j]表示以位置(i, j)结束能获得的最大路径和
      int dfs(int i, int j) {
        if (i == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = std::max({dfs(i - 1, j - 1) + a[i][j], dfs(i - 1, j) + a[i][j]});
      }
      
      int main() {
        cin >> r;
        for (int i = 1; i <= r; ++i)
          for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
        
        std::memset(dp, -1, sizeof dp);
        for (int j = 1; j <= r; ++j) ans = std::max(ans, dfs(r, j));
        cout << ans << "\n";
        return 0;
      }
      ```
  
  - 总结一下：
    - 状态的定义一：$f(i, \ j)表示以位置(i, \ j)出发能获得的最大路径和$，基于这个状态的定义，有递推法和记忆化搜索两种实现方式
    - 状态的定义二：$f(i, \ j)表示以位置(i, \ j)结束能获得的最大路径和$，基于这个状态的定义，有递推法和记忆化搜索两种实现方式
    - 所以上面一共实现了四份代码（除去滚动数组优化的实现），希望大家好好理解。对于这四种实现虽然本质都相同，但是在一些时间复杂度要求更高的题目中，**人人为我**的递推实现中，常常可以优化转移的时间，如**前缀和优化DP、线段树优化DP...**，为啥可以优化转移呢？因为在**人人为我**的DP实现中哪些要依赖的状态都已经计算好了，所以我们可以对已计算好的状态利用一些数据结构等技巧优化转移。
    - 对于后面要讲的DP问题，在时间复杂度可以通过题目的情况下，我就只实现其中一种了，由于个人偏好我常常用记忆化搜索的方式实现。

- 例题B_003：[最长上升子序列 LIS](https://www.luogu.com.cn/problem/AT_chokudai_S001_h)

  - 题目描述

    ```
    给定一个长为n的序列ai，求这个序列的最长单调上升子序列长度。N <= 1e5
    ```

  - 题目样例

    ```
    // 输入
    5
    3 1 5 4 2
    
    // 输出
    2
    ```

  - 题目解析

    - 先给出经典的$O(N ^ 2)$的做法
    - 状态的定义：$f(i)表示前i个元素[1: i], 以第i个元素结尾时，最长单调上升子序列长度$
    - 状态的转移：$f(i) = max\{ f(j) + 1 \}, 且\ a[j] \ < \ a[i]$
    - 状态的边界：$f(i) = 1, 只有自己一个元素$
    - 时间复杂度：$状态数为O(N), 转移要O(N), 所以总的时间复杂度为O(N ^ 2)$

  - 代码实现

    - 如下，由于本题数据范围过大，$O(N^2)$的做法并不能通过，可以去这提交[最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)，参考代码here：[longest-increasing-subsequence.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/longest-increasing-subsequence.cpp)

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 5e3 + 5;
      int n, a[N], dp[N], ans = 1;
      
      int main() {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        
        for (int i = 1; i <= n; ++i) {
          dp[i] = 1;
          for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
              dp[i] = std::max(dp[i], dp[j] + 1);
            }
          }
          ans = std::max(ans, dp[i]);
        }
        cout << ans << "\n";
        return 0;
      }
      ```

  - 题目解析二

    - 本题存在一个经典的贪心 + 二分做法
    - 状态的定义：$f(i)表示从左往右扫描数组时，最长递增子序列长度为i时，这个子序列结尾的最小值$
    - 由于这里结尾保存的最小值，体现了贪心的思想
    - 由于是从左往右扫描，当扫描到$a[i]$时，如何快速插入$a[i]$到合适位置用到了二分，因为按照上面的状态的定义，长度为3的子序列的结尾的值，肯定小于长度为4的子序列的结尾的值，即长度越大值越大，所以可以二分。

  - 代码实现

    - 如下，时间复杂度$O(N * logN)$，下面的实现中$dp$数组下标是从0开始的，所以$dp[i]$保存的长度就是$i + 1$

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      // dp[i]表示从左往右扫描数组时，最长递增子序列长度为i+1时，这个子序列结尾的最小值
      vector<int> dp;
      int n, x;
      
      int main() {
      
        cin >> n;
        for (int i = 1; i <= n; ++i) {
          cin >> x;
          auto it = std::lower_bound(dp.begin(), dp.end(), x);
          
          if (it == dp.end()) dp.push_back(x);
          else *it = x;
        }
        cout << dp.size() << "\n";
        return 0;
      }
      ```
  
- 例题B_004：[最长公共子序列 LCS](https://www.luogu.com.cn/problem/P1439)

  - 题目描述

    ```
    给出1,2,...,n的两个排列P1和P2，求它们的最长公共子序列。N <= 1e5
    ```

  - 题目样例

    ```
    // 输入
    5 
    3 2 1 4 5
    1 2 3 4 5
    
    // 输出
    3
    ```

  - 题目解析

    - 先给出经典的$O(N ^ 2)$的做法
    - 状态的定义：$f(i, \ j)表示排列P1的前i个元素，排列P2的前j个元素，它们的最长的公共子序列的长度$
    - 状态的转移：$f(i, \ j) \begin{cases} \leftarrow f(i - 1, \ j - 1) \ + \ 1，\ \ P1[i] \ = P2[j] \\ \\ \leftarrow max\{ f(i - 1, \ j), f(i, j - 1) \} \ + \ 0，\ \ P1[i] \ != P2[j] \end{cases}$
    - 状态的边界：$f(0, \ j) = 0, f(i, \ 0) = 0$

  - 代码实现

    - 如下，本题范围是$1e5$，所以$O(N^2)$的做法会超时，可以去这提交数据范围更小的题[最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)，参考代码here：[longest-common-subsequence.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/longest-common-subsequence.cpp)

    - 在记忆化搜索的实现中，未访问过的状态一般初始化为-1，也就是代码里的$std::memset(dp, -1, sizeof\ \ dp)$这行
    
      ```cpp
    // 记忆化搜索实现，时间复杂度O(N ^ 2)
      #include <bits/stdc++.h>
    using namespace std;
      
      const int N = 1e3 + 5;
      int n, P1[N], P2[N], dp[N][N];
      
      // dp[i][j]：表示排列P1的前i个元素，排列P2的前j个元素，它们的最长的公共子序列的长度
      int dfs(int i, int j) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ret = 0;
        if (P1[i] == P2[j]) ret = std::max(ret, dfs(i - 1, j - 1) + 1);
        return dp[i][j] = std::max({ret, dfs(i - 1, j), dfs(i, j - 1)});
      }
      
      int main() {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> P1[i];
        for (int i = 1; i <= n; ++i) cin >> P2[i];
        
        std::memset(dp, -1, sizeof dp);
        cout << dfs(n, n) << "\n";
        return 0;
      }
      ```
      

  - 题目解析二
    
    - 巧妙的转化，将排列等价映射，转化成$LIS$问题
    
      ```
      A:3 2 1 4 5
      B:1 2 3 4 5
      
      我们不妨给它们重新标个号：把3标成a,把2标成b，把1标成c……于是变成：
      
      A: a b c d e
      B: c b a d e
      
      这样标号之后，LCS长度显然不会改变。但是出现了一个性质：
      
      两个序列的子序列，一定是A的子序列。而A本身就是单调递增的。
      因此这个子序列是单调递增的。
      
      换句话说，只要这个子序列在B中单调递增，它就是A的子序列。
      
      哪个最长呢？当然是B的LIS最长。
      
      自此完成转化。
      ```
  
  - 代码实现二
  
    - 等价映射转化为$LIS$问题，而$LIS$问题可以做到$O(N * logN)$
  
      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e5 + 5;
      int mp[N], n, x;
      
      int LIS(const vector<int> &v) {
        vector<int> dp;
        for (auto &c: v) {
          auto it = lower_bound(dp.begin(), dp.end(), c);
          if (it == dp.end()) dp.push_back(c);
          else *it = c;
        }
        return dp.size();
      }
      
      int main() {  
        cin >> n;
        for (int i = 1; i <= n; ++i) {
          cin >> x;
          mp[x] = i;
        }
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
          cin >> x;
          v.push_back(mp[x]);
        }
        cout << LIS(v);
        return 0;
      }
      ```

- 例题B_005：[编辑距离](https://www.luogu.com.cn/problem/P2758)

  - 题目描述

    ```
    设A和B是两个字符串。我们要用最少的字符操作次数，将字符串A转换为字符串B。这里所说的字符操作共有三种：
    	1. 删除一个字符；
    	2. 插入一个字符；
    	3. 将一个字符改为另一个字符。
    A,B均只包含小写字母
    ```

  - 题目样例

    ```
    输入：A = "horse", B = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')
    ```

  - 题目解析

    - 状态的定义：$f(i, j)表示将字符串A的前i个字符[0:i]，使用三种操作转换为，字符串B的前j个字符[0:j]，的最少操作数$

    - 状态的转移：$f(i, \ j) \begin{cases} \leftarrow f(i - 1, \ j) \ + \ 1，\ \ 删除A里的第i个字符 \\ \\ \leftarrow max\{ f(i, \ j - 1) \ + \ 1, \ \ 在A的末尾插入一个字符B[j] \\ \\ \leftarrow f(i - 1, j - 1) \} \ + \ 1，\ \ 将A[i]改为B[j]，注意到如果A[i] = B[j]那显然不用改了 \end{cases}$

    - 状态的边界：$f(-1, j) = j + 1, f(i, -1) = i + 1$

  - 代码实现

    - 如下，记忆化实现

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 2e3 + 5;
      int dp[N][N];
      string s1, s2;
      
      // dp[i][j]表示将字符串A的前i个字符[0:i]，使用三种操作转换为，字符串B的前j个字符[0:j]，的最少操作数
      int dfs(int i, int j) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (dp[i][j] != -1) return dp[i][j];
        int ret = i + j, flag = (s1[i] == s2[j]? 0: 1);
        return dp[i][j] = std::min({dfs(i - 1, j) + 1, dfs(i, j - 1) + 1, dfs(i - 1, j - 1) + flag});
      }
      
      int main() {
        cin >> s1 >> s2;
        
        std::memset(dp, -1, sizeof dp);
        cout << dfs(s1.size() - 1, s2.size() - 1) << "\n";
        return 0;
      }
      ```

- 例题B_006：[斐波那契乘积](https://www.luogu.com.cn/problem/P10095)

  - 题目描述

    ```
    给定一个自然数n，求出将其表示为大于1的斐波那契数的乘积的方式数量。 N <= 1e18
    斐波那契数指斐波那契数列（f(0) = 1, f(1) = 1, f(i) = f(i - 1) + f(i -2)）中出现的数。
    ```

  - 题目样例

    ```
    // 多组输入，第一行输入的数表示组数
    5
    2
    7
    8
    40
    64
    
    // 输出
    1
    0
    2
    2
    3
    
    样例解释
    2 = 2
    7无法被表示为斐波那契乘积
    8 = 8 = 2 * 2 * 2
    40 = 5 * 8 = 2 * 2 * 2 * 5
    64 = 8 * 8 = 2 * 2 * 2 * 8 = 2 * 2 * 2 * 2 * 2 * 2
    ```

  - 题目解析
    - N看起来很大，不过斐波那契数增长的很快，所以在N的范围内，斐波那契数的个数并不是很多（不到90个），所以可以DP解决
    - 由于是多组数据输入，我们先预处理$<=1e18$内的所有斐波那契数，存放到$nums$数组里
    - 状态的定义：$f(i, x)表示nums数组里的前i个元素[0:i], 构成斐波那契数的乘积为x，的方式数量$
    - 状态的转移：$f(i, \ x) \begin{cases} \leftarrow f(i, \ x \ / \ nums[i])，\ x \ \% \ nums[i] = 0, 拆出一个nums[i]出来（注意由于可能可以拆除多个nums[i], 所以i的下标不变） \\ \\ \leftarrow max\{ f(i - 1, \ x), \ \ 一个nums[i]也不选，直接跳过 \end{cases}$

  - 代码实现

    - 如下，记忆化实现，由于$dp[{i, \ x}]$里的x数值可能很多，所以用$std::map$保存状态

    - 看样例解释拆分出来的数都是从小到大的，我们$dfs$拆分时是从大到小拆分的（$nums$本身是有序的），方案数是等价的/一样的

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      using ll = long long;
      using pii = pair<int, ll>;
      
      const ll N = 1e18 + 5;
      ll t, n;
      map<pii, ll> dp;
      vector<ll> nums;
      
      // dp[{i, x}]表示nums数组里的前i个元素[0:i]，构成斐波那契数的乘积为x，的方式数量
      ll dfs(int i, ll x) {
        if (i < 0) return x == 1? 1: 0;
        if (dp.count({i, x})) return dp[{i, x}];
        ll ret = 0;
        // 选出一个nums[i]
        if (x % nums[i] == 0) ret += dfs(i, x / nums[i]);
        // 跳过nums[i]
        ret += dfs(i - 1, x);
        return dp[{i, x}] = ret;
      }
      
      int main() {
        // 先预处理出<=N范围内的所有斐波那契数，虽然看起来N很大，但是在这个范围内的斐波那契数不会太多
        ll a = 1, b = 2, c;
        while (b < N) {
          nums.push_back(b);
          c = a + b;
          a = b;
          b = c;
        }
        // cout << nums.size() << "\n";
        
        cin >> t;
        while (t--) {
          cin >> n;
          cout << dfs(nums.size() - 1, n) << "\n";
        }
        return 0;
      }
      ```

- 例题B_007：[最大正方形](https://www.luogu.com.cn/problem/P1387)

  - 题目描述

    ```
    在一个n×m的只包含0和1的矩阵里找出一个不包含0的最大正方形，输出边长。
    ```

  - 题目样例

    ```
    // 输入
    4 4
    0 1 1 1
    1 1 1 0
    0 1 1 0
    1 1 0 1
    
    // 输出
    2
    ```

  - 题目解析

    ```
    题目要求全1的最大正方形的边长，可以考虑每一个以（x, y）为右下角顶角的情况
    ```

    - 状态的定义：$f(x, y)表示以坐标(x, y)为右下角顶角的最大正方形的边长$，$up(x, y)表示以坐标(x, y)向上连续1的个数，同理left$
    - 状态的转移：$f(x, y) = min\{\ f(x - 1, y - 1) + 1, \ left(x, y), \ up(x, y)\ \}$
    - 时间复杂度：$从上到下，从左到右开始遍历，每个坐标（x，y）都只访问一次，所以总的时间复杂度为O(N ^ 2)$

  - 代码实现

    - 如下，看着类似的题[最大子矩阵](https://leetcode.cn/problems/max-submatrix-lcci/)（提示：直接枚举4个顶角$O(N ^ 4)$，可以枚举上下边界, 再求最大子段和$O(N ^ 3)$ 

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e2 + 5;
      int n, m, ans, a[N][N], dp[N][N], up[N][N], Left[N][N];
      
      int main() {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
        
        // 有三个状态dp, up, left，都可以在（从上到下，从左到右）一次遍历求得。
        for (int x = 1; x <= n; ++x) {
          for (int y = 1; y <= m; ++y) {
            if (a[x][y] == 0) {
              dp[x][y] = up[x][y] = Left[x][y] = 0;
            }
            else {
              up[x][y] = up[x - 1][y] + 1;
              Left[x][y] = Left[x][y - 1] + 1;
              dp[x][y] = std::min({dp[x - 1][y - 1] + 1, Left[x][y], up[x][y]});
            }
            ans = std::max(ans, dp[x][y]);
          }
        }
        cout << ans << "\n";
        return 0;
      }
      ```

- 例题B_008：[滑雪](https://www.luogu.com.cn/problem/P1434)

  - 题目描述

    ```
    给定一个R x C整数矩阵，找出其中最长递增路径的长度。
    对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在 角线方向上移动或移动到边界外（即不允许环绕）
    ```

  - 题目样例

    ```
    // 输入
    3 3
    9 9 4
    6 6 8
    2 1 1
    
    // 输出
    4
    ```

    <div align=center >
        <img alt="xxxx" src="../pics/longest-increasing-path-in-a-matrix.jpg" style="zoom:0%" />
    </div>

  - 题目解析

    - 由于只能从值大的（A）走到值小的（B）,我们从A连一条有向边到B，即A --> B，那么整个滑雪过程其实就是再DAG图上滑动。属于我们上面讲的（显式）DAG模型。
    - 状态的定义：$f(x, y)表示从坐标（x, y）出发，能获得的最长距离$
    - 状态的转移：$f(x, y) = max\{ \ f(newx, newy) + 1，\ (newx, \ newy)是能从(x, y)一步可以走到的点的坐标\}$

    - 时间复杂度：$O(R * C) = 状态数O(R * C) * 转移数O(1)$

  - 代码实现

    - 如下，相似的题[矩阵中的最长递增路径](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/)，[矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/)，[Integers on Grid](https://www.luogu.com.cn/problem/AT_abc224_e)（难，需要DP优化，后面统一在DP优化章节讲）

    - 下面的代码是以某状态出发实现的，我们知道DAG模型，有两种对称的状态的定义，如果以某状态结束该怎么实现呢？

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1e2 + 5;
      const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
      int R, C, ans, a[N][N], dp[N][N];
      
      // dp[x][y]表示从坐标（x, y）出发，能走的最长的距离
      int dfs(int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];
        int ret = 1;
        for (int i = 0; i < 4; ++i) {
          int newx = x + dx[i], newy = y + dy[i];
          if (newx >= 1 && newx <= R && newy >= 1 && newy <= C && a[newx][newy] < a[x][y])
            ret = std::max(ret, dfs(newx, newy) + 1);
        }
        return dp[x][y] = ret;
      }
      
      int main() {
        cin >> R >> C;
        for (int i = 1; i <= R; ++i)
          for (int j = 1; j <= C; ++j)
            cin >> a[i][j];
        
        std::memset(dp, -1, sizeof dp);
        for (int i = 1; i <= R; ++i)
          for (int j = 1; j <= C; ++j)
            ans = std::max(ans, dfs(i, j));
        
        cout << ans << "\n";
        return 0;
      }
      ```

- 例题B_009：[最长路](https://www.luogu.com.cn/problem/P1807)

  - 题目描述

    ```
    设G为有n个顶点的带权有向无环图，G中各顶点的编号为1到n，请设计算法，计算图G中1到n的最长路。
    ```

  - 题目样例

    ```
    // n <= 1500, m <= 5e4
    // 输入，顶点数n，边数m
    2 1
    1 2 1
    
    // 输出
    1
    ```

  - 题目解析
    - 带权有向无环图，DAG模型
    - 状态的定义：$f(u)表示从节点u出发，到达节点n的最长路$
    - 状态的转移：$f(u) = max\{\ f(v) + w，其中<u, v, w>, 表示有一条边u连接v，且权值为w\}$
    - 时间复杂度：$O(V + E), 图中每个顶点，每条边，都只访问一次$

  - 代码实现

    - 如下，看下$std::array$的用法

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 1500 + 5, INF = 1e9;
      int n, m, dp[N];
      vector<array<int, 2> > g[N];
      
      // dp[u]表示从节点u出发，到达节点n的最长路。
      // 如果dp[u] = -INF, 表示从节点u出发，无法到达节点n
      int dfs(int u) {
        if (u == n) return 0;
        if (dp[u] != -1) return dp[u];
        int ret = -INF;
        for (auto &c: g[u]) {
          int v = c[0], w = c[1];
          ret = std::max(ret, dfs(v) + w); 
        }
        return dp[u] = ret;
      }
      
      int main() {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
          int u, v, w;
          cin >> u >> v >> w;
          g[u].push_back({v, w});
        }
        
        std::memset(dp, -1, sizeof dp);
        int ans = dfs(1);
        if (ans < 0) cout << -1;
        else cout << ans;
        return 0;
      }
      ```
  
- 例题B_010：[Backward Digit Sums](https://www.luogu.com.cn/problem/P1118)

  - 题目描述

    ```
    写出一个1∼n 的排列a，然后每次将相邻两个数相加，构成新的序列，再对新序列进行这样的操作，显然每次构成的序列都比上一次的序列长度少1，直到只剩下一个数字位置。
    
    下面时一个例子
    3 1 2 4
    4 3 6
    7 9
    16
    最后得到16这样一个数字
    
    现在给出n，以及最后得到的数字大小sum，请你求出最初的序列a。如果有多个答案，则输出字典序最小的哪个。
    ```

  - 题目样例

    ```
    // 输入
    4 16
    
    // 输出
    3 1 2 4
    ```

  - 题目解析

    ```
    可以发现当给出一个n时，最后的答案的系数对应杨辉三角的第n - 1行。
    
    所以可以先递推预处理杨辉三角，然后搜索。
    ```

  - 代码实现

    - 如下，杨辉三角和组合数关系密切

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      /* 杨辉三角
      1
      1 1
      1 2 1
      1 3 3 1
      1 4 6 4 1
      */
      
      /*
      n = 5时，最后的系数为1 4 6 4 1, 对应杨辉三角的第4行（从0开始）
      
      a     b     c     d      e
        a+b   b+c   c+d     d+e
         a+2b+c b+2c+d  c+2d+e
          a+3b+3c+d b+3c+3d+e
              a+4b+6c+4d+e
      */
      
      const int N = 12 + 5;
      // 杨辉三角
      int n, sum, found, c[N][N], vis[N];
      vector<int> ans;
      
      void dfs(int i, int s, vector<int> &path) {
        // 剪枝
        if (s > sum || found) return ;
        if (i == n) {
          if (s == sum) {
            found = 1;
            ans = path;
          }
          return ;
        }
        for (int num = 1; num <= n; ++num) {
          if (vis[num] == 0) {
            vis[num] = 1;
            path.push_back(num);
            // c[n - 1][i] * num, 也就是这一位在最后的答案里的权重
            dfs(i + 1, s + c[n - 1][i] * num, path);
            // 回溯
            path.pop_back();
            vis[num] = 0;
          }
        }
      }
      
      int main() {
        // 递推预处理杨辉三角
        c[0][0] = 1;
        for (int i = 1; i < N; ++i) {
          for (int j = 0; j <= i; ++j) {
            if (j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
          }
        }
        cin >> n >> sum;
        
        vector<int> path;
        dfs(0, 0, path);
        if (found) {
          for (auto &c: ans) cout << c << " ";
        }
        return 0;
      }
      ```

- 例题B_011：[吃奶酪](https://www.luogu.com.cn/problem/P1433)

  - 题目描述

    ```
    房间里放着N块奶酪。一只小老鼠要把它们都吃掉，问至少要跑多少距离？老鼠一开始在 (0,0) 点处。N <= 15
    ```

    - 对于两个点 $(x_1,y_1)$，$(x_2, y_2)$，两点之间的距离公式为 $\sqrt{(x_1-x_2)^2+(y_1-y_2)^2}$

  - 题目样例

    ```
    // 输入
    4
    1 1
    1 -1
    -1 1
    -1 -1
    
    // 输出
    7.41（保留2位小数）
    ```

  - 题目解析一

    - 状态的定义：$f(u, dis, cnt, vis)表示当前走到节点u，走过的距离为dis，走过哪些点的个数为cnt，走过哪些点保存在vis$
    
    - 状态的转移：$f(u, dis, cnt, vis) \rightarrow f(new\_u，new\_dis，new\_cnt，new\_vis)，枚举下一个未访问过的点new\_u$

    - 代码实现如下, 交上去喜提$TLE$
    
      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 15 + 2;
      int n, vis[N];
      float x[N], y[N], ans = 1e9;
      
      float distance(int u, int v) {
        return std::sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
      }
      
      // vis并未保存在dfs函数的参数列表里，而是一个全局变量
      // 状态<u, dis, cnt, vis>表示当前走到节点u，走过的距离为dis，走过哪些点的个数为cnt，走过哪些点保存在vis
      void dfs(int u, float dis, int cnt) {
        // 边界
        if (cnt == n) {
          ans = std::min(ans, dis);
          return ;
        }
        // 剪枝
        if (dis > ans) return ;
        // 枚举下一个未选择的点
        for (int v = 1; v <= n; ++v) {
          if (vis[v] == 0) {
            vis[v] = 1;
            dfs(v, dis + distance(u, v), cnt + 1);      
            vis[v] = 0;
          }
        }
      }
      
      int main() {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
        
        vis[0] = 1;
        dfs(0, 0, 0);
        cout << setprecision(2) << fixed << ans << endl;
        return 0;
      }
      ```
    
  - 题目解析二

    - ```cpp
      假设我们访问过了节点0 3 5, 也就是vis[0] = vis[3] = vis[5] = 1
      
      放在二进制下, num = 2 ^ 0 + 2 ^ 3 + 2 ^ 5 = 1 + 8 + 32 = 41.
      
      也就是说我们可以用num=41来表示访问过了节点0 3 5.
      
      把一堆数字{0, 3, 5}压缩为一个状态41，也就是大家常说的状态压缩。
      ```

    - N <= 15, 我们可以把哪些访问过的点压缩为一个状态，进行下面的状态压缩DP

    - 状态的定义：$f(u，vis)表示当前在u节点，已经访问过的节点集合为vis时，从此出发，访问完所有节点的最小距离$

    - 状态的转移：$f(u，vis) \leftarrow min\{\ f(v，new\_vis) + distance(u, v) \ \}，枚举下一个未访问的节点v$

    - 时间复杂度：$状态数 * 转移数 = O(n * 2^n) * O(n) = O(n^2 * 2^n)$

    - 代码实现如下，状态的定义我们是按照从某个节点出发进行的

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 15 + 2, INF = 1e9;
      int n, visited[N][1 << N];
      float x[N], y[N], dp[N][1 << N];
      
      float distance(int u, int v) {
        return std::sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
      }
      
      // 从<u, vis>节点u出发，已经访问过的点的集合为vis，访问完所有节点，的最小距离
      float dfs(int u, int vis) {
        if (vis == (1 << (n + 1)) - 1) return 0;
        if (visited[u][vis]) return dp[u][vis];
        
        float ret = INF;
        // 枚举下一个未访问的点v
        for (int v = 1; v <= n; ++v) {
          if (((1 << v) & vis) == 0) {
            ret = std::min(ret, dfs(v, vis + (1 << v)) + distance(u, v));
          }
        }
        visited[u][vis] = 1;
        return dp[u][vis] = ret;
      }
      
      int main() {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
        
        cout << setprecision(2) << fixed << dfs(0, 1) << endl;
        return 0;
      }
      ```

- 例题B_012：[取数游戏](https://www.luogu.com.cn/problem/P1123)

  - 题目描述

    ```
    一个N×M的由非负整数构成的数字矩阵，你需要在其中取出若干个数字，使得取出的任意两个数字不相邻（若一个数字在另外一个数字相邻8个格子中的一个即认为这两个数字相邻），求取出数字和最大是多少。N, M <= 6, T <= 20
    ```

  - 题目样例

    ```
    // 输入，第一行代表数据组数，接下来输入N和M，代表数字矩阵的N行M列
    3
    4 4
    67 75 63 10
    29 29 92 14
    21 68 71 56
    8 67 91 25
    2 3
    87 70 85
    10 3 17
    3 3
    1 1 1
    1 99 1
    1 1 1
    
    // 输出
    271
    172
    99
    ```

    <div align="center" style="height:265px">
        <img alt="xxxx" src="../pics/P1123.png" style="zoom:0%"/>
    </div>

  -  题目解析

    - 状态的定义：$f(x，y，sum，vis)表示走到了（x, y）坐标，目前和为sum（不包括当前坐标(x, y)），访问过的坐标保存在vis里$

    - 状态的转移：$f(x，y，sum，vis) \rightarrow f(x，y + 1, new\_sum，new\_vis) 对于当前坐标（x, y）选还是不选$

  - 代码实现

    - 如下, $dfs$的过程是一个格子一个格子，从左到右从上到下 进行的

      ```cpp
      #include <bits/stdc++.h>
      using namespace std;
      
      const int N = 6 + 2;
      const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
      const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
      int T, n, m, ans, a[N][N], vis[N][N];
      
      // 如果(x, y)被选，那相邻8个格子都不能有选的
      bool check(int x, int y) {
        for (int i = 0; i < 8; ++i) {
          int newx = x + dx[i], newy = y + dy[i];
          if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy])
            return 0;
        }
        return 1;
      }
      
      // dfs的过程是一个格子一个格子，从左到右从上到下 进行的
      // 状态：<x, y, sum， vis>表示走到了（x, y）坐标，目前和为sum（不包括当前坐标(x, y)），访问过的坐标保存在vis里
      // 转移：对于当前坐标（x, y）选还是不选
      void dfs(int x, int y, int sum) {
        // 边界，走到了(n + 1, 1)的位置
        if (x == n + 1) {
          if (sum > ans) ans = sum;
          return ;
        }
        // 本行走完了，该走下一行了
        if (y == m + 1) return dfs(x + 1, 1, sum);
        // 不选(x, y)
        dfs(x, y + 1, sum);
        // 选(x, y), 那就得确保满足已经选了的元素没有和它相邻的
        if (check(x, y)) {
          vis[x][y] = 1;
          dfs(x, y + 1, sum + a[x][y]);
          vis[x][y] = 0;
        }
      }
      
      int main() {
        cin >> T;
        while (T--) {
          cin >> n >> m;
          for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> a[i][j];
      
          ans = 0;    
          dfs(1, 1, 0);
          cout << ans << "\n";
        }
        return 0;
      }
      ```


- 例题B_013：[最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

  - 题目描述

    ```
    给你一个整数数组nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。子数组是数组中的一个连续部分。
    ```

  - 题目样例

    ```
    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出：6
    解释：连续子数组[4,-1,2,1]的和最大，为6 。
    ```

  - 题目解析

    - 状态的定义：$f(i)表示考虑前i个元素[0:i]以第i个元素结尾，的最大值$
    - 状态的转移：$f(i) \begin{cases} \leftarrow nums[i]，单独存在\\ \\ \leftarrow f(i - 1) + a[i]，和前面的一段连在一起 \end{cases}$
    - 时间复杂度：$状态数为O(N)，转移为O(1)，所以总的时间复杂度为O(N)$

  - 代码实现

    - 如下，看着类似的题[Longest X](https://www.luogu.com.cn/problem/AT_abc229_d)（提示滑动窗口或二分答案）

      ```cpp
      class Solution {
      public:
          // dp[i]表示已第i个元素结尾的连续最大和
          // 由于dp[i]只和dp[i - 1]有关, 所以可以滚动，用一个变量pre表示dp[i - 1]的状态就行
          int maxSubArray(vector<int>& nums) {
              int n = nums.size(), pre = 0, ans = -1e9;
              for (int i = 0; i < n; ++i) {
                  pre = std::max(nums[i], pre + nums[i]);
                  ans = std::max(ans, pre);
              }
              return ans;
          }
      }; 
      ```

- 例题B_014：[环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/)

  - 题目描述

    ```
    给定一个长度为n的环形整数数组nums，返回nums的非空子数组的最大可能和。环形数组意味着数组的末端将会与开头相连呈环状
    ```

  - 题目样例

    ```
    输入：nums = [1,-2,3,-2]
    输出：3
    解释：从子数组 [3] 得到最大和 3
    ```

  - 题目解析

    ```
    最大的可能和，只可能有两种形式：情况一：单独的某一段，为答案；情况二：开头的一段 + 末尾的一段，为答案
    ```

    - 状态的定义：$f(i)表示前i个元素[0:i]，前缀和的最大值$
    - 状态的转移：$f(i) = max\{ f(i - 1)，s[0:i] \ 其中s[0:i]表示前i个元素的和\}$

  - 代码实现

    - 如下，总的时间复杂度为$O(N)$

      ```cpp
      class Solution {
      public:
          int maxSubarraySumCircular(vector<int>& nums) {
              int n = nums.size(), pre = 0, ans = -1e9;
              // 情况一：单独的某一段，为答案
              for (int i = 0; i < n; ++i) {
                  pre = std::max(nums[i], pre + nums[i]);
                  ans = std::max(ans, pre);
              }
              // 预处理dp, dp[i]表示[0: i]范围内，前缀和的最大值
              int s = nums[0];
              vector<int> dp(n + 5, 0);
              dp[0] = nums[0];
              for (int i = 1; i < n; ++i) {
                  s += nums[i];
                  dp[i] = std::max(dp[i - 1], s);
              }
              // 情况二：开头的一段 + 末尾的一段，为答案
              s = 0;
              for (int i = n - 1; i >= 1; --i) {
                  s += nums[i];
                  ans = std::max(ans, dp[i - 1] + s);
              }
              return ans;
          }
      };
      ```

- 例题B_015：[删除一次得到子数组最大和](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/)

  - 题目描述

    ```
    给你一个整数数组，返回它的某个非空子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。
    ```

  - 题目样例

    ```
    输入：arr = [1,-2,0,3]
    输出：4
    解释：我们可以选出 [1, -2, 0, 3]，然后删掉 -2，这样得到 [1, 0, 3]，和最大。
    ```

  - 题目解析

    - 第一种比较直观的思路，相似的题[Remove One Element](https://codeforces.com/contest/1272/problem/D)

      - 枚举每个删除位置i, ans = max \{ 左边连续最大和($dp\_left[i - 1]$) + (删除位置i) + 右边连续最大和($dp\_right[i + 1]$) \}

      - 代码实现如下, 时间复杂度$O(N)$

        ```cpp
        class Solution {
        public:
            static const int N = 1e5 + 5, INF = 1e9;
            // dp_left[i]表示前i个元素[0:i]，以第i个位置结尾的，最大连续和
            // dp_right[i]表示后i个元素[i:n)，以第i个位置结尾的，最大连续和
            
            // 答案之一：左边连续最大和 + (删除位置) + 右边连续最大和
        
            int dp_left[N], dp_right[N];
            int maximumSum(vector<int>& arr) {
                if (arr.size() == 1) return arr[0];
                int n = arr.size(), ans = -INF;
                for (int i = 0; i < n; ++i)
                    dp_left[i] = std::max(arr[i], (i - 1 >= 0? dp_left[i - 1]: 0) + arr[i]);
        
                for (int i = n - 1; i >= 0; --i)
                    dp_right[i] = std::max(arr[i], dp_right[i + 1] + arr[i]);
                
                for (int i = 0; i < n; ++i) {
                    int L = i - 1 >= 0? dp_left[i - 1]: 0;
                    int R = dp_right[i + 1];
                    // 删除第i个位置的元素
                    ans = std::max({ans, L + R, (i != 0 ? L: -INF), (i != n - 1? R: -INF)});
                    // 不删除
                    ans = std::max({ans, dp_left[i], dp_right[i]});
                }
                return ans;
            }
        };
        ```

    - 第二种思路

      - 状态的定义

        - $f(i，0)表示考虑前i个元素[0:i]，以第i个位置结尾，恰好删除0个时，的最大值$
        - $f(i，1)表示考虑前i个元素[0:i]，以第i个位置结尾，恰好删除1个时，的最大值$

      - 状态的转移

        - $f(i，0) = max\{\ arr[i]，f(i - 1) + arr[i] \ \}$
        - $f(i，1) = max\{\ f(i - 1，1) + arr[i]，f(i，0) + 0，枚举第i个元素删还是不删\ \}$

      - 代码实现如下，由于$f(i，...)只与f(i - 1，...)有关，当然可以滚动数组优化$，时间复杂度$O(N)$

        ```cpp
        class Solution {
        public:
            // zero表示考虑前i个元素[0:i], 以第i个位置结尾，恰好删除0个时，的最大值
            // one表示考虑前i个元素[0:i], 以第i个位置结尾，恰好删除1个时，的最大值（值得注意的是虽然以i个元素结尾，但是第i个元素可能并没有被选）
        
            // 可能大家会习惯性定义，以第i个元素结尾，的最大值。在这个状态定义下，由于以i个元素结尾，看起来就是第i个元素必须取了。
            // 其实我们关心的是以第i个位置结尾时，向左连续的，最大值。而第i个位置上的元素取or删除，是我们的决策。
            // 所以以第i个位置结尾时定义状态就清晰多了
            int maximumSum(vector<int>& arr) {
                int n = arr.size(), zero = -1e9, one = -1e9, ans = -1e9;
                for (int i = 0; i < n; ++i) {
                    int new_zero = std::max(arr[i], zero + arr[i]);
                    int new_one = std::max(one + arr[i], zero + 0);
        
                    zero = std::move(new_zero);
                    one = std::move(new_one);
                    ans = std::max({ans, zero, one});
                }
                return ans;
            }
        };
        ```

- 例题B_016：[打家劫舍](https://leetcode.cn/problems/house-robber/)
- 例题B_017：[打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/)
- 例题B_018：[打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/)

##### 不要删这行