class Solution {
public:
    vector<vector<int>>ans;
   void comb(vector<int>& candidates,int sum,int i,vector<int>&res,int target){
       if(sum>target)return;
        if(sum==target){
            ans.push_back(res);
          return;
        }
       for(int k=i;k<candidates.size();k++){
           res.push_back(candidates[k]);
           comb( candidates, sum+candidates[k],k,res, target);
    res.pop_back(); 
       };
      
       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        comb( candidates,0,0,res, target);
            return ans;
    }
};