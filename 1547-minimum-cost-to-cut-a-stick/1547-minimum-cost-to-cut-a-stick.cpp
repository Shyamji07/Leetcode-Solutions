class Solution {
public:
    int minCost(int n, vector<int>& nums) {
        nums.push_back(0);
        nums.push_back(n);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size));
        for (int d = 2; d < size; ++d) {
            for (int i = 0; i < size - d; ++i) {
                dp[i][i + d] = 1e9;
                for (int m = i + 1; m < i + d; ++m) {
                    dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + nums[i + d] - nums[i]);
                }
            }
        }
        return dp[0][size - 1];
    }
};
