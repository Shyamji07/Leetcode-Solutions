class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        tmp = set(dictionary)
        n = len(s)
        dp = [inf] * (n + 1)
        dp[0] = 0
        for i in range(n):
            dp[i+1] = min(dp[i] + 1, dp[i+1])
            for j in range(i, n):
                if s[i:j+1] in tmp:
                    dp[j+1] = min(dp[j+1], dp[i])
        return dp[-1]