// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n=s.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         // int dp[n+1][n+1];
//       string t=s;
//         reverse(t.begin(),t.end());
//         for(int i=0;i<=n;i++){
//             dp[i][0]=0;
//             dp[0][i]=0;
//         }
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 if(s[i-1]==t[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[n][n];
//     }
// };



class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n), dpPrev(n);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[j] = dpPrev[j - 1] + 2;
                } else {
                    dp[j] = max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp;
        }

        return dp[n - 1];
    }
};