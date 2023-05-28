/**
 * @param {number[]} piles
 * @return {number}
 */
var stoneGameII = function(A) {
    const N = A.length;
    for (let i = N - 2; i >= 0; i--) {
      A[i] += A[i + 1];
    }
    const cache = new Map();
    const dp = (i, m) => {
      if (i + 2 * m >= N) return A[i];
      if (cache.has(`${i},${m}`)) return cache.get(`${i},${m}`);
      let minStones = Infinity;
      for (let x = 1; x <= 2 * m; x++) {
        minStones = Math.min(minStones, dp(i + x, Math.max(m, x)));
      }
      const result = A[i] - minStones;
      cache.set(`${i},${m}`, result);
      return result;
    };
    return dp(0, 1);
};