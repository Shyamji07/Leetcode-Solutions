class Solution {
public:
    bool canJump(vector<int>& nums) {
       if(nums.size()<=1)return true;
        if(nums[0]==0)return false;
       
          int currpos=0;
       int max_reach=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i>max_reach)return false;
            max_reach=max(max_reach,i+nums[i]);
        }
        return max_reach>=nums.size()-1;
    }
};