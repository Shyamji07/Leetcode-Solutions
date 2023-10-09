class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int st=0;
        int ed=nums.size()-1;
        int ans = -1;
        while(st <= ed) {
            int mid = st + (ed-st)/2;
            if(target == nums[mid]) {
                ans = mid;
                ed=mid-1;
            }
            if(target < nums[mid]) {
                ed = mid-1;
            }
            else if(target > nums[mid]){
                st = mid+1;
            }
        }
        
        return ans;
    }
    int lastPos(vector<int>& nums, int target) {
        int st=0;
        int ed=nums.size()-1;
        int ans = -1;
        while(st <= ed) {
            int mid = st + (ed-st)/2;
            if(target == nums[mid]) {
                ans = mid;
                st =mid+1;
            }
            if(target < nums[mid]) {
                ed = mid-1;
            }
            else if(target > nums[mid]){
                st = mid+1;
            }
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n == 0) return {-1,-1};
        int first = firstPos(nums,target);
        int last = lastPos(nums,target);
        
        return {first,last};
    }
};
