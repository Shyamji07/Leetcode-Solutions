class Solution {
public:
      long long maxTaxiEarnings(int n, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<long long> dp(n+1);
        int j = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i], dp[i - 1]);
            while (j < arr.size() && arr[j][0] == i)
                dp[arr[j++][1]] = max(dp[arr[j][1]], dp[i] + arr[j][1] - arr[j][0] + arr[j][2]);
        }
        return dp[n];
    }
};