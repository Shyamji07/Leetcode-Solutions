class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        dp = Counter({0: 1})
        res = pre = 0
        for a in nums:
            pre ^= a
            res += dp[pre]
            dp[pre] += 1
        return res
        