class Solution {
public:
    int jump(vector<int>& nums) {
         if(nums.size()<=1)return 0;
        int ans=0;
       int cp=0;
        int mr=0;
        for(int i=0;i<nums.size()-1;i++){
            mr=max(mr,nums[i]+i);
            if(i==cp){
                cp=mr;
                ans++;
            }
        }
        return ans;
    }
};