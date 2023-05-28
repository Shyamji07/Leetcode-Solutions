class Solution(object):
    def removeTrailingZeros(self, num):
        """
        :type num: str
        :rtype: str
        """
        i = len(num) - 1
        while i >= 0 and num[i] == '0':
            i -= 1
        return num[0:i + 1]