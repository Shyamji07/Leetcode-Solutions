class Solution:
    def maxIncreasingCells(self, mat: List[List[int]]) -> int:
        dic = defaultdict(list)
        m = len(mat)
        n = len(mat[0])
        
        for row in range(m):
            for col in range(n):
                dic[mat[row][col]].append((row, col))
        
        rows = [0] * m
        cols = [0] * n
        
        for _, arr in sorted(dic.items()):
            curr = []
            for r, c in arr:
                curr.append(1 + max(rows[r], cols[c]))
            
            for i in range(len(arr)):
                r, c = arr[i]
                x = curr[i]
                rows[r] = max(rows[r], x)
                cols[c] = max(cols[c], x)
            
        return max(rows + cols)