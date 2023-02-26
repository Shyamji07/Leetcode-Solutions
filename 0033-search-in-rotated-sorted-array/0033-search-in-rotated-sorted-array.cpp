class Solution {
public:
    int search(vector<int>& nums, int target) {
        //using binary sreach 
        int low = 0;
        int high = nums.size()-1;
           
        while(low <= high){
            int mid = (low+high) /2;
            if(nums[mid] == target){
                return mid;
            }else if (nums[low] <= nums[mid]){
                // means nums at lo to mid is sorted
                if(target>= nums[low] && target < nums[mid]){ //check in the sorted array and is btw range lo to mid
                    high = mid-1;
                }else{
                    //check in the unsorted part
                    low = mid+1;
                }
            }else if(nums[mid]< nums[high]){
                //means nums at mid to high is sorted
                if(nums[mid] < target && nums[high] >= target){
                    low = mid+1;
                }else{
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};