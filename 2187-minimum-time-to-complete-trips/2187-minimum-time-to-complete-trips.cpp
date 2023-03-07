class Solution {
public:
    long long minimumTime(vector<int>& arr, int k) {
        
        long long left =0, right=1e14,mid;
        
        while(left <= right){
            mid=(left +right)/2; 
            long long ans=0;     
            for(int i=0;i<arr.size();i++) 
                ans+= mid/arr[i];
            if(ans < k) left =mid+1;   
            else right=mid-1;       
        }
        return left;    
            
        
    }
};