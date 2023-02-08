/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    if(nums.length<=1)return 0;
        var ans=0;
       var cp=0;
        var mr=0;
        for(let i=0;i<nums.length-1;i++){
            mr=Math.max(mr,nums[i]+i);
            if(i==cp){
                cp=mr;
                ans++;
            }
        }
        return ans;
};