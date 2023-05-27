/**
 * @param {number[]} nums
 * @return {number}
 */
var maxStrength = function(nums) {
    const size = nums.length;

    if (size === 1) {
      return nums[0];
    }

    let negativeCount = 0;
    let maxNegative = Number.MIN_SAFE_INTEGER;
    let positiveCount = 0;
    let answer = 1;
    let zeroCount = 0;

    for (const num of nums) {
      if (num === 0) {
        zeroCount++;
        continue;
      }
      if (num < 0) {
        negativeCount++;
        maxNegative = Math.max(maxNegative, num);
      } else {
        positiveCount++;
      }
      answer *= Math.abs(num);
    }

    if (zeroCount === size) return 0;
    if (negativeCount + zeroCount === size && negativeCount === 1) return 0;
    if (negativeCount % 2 === 0) return answer;
    else return answer / Math.abs(maxNegative);
  }


