/**
 * @param {number[]} nums
 * @return {number}
 */
var longestArithSeqLength = function(nums) {
    const n = nums.length;
    if (n <= 2)
      return n;
    let longest = 2;
    const dp = new Array(n);

    for (let i = 0; i < n; i++) {
      dp[i] = new Map();
      for (let j = 0; j < i; j++) {
        const diff = nums[i] - nums[j];
        dp[i].set(diff, dp[j].has(diff) ? dp[j].get(diff) + 1 : 2);
        longest = Math.max(longest, dp[i].get(diff));
      }
    }

    return longest;
};