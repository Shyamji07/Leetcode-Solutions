class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int prev){
        if(r < 0 || r == grid.size() || c == grid[0].size() || prev >= grid[r][c] ) return 0;
        prev = grid[r][c];
        grid[r][c] = INT_MAX;
        int res = dfs(grid, r-1, c+1, prev);
        res = max(res, dfs(grid, r, c+1, prev ));
        res = max(res, dfs(grid, r+1, c+1, prev));
        return res + 1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) ans = max(ans, dfs(grid, i, 0, 0));
        return ans-1;
    }
};

// class Solution {
// public:
//     int maxMoves(vector<vector<int>>& g) {
//         int m = g.size(), n = g[0].size();
//         vector<vector<int>> dp(2, vector<int>(m));
//         for (int c = n - 2; c >= 0; --c)
//             for (int r = 0; r < m; ++r) {
//                 int c0 = c % 2, c1 = (c + 1) % 2;
//                 dp[c0][r] = g[r][c + 1] > g[r][c] ? 1 + dp[c1][r] : 0;
//                 if (r > 0 && g[r - 1][c + 1] > g[r][c])
//                     dp[c0][r] = max(dp[c0][r], 1 + dp[c1][r - 1]);
//                 if (r + 1 < m && g[r + 1][c + 1] > g[r][c])
//                     dp[c0][r] = max(dp[c0][r], 1 + dp[c1][r + 1]);
//             }
//         return *max_element(begin(dp[0]), end(dp[0]));
//     }
// };