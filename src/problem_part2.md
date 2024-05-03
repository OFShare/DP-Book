<div align=center >
  <font face="黑体" size=7>动态规划的思考艺术（第二卷题单）</font>
 </div>

##### 例题

- 这是【第二卷】的例题题单，方便大家直接练习。

- 在（A：我为人人递推法、或者叫刷表法）中，转移一般不叫转移方程，因为这只是一种更新方式；在（B：人人为我递推法，或者叫填表法）中，转移一般叫做转移方程。为了统一，全书都用状态的转移来描述，而不是单纯的叫状态的转移方程。

- A和B一般在（操作"可逆"或者比较容易寻找"可逆"关系）的时候，在实现上A和B都无太大区别。什么叫操作"可逆"，举个例子，从坐标$(x, y)$往下走一步到$(x + 1, y)$，那反过来，对于坐标$(x + 1, y)$就是向上走一步到坐标$(x, y)$，往下走和往上走就是可逆操作。

- 

- |                             题目                             |                           参考代码                           |                           简要说明                           |
  | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
  |   [爬楼梯](https://leetcode.cn/problems/climbing-stairs/)    | [climbing-stairs.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/climbing-stairs.cpp) | 介绍两种递推法（人人为我，我为人人），以及记忆化搜索，滚动数组优化技巧 |
  |     [数字三角形](https://www.luogu.com.cn/problem/P1216)     | [P1216.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1216.cpp) |          DAG模型，递推法，记忆化搜索，滚动数组优化           |
| [最长上升子序列 LIS](https://www.luogu.com.cn/problem/AT_chokudai_S001_h) | [AT_chokudai_S001_h.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/AT_chokudai_S001_h.cpp) | 掌握$O(N ^ 2)$的通用做法，以及$O(N * logN)$的二分做法，知晓还有$O(N * logN)$的树状数组优化做法 |
  | [最长公共子序列 LCS](https://www.luogu.com.cn/problem/P1439) | [P1439.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1439.cpp) | 掌握$O(N ^ 2)$的通用做法，知道排列的特殊做法$O(N * logN)$，以及$O(N^2 / W)$的位运算优化高级通用做法，知晓最长公共子串的后缀自动机 (SAM)做法，知晓将$LIS$和$LCS$合在一起的问题[LCIS](https://codeforces.com/problemset/problem/10/D)，方案数[Common Subsequence](https://www.luogu.com.cn/problem/AT_abc130_e) |
  |      [编辑距离](https://www.luogu.com.cn/problem/P2758)      | [P2758.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P2758.cpp) |                      时间复杂度$O(N^2)$                      |
  |   [斐波那契乘积](https://www.luogu.com.cn/problem/P10095)    | [P10095.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P10095.cpp) |               $<=1e18$的斐波那契数个数不到90个               |
  |      [四方定理](https://www.luogu.com.cn/problem/P1586)      |                             done                             |                     放在背包问题后。。。                     |
  |     [最大正方形](https://www.luogu.com.cn/problem/P1387)     | [P1387.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1387.cpp) | 不一样的题还有[最大子矩阵](https://leetcode.cn/problems/max-submatrix-lcci/)$O(N ^ 3)$，[P4147 玉蟾宫](https://www.luogu.com.cn/problem/P4147)$O(N ^ 2)$，[P3400 仓鼠窝](https://www.luogu.com.cn/problem/P3400)统计子矩阵的个数$O(N ^ 2)$ |
  |        [滑雪](https://www.luogu.com.cn/problem/P1434)        | [P1434.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1434.cpp) |        DAG模型，从某个状态出发（结束），能获得最优解         |
  |       [最长路](https://www.luogu.com.cn/problem/P1807)       | [P1807.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1807.cpp) |                           DAG模型                            |
  | [Backward Digit Sums](https://www.luogu.com.cn/problem/P1118) | [P1118.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1118.cpp) |                     杨辉三角，$dfs$剪枝                      |
  |       [吃奶酪](https://www.luogu.com.cn/problem/P1433)       | [P1433_1.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1433_1.cpp)，[P1433_2.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1433_2.cpp) |          $dfs$剪枝，状态压缩DP初步，原来如此简单？           |
  |      [取数游戏](https://www.luogu.com.cn/problem/P1123)      | [P1123.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/P1123.cpp) |            $dfs$搜索可过，你能改成状态压缩DP吗？             |
  |                                                              |                                                              |                                                              |
  | [最大子数组和](https://leetcode.cn/problems/maximum-subarray/) | [maximum-subarray.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-subarray.cpp) | 连续是一种很好的性质，$O(N)$的DP，可滚动数组优化，看着类似的题[Longest X](https://www.luogu.com.cn/problem/AT_abc229_d) |
  | [环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/) | [maximum-sum-circular-subarray.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-sum-circular-subarray.cpp) | 答案存在两种情况之一，相似的更难的题[环状最大两段子段和](https://www.luogu.com.cn/problem/P1121) |
  | [删除一次得到子数组最大和](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/) | [maximum-subarray-sum-with-one-deletion.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-subarray-sum-with-one-deletion.cpp) | 枚举删除位置，还可以直接DP（以第i个位置（not 元素）结尾）相似的题[Remove One Element](https://codeforces.com/contest/1272/problem/D) |
  |    [打家劫舍](https://leetcode.cn/problems/house-robber/)    | [house-robber.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/house-robber.cpp) |                       觉得简单起来了？                       |
  | [打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/) | [house-robber-ii.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/house-robber-ii.cpp) |                  增加一维状态，处理环的问题                  |
  | [打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/) | [house-robber-iii.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/house-robber-iii.cpp) | 从一维序列的情况，变成了在树上的情况，是不是依旧没太大区别？ |
  |                                                              |                                                              |                                                              |
  |    [不同路径](https://leetcode.cn/problems/unique-paths/)    | [unique-paths.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/unique-paths.cpp) | 由于只能向下或者向右移动，所以以坐标(x, y)为状态时构成天然的DAG图 |
  | [不同路径 II](https://leetcode.cn/problems/unique-paths-ii/) | [unique-paths-ii.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/unique-paths-ii.cpp) |                  构成DAG图，只是多了障碍点                   |
  | [不同路径 III](https://leetcode.cn/problems/unique-paths-iii/) | [unique-paths-iii.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/unique-paths-iii.cpp) | 由于可以上下左右移动，($A位置 \leftrightarrow B位置$)，以坐标(x, y)为状态时无法构成DAG图 |
  | [Minimizing the Sum](https://www.luogu.com.cn/problem/CF1969C) | [CF1969C_1.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/CF1969C_1.cpp)，[CF1969C_2.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/CF1969C_2.cpp)，[CF1969C_3.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/CF1969C_3.cpp) | 枚举最后一段or枚举接下来的一段（填表法/刷表法），简单DP优化  |
  | [矩阵中移动的最大次数](https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/) | [maximum-number-of-moves-in-a-grid.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/maximum-number-of-moves-in-a-grid.cpp) | 刷表法实现，你能改成填表法吗？[矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/)（相似的更难的题，难在哪儿？） |
  | [网格中的最小路径代价](https://leetcode.cn/problems/minimum-path-cost-in-a-grid/) | [minimum-path-cost-in-a-grid.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/minimum-path-cost-in-a-grid.cpp) |               本题刷表法的实现是不是非常自然？               |
  | [下降路径最小和](https://leetcode.cn/problems/minimum-falling-path-sum/) | [minimum-falling-path-sum.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/minimum-falling-path-sum.cpp) |                            刷表法                            |
  | [下降路径最小和 II](https://leetcode.cn/problems/minimum-falling-path-sum-ii/) | [minimum-falling-path-sum-ii_1.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/minimum-falling-path-sum-ii_1.cpp)，[minimum-falling-path-sum-ii_2.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/minimum-falling-path-sum-ii_2.cpp) |      刷表法$O(N ^ 3)$，填表法$O(N ^ 2)比较自然的DP优化$      |
  |                                                              |                                                              |                                                              |
  | [最大得分的路径数目](https://leetcode.cn/problems/number-of-paths-with-max-score/) | [number-of-paths-with-max-score.cpp](https://github.com/OFShare/DP-Book/blob/master/codes/number-of-paths-with-max-score.cpp) |          填表法记忆化实现，为何不太好用刷表法实现？          |
  | [矩阵中和能被 K 整除的路径](https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) |                                                              |                                                              |
  |   [地下城游戏](https://leetcode.cn/problems/dungeon-game/)   |                                                              |                                                              |
  |    [摘樱桃](https://leetcode.cn/problems/cherry-pickup/)     |                                                              |                                                              |
  | [摘樱桃 II](https://leetcode.cn/problems/cherry-pickup-ii/)  |                                                              |                                                              |
  | [网格图中递增路径的数目](https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/) |                                                              |                                                              |
  |                                                              |                                                              |                                                              |
  |                                                              |                                                              |                                                              |
  

##### 练习题

- 如下

- |                             题目                             | 参考代码 |
  | :----------------------------------------------------------: | :------: |
  | [任意子数组和的绝对值的最大值](https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/) |   done   |
  | [删除并获得点数](https://leetcode.cn/problems/delete-and-earn/) |   done   |
  | [乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/) |   done   |
  |                                                              |          |
  | [最小路径和](https://leetcode.cn/problems/minimum-path-sum/) |   done   |
  | [矩阵的最大非负积](https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/) |          |
  | [Sequence Decomposing](https://www.luogu.com.cn/problem/AT_abc134_e) |          |

