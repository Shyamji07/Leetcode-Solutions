/**
 * @param {number} n
 * @param {number} k
 * @param {number} maxPts
 * @return {number}
 */
var new21Game = function(N, K, W) {
    if (K == 0 || N >= K + W) return 1.0;
        let dp = new Array(N+1); 
        dp[0] = 1.0;
        let Wsum = 1.0, res = 0.0;
        for (let i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K) Wsum += dp[i]; else res += dp[i];
            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
};