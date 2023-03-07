class Solution:
    def minimumTime(self, arr: List[int], k: int) -> int:
        left = 0
        right = k * min(arr)
        while left < right:
            mid = (left + right) // 2
            if sum((mid // x for x in arr)) >= k:
                right = mid
            else:
                left = mid + 1
        
        return left