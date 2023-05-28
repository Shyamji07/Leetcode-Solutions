class Solution:
    def differenceOfDistinctValues(self, grid):
        ans = [[0] * len(grid[0]) for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                a = set()
                b = set()
                for k in range(1, min(i + 1, j + 1)):
                    a.add(grid[i - k][j - k])
                for k in range(1, min(len(grid) - i, len(grid[0]) - j)):
                    b.add(grid[i + k][j + k])
                ans[i][j] = abs(len(a) - len(b))
        return ans
