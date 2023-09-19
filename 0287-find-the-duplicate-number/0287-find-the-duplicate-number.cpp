class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ind,n=nums.size()-1;
        vector<int> count(n+1,0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(count[i]>1) return i;
        }
        return -1;
    }
};