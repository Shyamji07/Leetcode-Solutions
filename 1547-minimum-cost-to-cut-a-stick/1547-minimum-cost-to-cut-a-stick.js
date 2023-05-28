/**
 * @param {number} n
 * @param {number[]} cuts
 * @return {number}
 */
var minCost = function(n, nums) {
    nums.push(0);
    nums.push(n);
    nums.sort((a, b) => a - b);
    const size = nums.length;
    const dp = Array.from({ length: size }, () => Array(size).fill(0));
    for (let d = 2; d < size; ++d) {
      for (let i = 0; i < size - d; ++i) {
        dp[i][i + d] = Infinity;
        for (let m = i + 1; m < i + d; ++m) {
          dp[i][i + d] = Math.min(dp[i][i + d], dp[i][m] + dp[m][i + d] + nums[i + d] - nums[i]);
        }
      }
    }
    return dp[0][size - 1];
};