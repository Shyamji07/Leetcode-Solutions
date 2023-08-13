class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            string first = to_string(nums[i]);
            sort(begin(first),end(first));
            
            for(int j = i+1; j<nums.size(); j++){
                string sec = to_string(nums[j]);
                sort(begin(sec),end(sec));
                if(first[first.size()-1] == sec[sec.size()-1]){
                    res = max(res,nums[i]+nums[j]);
                }
            }
        }
        
        return res == 0 ? -1 : res;
    }
};