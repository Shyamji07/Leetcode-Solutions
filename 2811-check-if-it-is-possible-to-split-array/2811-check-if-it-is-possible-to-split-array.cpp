class Solution {
public:
    bool canSplitArray(vector<int>& A, int m) {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A[i] + A[i + 1] >= m)
                return true;
        return A.size() < 3;
    }
};