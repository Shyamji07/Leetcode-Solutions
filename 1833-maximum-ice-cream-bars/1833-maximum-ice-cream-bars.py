class Solution:
   def maxIceCream(self, A, coins):
        A.sort()
        for i, a in enumerate(A):
            coins -= a
            if coins < 0:
                return i
        return len(A)
        