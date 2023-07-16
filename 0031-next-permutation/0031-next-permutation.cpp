class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,i;
        for( k=n-2;k>=0;k--){
            if(nums[k+1]>nums[k])break;
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for( i=n-1;i>k;i--){
                if(nums[i]>nums[k]){
              swap(nums[k],nums[i]);
                    break;
            } 
            }
            sort(nums.begin()+k+1,nums.end());
        }
    }
};

// class Solution {
// public:
//     void nextPermutation(vector<int>& n) {
//      next_permutation(n.begin(),n.end());
//     }
// };