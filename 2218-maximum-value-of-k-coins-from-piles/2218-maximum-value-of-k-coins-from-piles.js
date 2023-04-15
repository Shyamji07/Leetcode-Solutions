var maxValueOfCoins = function(piles, k) {
    const n = piles.length;
    const dp = Array(n + 1).fill().map(() => Array(k + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= k; j++) {
            let cur = 0;
            for (let x = 0; x < Math.min(j, piles[i-1].length); x++) {
                cur += piles[i-1][x];
                dp[i][j] = Math.max(dp[i][j], cur + dp[i-1][j-x-1]);
            }
            dp[i][j] = Math.max(dp[i][j], dp[i-1][j]);
        }
    }
    return dp[n][k];
};