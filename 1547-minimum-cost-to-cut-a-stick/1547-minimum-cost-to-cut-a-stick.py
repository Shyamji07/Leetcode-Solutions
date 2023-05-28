class Solution:
    def __init__(self):
        self.dp = [[0] * 101 for _ in range(101)]
    
    def solve(self, start, end, cuts, left, right):
        if left > right:
            return 0
        if self.dp[left][right]:
            return self.dp[left][right]

        cost = float('inf')
        for i in range(left, right + 1):
            left_cost = self.solve(start, cuts[i], cuts, left, i - 1)
            right_cost = self.solve(cuts[i], end, cuts, i + 1, right)

            cost = min(cost, end - start + left_cost + right_cost)
        
        self.dp[left][right] = cost
        return cost
    
    def minCost(self, n, cuts):
        cuts.sort()
        return self.solve(0, n, cuts, 0, len(cuts) - 1)
