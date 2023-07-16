class Solution {
public:
    vector<vector<int>>ans;
     vector<int>curr;
    void comb(vector<int>&curr,int k,int n,int index){
         if(n<0)return;
        if(k==0 and n==0){
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<=9;i++){
            curr.push_back(i);
            comb(curr,k-1,n-i,i+1);//last parameter i+1 not index+1
            curr.pop_back();
        
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       
        if(k*(k+1)/2>n)return {};
        comb(curr,k,n,1);
        return ans;
    }
};