class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int low = 0, high = nums.size()-2; 
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
			// If we are on left side, move right
            if(nums[mid] == nums[mid^1]) low = mid+1;
			// if we are on right side, move left
            else high = mid-1;
        }
        
        return nums[low];
    }
};