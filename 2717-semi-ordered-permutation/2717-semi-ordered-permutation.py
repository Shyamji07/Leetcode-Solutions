class Solution:
    def semiOrderedPermutation(self, A: List[int]) -> int:
        n = len(A)
        i, j = A.index(1), A.index(n)
        return i + n - 1 - j - (i > j)
        