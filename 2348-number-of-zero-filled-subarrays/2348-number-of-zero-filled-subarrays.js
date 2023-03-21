/**
 * @param {number[]} nums
 * @return {number}
 */
var zeroFilledSubarray = function(nums) {
        let ans=0,c=0;
        
        for(let i=0;i<nums.length;i++){
            if(nums[i]==0){
                c++;
            }
            else{
                ans+=(c*(c+1))/2;
                c=0;
            }
        }
        ans+=(c*(c+1))/2;
        return ans;

};