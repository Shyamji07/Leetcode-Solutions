class Solution(object):
    def minimumCost(self, s):
        """
        :type s: str
        :rtype: int
        """
        a = 0
        for i in range(1, len(s)):
            a += 0 if s[i - 1] == s[i] else min(i, len(s) - i)
        return a