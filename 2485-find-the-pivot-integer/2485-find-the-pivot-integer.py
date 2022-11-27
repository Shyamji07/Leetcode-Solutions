class Solution:
    def pivotInteger(self, n):
        x = sqrt(n * (n + 1) // 2)
        return -1 if x % 1 else int(x)


# class Solution:
#     def pivotInteger(self, n: int) -> int:
#         total_sum = (1 + n) * n // 2
#         for x in range(1, n+1):
#             a = x * (1 + x) - x 
#             if a == total_sum:
#                 return x
#             if a > total_sum:
#                 return -1


