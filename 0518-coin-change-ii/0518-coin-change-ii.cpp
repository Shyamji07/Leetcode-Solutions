class Solution { // using 2D DP
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<n+1;i++)dp[i][0] = 1;
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<amount+1;j++)  {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];          // exclude
                } else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];  //exclude + include
                }
            }
        }
        return dp[n][amount];
        
    }
};



/*  Using 1D DP
class Solution {
public:
    int change(int sum, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(sum+1,0);
        dp[0]=1;
            for(int j=0;j<n;j++)
                for(int i=arr[j];i<=sum;i++)
                  dp[i]=dp[i]+dp[i-arr[j]];   // before updating dp[i] is working as previous state
        return dp[sum];
    }
};
*/