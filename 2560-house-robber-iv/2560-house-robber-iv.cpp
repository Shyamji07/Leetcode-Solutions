class Solution {
public:
    bool isPossible(vector<int> &a, int k, int req){
        vector<int> dp(a.size());
        for(int i=0;i<a.size();i++){
            dp[i]=-1;
        }
        int maxi=help(a,k,0,dp);
        return maxi>=req;
    }
    int help(vector<int> &arr, int k, int i, vector<int> &v){
        if(i>=arr.size())return 0;
        if(v[i]!=-1)return v[i];
        int temp=help(arr,k,i+1,v);
        if(arr[i]<=k){
            return v[i]= max(help(arr,k,i+2,v)+1,temp);
        }
        return v[i]= temp;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int l=0, r=1e9;
        while(l<r-1){
            int mid=l+(r-l)/2;
            if(isPossible(nums,mid,k))
                r=mid;
            else l=mid;
   
        }
        return r;
    }
};