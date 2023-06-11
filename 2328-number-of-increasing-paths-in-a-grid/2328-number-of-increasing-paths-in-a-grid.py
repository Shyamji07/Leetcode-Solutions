MOD = int(1e9 + 7)
dirs = [0, 1, 0, -1, 0]

class Solution:
    def __init__(self):
        self.memo = []

    def helper(self, grid, i, j):
        result = 1  # Contribution of current cell as an increasing sequence.
        if self.memo[i][j] != -1:  # Return the cached results if they exist.
            return self.memo[i][j]
        for d in range(4):  # Check all 4 directions.
            x = i + dirs[d]
            y = j + dirs[d + 1]
            if (
                x >= 0
                and y >= 0
                and x < len(grid)
                and y < len(grid[0])
                and grid[x][y] > grid[i][j]
            ):
                result = (result + self.helper(grid, x, y)) % MOD  # Add the total number of cells in the longest path for all directions.
        self.memo[i][j] = result
        return result

    def countPaths(self, grid):
        result = 0
        self.memo = [[-1] * len(grid[0]) for _ in range(len(grid))]
        for i in range(len(grid)):  # For each cell as a starting point calculate the number of increasing paths it can contribute.
            for j in range(len(grid[0])):
                result = (result + self.helper(grid, i, j)) % MOD
        return result
