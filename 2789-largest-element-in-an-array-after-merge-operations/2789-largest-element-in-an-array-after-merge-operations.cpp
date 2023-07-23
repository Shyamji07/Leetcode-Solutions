class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long suffixSum = 0, ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
		{
            if(nums[i] > suffixSum) 
			{
                suffixSum = 0;
            }
            suffixSum += nums[i];
            ans = max(ans, suffixSum);
        }
        return ans;
    }
};