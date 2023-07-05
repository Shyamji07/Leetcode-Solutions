class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        def lengths_of_one_intervals():
            i, n = 0, len(nums)
            while i < n:
                j = i
                while i < n and nums[i] == 1:
                    i += 1
                yield i - j
                i += 1  # Skip one zero

        max_length = max((a + b for a, b in pairwise(lengths_of_one_intervals())), default=-1)
        return max_length if max_length != -1 else len(nums) - 1
        