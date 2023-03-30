var isScramble = function (s1, s2) {
  const totalLength = s1.length;

  // Initialize a 3D array to store the intermediate results
  const canScramble = new Array(totalLength + 1)
    .fill(null)
    .map(() =>
      new Array(totalLength)
        .fill(null)
        .map(() => new Array(totalLength).fill(false))
    );

  // Initialize the base case where the two strings have length 1
  for (let i = 0; i < totalLength; i++) {
    for (let j = 0; j < totalLength; j++) {
      canScramble[1][i][j] = s1[i] === s2[j];
    }
  }

  // Solve the subproblems in a bottom-up manner
  for (let len = 2; len <= totalLength; len++) {
    for (let i = 0; i <= totalLength - len; i++) {
      for (let j = 0; j <= totalLength - len; j++) {
        for (let k = 1; k < len; k++) {
          // Partition s1[0,len] into two parts: s1[0,k] and s1[k,len]
          // Check if s1[0,k] can be scrambled to get s2[0,k]
          const canScrambleLeft = canScramble[k][i][j];
          // Check if s1[k,n] can be scrambled to get s2[k,n]
          const canScrambleRight = canScramble[len - k][i + k][j + k];
          // Check if s1[0,k] can be scrambled to get s2[len-k,n]
          const canScrambleLeftReverse = canScramble[k][i][j + len - k];
          // Check if s1[k,n] can be scrambled to get s2[0,len-k]
          const canScrambleRightReverse = canScramble[len - k][i + k][j];

          // Check if s1[0,k] can be scrambled to get s2[0,k] and s1[k,n] can be scrambled to get s2[k,n]
          // OR if s1[0,k] can be scrambled to get s2[len-k,n] and s1[k,n] can be scrambled to get s2[0,len-k]
          if (
            (canScrambleLeft && canScrambleRight) ||
            (canScrambleLeftReverse && canScrambleRightReverse)
          ) {
            // If either case is true, s1[0,len] can be scrambled to get s2[0,len]
            canScramble[len][i][j] = true;
            break;
          }
        }
      }
    }
  }

  // The answer is stored in canScramble[n][0][0]
  return canScramble[totalLength][0][0];
};