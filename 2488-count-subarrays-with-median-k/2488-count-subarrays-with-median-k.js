var countSubarrays = function(nums, k) {
  let n = nums.length, kIndex = nums.indexOf(k);
  let map = new Map(), leftBalance = 0;
  map.set(0, 1);
  for (let i = kIndex - 1; i >= 0; i--) {
    leftBalance += nums[i] > k ? 1 : -1;
    map.set(leftBalance, (map.get(leftBalance) || 0) + 1);
  }
  
  let rightBalance = 0, ans = 0;
  for (let j = kIndex; j < n; j++) {
    if (nums[j] !== k) rightBalance += nums[j] > k ? 1 : -1;
    let oddComplement = -rightBalance; // k = mid
    let evenComplement = -rightBalance + 1; // k = lower mid
    ans += (map.get(oddComplement) || 0);
    ans += (map.get(evenComplement) || 0);
  }
  return ans;
};