class Solution:
    def onesMinusZeros(self, arr: List[List[int]]) -> List[List[int]]:
        R, C = len(arr), len(arr[0])
        row, col = [0] * R, [0] * C
        for r in range(R):
            for c in range(C):
                offset = 2 * arr[r][c] - 1 
                row[r] += offset
                col[c] += offset
        return [[row[r] + col[c] for c in range(C)] for r in range(R)]
