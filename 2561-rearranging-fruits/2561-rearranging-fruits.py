class Solution:
    def minCost(self, A: List[int], B: List[int]) -> int:
        count = Counter(A + B)
        for c in count:
            if count[c] % 2:
                return -1
            count[c] >>= 1
        A2 = list((Counter(A) - count).elements())
        B2 = list((Counter(B) - count).elements())
        small = min(count)
        C = sorted(A2 + B2)
        return sum(min(small * 2, C[i]) for i in range(len(A2)))
        