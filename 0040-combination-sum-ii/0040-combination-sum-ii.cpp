class Solution {
public:
    vector<vector<int>>res;
    void comb(vector<int>& candidates,vector<int>&temp, int target,int i){
        if(target<0)return;
        if(target==0){
            res.push_back(temp);
            return;
        }
      
       for(int k=i;k<candidates.size();k++){
           if( k>i&&candidates[k-1]==candidates[k]){
               continue;
           }
           temp.push_back(candidates[k]);
           comb( candidates, temp,target-candidates[k],k+1);
           temp.pop_back(); 
    }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        comb(candidates,temp,target,0);
        return res;
    }
};