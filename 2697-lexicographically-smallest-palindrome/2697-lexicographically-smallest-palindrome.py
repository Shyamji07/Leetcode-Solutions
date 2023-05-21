class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        return ''.join(map(min, zip(s, s[::-1])))
        