class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), l = -1, mid = -1, r = 0, maxLen = 0;

        while(r < n) {
            while(r < n && nums[r]) r++;
            maxLen = l > -1 ? max(maxLen, r - l - 2) 
                            : max(0, r - 1);
            l = mid;
            mid = r;
            r++;
        }
        return maxLen;
    }
};