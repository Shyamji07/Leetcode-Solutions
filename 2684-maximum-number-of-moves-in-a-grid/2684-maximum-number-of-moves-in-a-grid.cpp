class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> dp(2, vector<int>(m));
        for (int c = n - 2; c >= 0; --c)
            for (int r = 0; r < m; ++r) {
                int c0 = c % 2, c1 = (c + 1) % 2;
                dp[c0][r] = g[r][c + 1] > g[r][c] ? 1 + dp[c1][r] : 0;
                if (r > 0 && g[r - 1][c + 1] > g[r][c])
                    dp[c0][r] = max(dp[c0][r], 1 + dp[c1][r - 1]);
                if (r + 1 < m && g[r + 1][c + 1] > g[r][c])
                    dp[c0][r] = max(dp[c0][r], 1 + dp[c1][r + 1]);
            }
        return *max_element(begin(dp[0]), end(dp[0]));
    }
};