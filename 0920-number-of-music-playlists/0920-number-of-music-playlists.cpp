class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod = (int)1e9 + 7;
        long dp[L+1][N+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= L; i++){
            for (int j = 1; j <= N; j++){
                dp[i][j] = (dp[i-1][j-1] * (N - (j-1)))%mod; 
                if (j > K){
                    dp[i][j] = (dp[i][j] + (dp[i-1][j] * (j-K))%mod)%mod;
                }
            }
        }
        return (int)dp[L][N];
    }
};