/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverageDifference = function(nums) {
       let ans=0,sum=0;
       let mini=Infinity;
       let n=nums.length;
       let curr=0;
        for(let i=0;i<n;i++)sum+=nums[i];
        for(let i=0;i<n-1;i++){
           let temp=(Math.abs((parseInt)((nums[i]+curr)/(i+1))-(parseInt)((sum-nums[i]-curr)/(n-i-1))));
            if(temp<mini)mini=temp,ans=i;
            curr+=nums[i];
        }
        let temp=(parseInt)(sum/n);
        if(temp<mini)mini=temp,ans=n-1;
        return ans;
};