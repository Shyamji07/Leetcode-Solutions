class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        m = {c: i for i, c in enumerate(order)}
        l = [[m[c] for c in w] for w in words]
        return not any(x > y for (x, y) in zip(l, l[1:]))