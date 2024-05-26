const int MOD = 1e9 + 7;
class Solution {
public:
    vector<vector<vector<int>>> memo;
    int sum = 0;
    int helper(int n, int absentCnt, int consecutiveLate){
        if( absentCnt >= 2 or consecutiveLate >=3)
            return 0;
        if(n == 0) return 1;
        if (memo[n][absentCnt][consecutiveLate] != -1) {
            return memo[n][absentCnt][consecutiveLate];
        }
        sum = helper(n - 1, absentCnt, 0) % MOD;
        sum = (sum + helper(n - 1, absentCnt + 1, 0) % MOD)%MOD;
        sum = (sum + helper(n - 1, absentCnt, consecutiveLate + 1) % MOD)%MOD;
        return memo[n][absentCnt][consecutiveLate] = sum;
    }
    int checkRecord(int n) {
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(n, 0, 0);
    }
};