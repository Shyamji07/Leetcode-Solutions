class Solution:
    def canSplitArray(self, A: List[int], m: int) -> bool:
        return len(A) <= 2 or any(A[i] + A[i + 1] >= m for i in range(len(A) - 1))