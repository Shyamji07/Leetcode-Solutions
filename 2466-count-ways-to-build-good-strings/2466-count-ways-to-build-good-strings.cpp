long long MOD  = 1000000007;
class Solution {
public:
   
    int countGoodStrings(int low, int high, int zero, int one) {
         vector<long long> dp(200005);
        dp[0] = 1;
        for(int i = 0; i < 100005; i++){
            dp[i + zero] %= MOD;
            dp[i + zero] += dp[i];
             dp[i + one] %= MOD;
           dp[i + one] += dp[i];
        }
        long long res = 0;
        for(int i = low; i <= high; i++){
            res = (res + dp[i])%MOD;
        }
        return res;
    }
};