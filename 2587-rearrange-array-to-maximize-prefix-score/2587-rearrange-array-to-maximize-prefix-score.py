class Solution:
    def maxScore(self, arr: List[int]) -> int:
        return sum(n > 0 for n in accumulate(sorted(arr, reverse=True)))