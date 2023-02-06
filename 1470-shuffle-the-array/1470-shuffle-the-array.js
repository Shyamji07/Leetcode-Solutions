var shuffle = function(nums, n) {
    let res = []

    for(let i =0; i<nums.length/2;i++){
        res.push(nums[i],nums[i+n])
    }

    return res;
};