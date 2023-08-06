class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        
        MOD = 10 ** 9 + 7
        
        # dp[i][j] denotes the solution of i songs with j different songs
        dp = [[0 for _ in range(n+1)] for _ in range(goal+1)]
        
        dp[0][0] = 1
        
        # corner case
        # dp[0][j]: the solution of 0 songs with j different songs, should be 0
        # dp[i][0]: the solution of i songs with 0 different songs (but here at least 1 different song), should be 0
        
        for i in range(1, goal+1):
            for j in range(1, n+1):
                
                # new
                dp[i][j] = dp[i-1][j-1] * (n - (j-1))
                
                # old
                # if k >= j, no way to add old songs. 
                # For example, 123, k = 3, we want to add an old song after 123. 
                # Can we add 1? No, since if we want to add 1, then 3 other songs (except song 1) must have been played.
                # But obviously, we only have 2 and 3, two songs can be chosen. This two even can not satisfy the requirement.
                # So there is no way to add old songs in this case. It is just 0.
                if j > k:
                    dp[i][j] += dp[i-1][j] * (j - k)
        
        return dp[goal][n] % MOD