class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        s="aeiou"
        return sum(w[0] in s and w[-1] in s for w in words[left:right+1])