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