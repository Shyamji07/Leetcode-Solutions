class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        curr = [0] * (len(nums)+1)
        summ = sum(nums)

        for i in range(1, len(curr)):
            curr[i] = curr[i-1] + nums[i-1]

        ans = (-1, float('inf'))
        for i in range(1,len(curr)):
            left = curr[i] // i
            right = (summ-curr[i]) // (len(nums)-i) if (len(nums)-i) != 0 else 0
            diff = abs(left-right)
            if diff < ans[1]:
                ans = (i-1, diff)

        return ans[0]