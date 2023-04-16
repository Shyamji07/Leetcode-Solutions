class Solution:
    def findColumnWidth(self, A: List[List[int]]) -> List[int]:
        return [max(len(str(a)) for a in r) for r in zip(*A)]
        