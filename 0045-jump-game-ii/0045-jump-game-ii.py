
class Solution:
    def jump(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        cp, mr = 0, 0
        
        for i in range(n - 1):
            mr = max(mr, i + nums[i])
            if i == cp:
                ans += 1
                cp = mr
        return ans