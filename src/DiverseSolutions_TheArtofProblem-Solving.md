<div align=center >
  <font face="黑体" size=7>LeetCode·一题多解·101</font>
</div>




##### 写在前面的话


- "根据一些小数据，观察出一些性质，然后合理运用已掌握的知识，尝试解题。" ------ 我的内功心法/心得
- 无人扶我青云志，我自踏雪至山巅。三十年河东，三十年河西，莫欺少年穷。

##### 题目精选

- 例题001：[盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)

  - 题目描述

    ```cpp
    给定一个长度为n的整数数组height。有n条垂线，第i条线的两个端点是(i, 0)和(i, height[i]) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。
    说明：你不能倾斜容器。
    ```

  - 题目样例

    <div align=center >
    <img alt="aa" src="../pics/container-with-most-water.jpg" style="zoom:0%"/>
    <p> 样例 </p>
    </div>

    ```cpp
    输入：[1,8,6,2,5,4,8,3,7]
    输出：49 
    解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
    ```

  - 题目解析 · 方法一

    - 观察到，组成最优方案的两条线中，其中一条的高度一定恰好为围成矩形的高。比如样例中围成的矩形第二条红色的线。这提示我们可以从左往右枚举，以第`i`个位置`height[i]`为矩形的右边界，然后寻找左边大于等于`height[i]`的最远的位置pos，这时围成的矩形面积就是`(i - pos) * height[i]`。

    - 当然上面是从左往右枚举的，我们还得从右往左枚举一遍，以第`i`个位置`height[i]`为矩形的左边界，然后寻找右边大于等于`height[i]`的最远的位置。

    - 最终的答案就是上面两种方式取最大值。

    - 我们考虑从左往右枚举`右边界i`，问题的难点就转换为如何求`左边大于等于height[i]的最远的位置pos`，注意这里是存在的概念，并不是从`i位置`往左一直(即连续)都是大于等于`height[i]`的，只要在其左边存在某个`位置j，height[j] >= height[i]`就行。你看看上图的样例也是如此。如果是找左右最近的小于/大于当前元素的数，就是单调栈的基本应用了，但是本题并不是。

    - 那么我们如何做呢？我们需要维护以下的一个数据结构。

      - 我们维护一个二维的有序集合`multiset<pair<int, int>>`，第一维存的是`height[i]`，第二维存的是目前遍历过的元素`height[j] >= height[i]`的最远的位置, 因为我们是从左往右，这里位置最远即下标最小的。

      - 当我们遍历到`位置i`，我们在有序集合里寻找首次大于等于`<height[i], -i>`的迭代器`it`，`it -> second`自然也就是左边存在的大于等于`height[i]`的最远的位置。

        - ```
          auto it = st.lower_bound({height[i], -i});
          ```

      - 接着我们还要考虑将`<height[i], ?>`插入有序集合里，我们发现这个插入并不影响有序集合里所有第一维小于`height[i]`的元素，而且这个`?`很容易被算出来，其实也就是`it->second`。

    - 代码实现如下，时间复杂度`O(NlogN)`

      ```cpp
      class Solution {
      public:
          int maxArea(vector<int>& height) {
              int n = height.size(), ans = 0;
              std::multiset<pair<int, int> > st;
              // 从左往右, height[i]作为右边界
              for (int i = 0; i < n; ++i) {
                  auto it = st.lower_bound({height[i], -i});
                  if (it == st.end()) {
                      st.insert({height[i], i});
                  }
                  else {
                      ans = std::max(ans, height[i] * (i - it->second));
                      st.insert({height[i], it->second});
                  }
              }
              st.clear();
              // 从右往左, height[i]作为左边界
              for (int i = n - 1; i >= 0; --i) {
                  auto it = st.lower_bound({height[i], -i});
                  if (it == st.end()) {
                      st.insert({height[i], i});
                  }
                  else {
                      ans = std::max(ans, height[i] * (it->second- i));
                      st.insert({height[i], it->second});
                  }
              }
              return ans;
          }
      };
      ```

  - 题目解析 · 方法二

    - 我们发现最优答案就是某两条边界构成，如果我们从<最左端，最右端>的两条边界开始往中间靠拢，是不是一定能找到最优方案？答案是可以的。

    - 当我们固定两个边界时`<L, R>`，我们假设`height[R] <= height[L]`，那么以`height[R]`为右边界，在`[L + 1, R]`内寻找左边界X，那么[X, R]构成的矩形面积一定小于[L, R]构成的矩形面积，所以在[L, R]内，以R为右边界的矩形的所有情况都考虑完了，所以我们移动R，也即我们每次移动高度小的一条边。

    - 代码实现如下，时间复杂度`O(N)`

      ```cpp
      class Solution {
      public:
          int maxArea(vector<int>& height) {
              int n = height.size();
              int L = 0, R = n - 1, ans = 0;
              while (L < R) {
                  ans = std::max(ans, std::min(height[L], height[R]) * (R - L));
                  if (height[L] < height[R]) L += 1;
                  else R -= 1;
              }
              return ans;
          }
      };
      ```

- 例题002：

- f