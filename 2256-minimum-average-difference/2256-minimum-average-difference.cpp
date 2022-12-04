class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       long long int ans=0,sum=0;
        long long int mini=INT_MAX;
       long long  int n=nums.size();
       long long  int curr=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        for(int i=0;i<n-1;i++){
           long long  int temp=round(abs(((nums[i]+curr)/(i+1))-((sum-nums[i]-curr)/(n-i-1))));
            if(temp<mini)mini=temp,ans=i;
            curr+=nums[i];
        }
       long long  int temp=round(sum/n);
        if(temp<mini)mini=temp,ans=n-1;
        return ans;
    }
};