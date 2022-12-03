class Solution:
    def frequencySort(self, s: str) -> str:
        counts = Counter(s)
        arr = [(counts[c],c) for c in counts.keys()]
        arr.sort(reverse=True)
        return ''.join([a[1]*a[0] for a in arr])