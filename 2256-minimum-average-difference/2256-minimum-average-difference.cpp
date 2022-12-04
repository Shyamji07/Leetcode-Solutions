#define ll long long int 
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       ll ans=0, sum=0, mini=INT_MAX, n=nums.size(), curr=0;
        sum=accumulate(begin(nums),end(nums),0ll);
        for(int i=0;i<n-1;i++){
           long long  int temp=round(abs(((nums[i]+curr)/(i+1))-((sum-nums[i]-curr)/(n-i-1))));
            if(temp<mini)mini=temp,ans=i;
            curr+=nums[i];
        }
       ll temp=round(sum/n);
        if(temp<mini)mini=temp,ans=n-1;
        return ans;
    }
};