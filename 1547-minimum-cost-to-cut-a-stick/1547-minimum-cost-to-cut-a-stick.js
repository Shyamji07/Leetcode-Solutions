/**
 * @param {number} n
 * @param {number[]} cuts
 * @return {number}
 */
var minCost = function(n, cuts) {
    cuts.sort((a, b) => a - b);
    const dp = Array.from({ length: 101 }, () => Array(101).fill(0));
    
    const solve = (start, end, cuts, left, right) => {
      if (left > right) return 0;
      if (dp[left][right]) return dp[left][right];

      let cost = Infinity;
      for (let i = left; i <= right; i++) {
        const left_cost = solve(start, cuts[i], cuts, left, i - 1);
        const right_cost = solve(cuts[i], end, cuts, i + 1, right);

        cost = Math.min(cost, end - start + left_cost + right_cost);
      }
      return dp[left][right] = cost;
    };
    
    return solve(0, n, cuts, 0, cuts.length - 1);

};