class Solution:
    def minEatingSpeed(self, piles, H):
        low, right = 1, max(piles)
        while low < right:
            mid = (low + right) / 2
            if sum((h + mid - 1) / mid for h in piles) > H:
                low = mid + 1
            else:
                right = mid
        return low