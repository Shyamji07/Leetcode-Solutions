class Solution {
public:
  bool validPartition(vector<int>& A) {
        int n = A.size(), dp[4] = {0, 0, 0, 1};
        for (int i = 0; i < n; ++i) {
            dp[i % 4] = 0;
            if (i - 1 >= 0 && A[i] == A[i - 1])
                dp[i % 4] |= dp[(i + 2) % 4];
            if (i - 2 >= 0 && A[i] == A[i - 1] && A[i - 1] == A[i - 2])
                dp[i % 4] |= dp[(i + 1) % 4];
            if (i - 2 >= 0 && A[i] - 1 == A[i - 1] && A[i - 1] == A[i - 2] + 1)
                dp[i % 4] |= dp[(i + 1) % 4];
        }
        return dp[(n - 1) % 4];
    }
};