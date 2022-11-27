class Solution:
    def pivotInteger(self, n: int) -> int:
        total_sum = (1 + n) * n // 2
        for x in range(1, n+1):
            a = x * (1 + x) - x 
            if a == total_sum:
                return x
            if a > total_sum:
                return -1