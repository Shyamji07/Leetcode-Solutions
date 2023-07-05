var longestSubarray = function(nums) {
  let notDeletedState = 0;
  let deletedState = 0;
  let max = 0;
    
  for (const num of nums) {
    if (num == 0) {
      deletedState = notDeletedState;
      notDeletedState = 0;
    } else {
      notDeletedState++;  
      deletedState++;
    }
      
    max = Math.max(deletedState, max);
  }

  // Max can be the number of elements in this case but we have to delete one element
  // e.g. nums = [1, 1, 1]
  return max == nums.length ? max - 1 : max;
};