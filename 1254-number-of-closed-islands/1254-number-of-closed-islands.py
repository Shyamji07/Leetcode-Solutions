class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        DIRS = [[-1,0],[1,0],[0,1],[0,-1]]

        def dfs(r, c):
            if not (0<=r<ROWS and 0<=c<COLS): return 1
            if grid[r][c]==1: return 0
            grid[r][c] = 1

            res = 0
            for dr, dc in DIRS:
                res += dfs(r+dr, c+dc)
            return res
        
        ans = 0
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c]==1: continue
                if dfs(r, c)==0: ans += 1
        return ans