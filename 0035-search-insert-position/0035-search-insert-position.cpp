class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid, last=right;
        
        while( left <= right ){
            mid = left + (right-left)/2;
            if( nums[mid] == target )
                break;
            else if( target < nums[mid] ) 
                right = mid - 1;
            else if( target > nums[mid])
                left = mid + 1;
        }
        if( target > nums[mid] )
            mid++;
        return mid;
    }
};