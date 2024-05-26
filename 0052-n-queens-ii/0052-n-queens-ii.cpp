class Solution {
    int ans = 0;
    void dfs(int col, vector<int>&left, vector<int>&updig, vector<int>&lowdig, int n){
        if(col == n){
            ans++;
            return;
        }
        
        for(int row =0;row< n;row++){
            if(left[row] == 0 and updig[row+col] == 0 and lowdig[n-1 + col - row] == 0){
                left[row] = 1;
                updig[row+col] = 1;
                lowdig[n-1 + col -row] = 1;
                
                dfs(col+1,left, updig, lowdig, n);
                
                left[row] = 0;
                updig[row+col] = 0;
                lowdig[n-1 + col - row] = 0;
            }
            
            
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> left(n,0) , updig(2*n-1,0), lowdig(2*n-1, 0);
        dfs(0, left, updig, lowdig, n);
        return ans;
    }
};