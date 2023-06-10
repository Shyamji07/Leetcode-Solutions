var matrixSumQueries = function(n, queries) {
  const seen = [new Set(), new Set()];
  let ans = 0;

  for (let i = queries.length-1; i >= 0; i--) {
    const [type, index, val] = queries[i];
    if (!seen[type].has(index)) {
      seen[type].add(index);
      ans += (n-seen[1-type].size) * val;
    }
  }
  
  return ans;
};