class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        comb = sorted(zip(ages, scores))
        dp = [p[1] for p in comb]
        for i, (_, score) in enumerate(comb):
            for j in [j for j in range(i) if comb[j][1] <= score]:
                dp[i] = max(dp[i], dp[j] + score)
        return max(dp)