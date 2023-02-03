class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows == 1):
            return s
        n = len(s)
        k = 1
        res = [""]*numRows
        down = True
        for i in range(n):
            res[k-1] += s[i]
            if(k == numRows):
                down = False
            elif(k == 1):
                down = True
                
            if(down):
                k+=1
            else:
                k-=1
        return "".join(res)