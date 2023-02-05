class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        n = len(words)
        v = [0] * (n + 1)
        vowel = 'aeiou'
        ans = []
        for i in range(n):
            v[i + 1] = v[i] + (1 if words[i][0] in vowel and words[i][-1] in vowel else 0)
        for l, r in queries:
            ans.append(v[r + 1] - v[l])
        return ans