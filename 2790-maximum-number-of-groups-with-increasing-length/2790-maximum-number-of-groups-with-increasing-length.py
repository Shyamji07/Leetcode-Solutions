class Solution:
    def maxIncreasingGroups(self, usageLimits: List[int]) -> int:
        m = 0
        for n in accumulate(sorted(usageLimits)):
            if n >= (m + 1) * (m + 2) // 2:
                m += 1
        return m