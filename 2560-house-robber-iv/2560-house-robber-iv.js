var minCapability = function(nums, k) {
  let min = nums[0], max = nums[0];
  let n = nums.length;
  for (let i = 0; i < n; i++) {
    min = Math.min(min, nums[i]);
    max = Math.max(max, nums[i]);
  }
  let low = min, high = max;
  while (low < high) {
    let mid = Math.floor((low + high) / 2);
    if (isEnough(mid)) high = mid;
    else low = mid + 1;
  }
  return low;
  
  function isEnough(max) { 
    let houses = 0;
    for (let i = 0; i < n; i++) {
      if (nums[i] <= max) {
        houses++;
        i++;
      }
      if (houses === k) return true;
    }
    return false;
  }
};