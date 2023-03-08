/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
        dp = Array(n+1).fill(0)
        dp[0] = dp[1] = 1;
        for(let i = 2; i <= n; i++) {
            let l=0,r=i-1;
            while(l<=i-1){
                dp[i]+=dp[l]*dp[r];
                l++;
                r--;
            }
        }
           
        return dp[n];
};