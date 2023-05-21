class Solution:
    def punishmentNumber(self, n: int) -> int:
        def check(x):
            s = str(x * x)
            n = len(s)
            def dfs(i, tar):
                if tar < 0:
                    return False
                if i >= n and tar == 0:
                    return True
                for j in range(i, n):
                    if dfs(j+1, tar - int(s[i:j+1])):
                        return True
                return False
            
            return dfs(0, x)
        
        ans = 0
        for i in range(1, n+1):
            if check(i):
                ans += i * i
        return ans