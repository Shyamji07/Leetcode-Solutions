class Solution:
    def letterCasePermutation(self, S):
        L = [set([i.lower(), i.upper()]) for i in S]
        return map(''.join, itertools.product(*L))