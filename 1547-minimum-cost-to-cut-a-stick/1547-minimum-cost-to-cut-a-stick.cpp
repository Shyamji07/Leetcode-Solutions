class Solution {
public:
    int dp[101][101]{};
    int solve(int start , int end , vector<int>&cuts , int left , int right){
        if(left > right)return 0;
        if(dp[left][right])return dp[left][right];
        
        int cost = INT_MAX;
        for(int i = left; i <= right; i++){
            int left_cost = solve(start , cuts[i] , cuts , left , i - 1);
            int right_cost = solve(cuts[i] , end , cuts , i + 1 , right);
            
            cost = min(cost , end - start + left_cost + right_cost);
        }
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts) , end(cuts));
        return solve(0 , n , cuts , 0 , cuts.size() - 1);
    }
};