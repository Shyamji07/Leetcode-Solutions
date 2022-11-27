class Solution:
    def countSubarrays(self, p: List[int], m: int) -> int:
        c = dict()
        c[0] = 1
        flag = False
        cnt = 0
        res = 0
        n = len(p)
        for r in range(n):
            if (p[r] < m):
                cnt -= 1
            elif (p[r] > m):
                cnt += 1

            if (p[r] == m):
                flag = True

            if (flag):
                if(cnt in c.keys()):
                    res += c[cnt]
                if cnt-1 in c.keys():
                    res += c[cnt - 1]

            else:
                c[cnt] = c.get(cnt, 0) + 1

        return res