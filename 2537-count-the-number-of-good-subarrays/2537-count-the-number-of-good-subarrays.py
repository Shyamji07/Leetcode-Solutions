class Solution:
    def countGood(self, arr: List[int], k: int) -> int:
        res = cur = i = 0
        freq = Counter()
        for j in range(len(arr)):
            k -= freq[arr[j]]
            freq[arr[j]] += 1
            while k <= 0:
                freq[arr[i]] -= 1
                k += freq[arr[i]]
                i += 1
            res += i
        return res
        