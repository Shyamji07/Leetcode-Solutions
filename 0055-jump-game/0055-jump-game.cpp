class Solution {
public:
    bool canJump(vector<int>& nums) {
       int max_reach=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i>max_reach)return false;
            max_reach=max(max_reach,i+nums[i]);
        }
        return max_reach>=nums.size()-1;
    }
};