class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        if(nums.size()==3) return max(nums[0]+nums[2],nums[1]);

        int dp[nums.size()+1];
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+nums[0];
        for(int i=3;i<nums.size();i++){    
                  if(dp[i-2]>=dp[i-3]){
                      dp[i]=nums[i]+dp[i-2];
                  }
            else dp[i]=nums[i]+dp[i-3];
                     
        }
      return max(dp[nums.size()-1],dp[nums.size()-2]);
                    
    }
};


// class Solution {
// public:
//     int rob(vector<int>& arr) {
//         int prev2 = 0, prev = 0, cur = 0;
//         for(auto i : arr) {
//             cur = max(prev, i + prev2);
//             prev2 = prev;
//             prev = cur;
//         }
//         return cur;
//     }
// };
