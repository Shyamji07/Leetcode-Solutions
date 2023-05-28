class Solution:
    def minCost(self, n, nums):
        nums.append(0)
        nums.append(n)
        nums.sort()
        size = len(nums)
        dp = [[0] * size for _ in range(size)]
        for d in range(2, size):
            for i in range(size - d):
                dp[i][i + d] = float('inf')
                for m in range(i + 1, i + d):
                    dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + nums[i + d] - nums[i])
        return dp[0][size - 1]
