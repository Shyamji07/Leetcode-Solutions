# class Solution:
#     def validPartition(self, nums: List[int]) -> bool:
#         n = len(nums)
#         memo = {-1: True}

#         # Determine if the prefix array nums[0 ~ i] has a valid partition
#         def prefixIsValid(i):
#             if i in memo:
#                 return memo[i]
#             ans = False

#             # Check 3 possibilities
#             if i > 0 and nums[i] == nums[i - 1]:
#                 ans |= prefixIsValid(i - 2)
#             if i > 1 and nums[i] == nums[i - 1] == nums[i - 2]:
#                 ans |= prefixIsValid(i - 3)
#             if i > 1 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
#                 ans |= prefixIsValid(i - 3)
#             memo[i] = ans
#             return ans

#         return prefixIsValid(n - 1)



class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [True] + [False] * n

        # Determine if the prefix array nums[0 ~ i] has a valid partition
        for i in range(n):
            dp_index = i + 1

            # Check 3 possibilities
            if i > 0 and nums[i] == nums[i - 1]:
                dp[dp_index] |= dp[dp_index - 2]
            if i > 1 and nums[i] == nums[i - 1] == nums[i - 2]:
                dp[dp_index] |= dp[dp_index - 3]
            if i > 1 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
                dp[dp_index] |= dp[dp_index - 3]
 
        return dp[n]