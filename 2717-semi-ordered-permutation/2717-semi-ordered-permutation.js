var semiOrderedPermutation = function(nums) {
    const n = nums.length;
    let fi = -1, li = -1;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) {
            fi = i;
        } else if (nums[i] === n) {
            li = i;
        }
    }
    let ans = fi - 0 + n - 1 - li;
    if (li < fi) {
        ans--;
    }
    return ans;
};