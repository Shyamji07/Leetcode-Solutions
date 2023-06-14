class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,100000000));
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(coins[j-1]>i)
                    dp[j][i]=dp[j-1][i];
                else
                    dp[j][i]=min(dp[j-1][i],min(dp[j-1][i-coins[j-1]],dp[j][i-coins[j-1]])+1);
            }
        }
        return (dp[n][amount]==100000000?-1:dp[n][amount]);
    }
    
};


// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) { //amount outer loop
//     vector<int> need(amount+1, amount+1);
//     need[0] = 0;
//     for (int a=1; a<=amount; a++)
//         for (int c : coins)
//             if (c <= a)
//                 need[a] = min(need[a], need[a-c] + 1);
//     return need.back() > amount ? -1 : need.back();
// }
//     int coinChange(vector<int>& coins, int amount) {
//     vector<int> need(amount+1, amount+1);
//     need[0] = 0;
//     for (int c : coins)
//         for (int a=c; a<=amount; a++)
//             need[a] = min(need[a], need[a-c] + 1);
//     return need.back() > amount ? -1 : need.back();
// }


   