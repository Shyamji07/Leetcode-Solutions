import numpy as np

class Solution:
    def halvesAreAlike(self, s, vwls=set(list("aeiouAEIOU"))):
        cnt = 0
        for i,c in enumerate(s):                 
            if c in vwls:                       
                cnt += np.sign(len(s) - 2*i-1)   
        return cnt == 0                      