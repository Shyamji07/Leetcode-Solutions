class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>pascal(n+1,1);
        for(int row=1;row<=n;row++) 
            for(int i=row-1;i>=1;i--) 
                pascal[i]+=pascal[i-1];               
        return pascal; 
        
    }
};