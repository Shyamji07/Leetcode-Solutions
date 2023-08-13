// class Solution {
// public:
//     void dfs(vector<string>&res,string s, int l,int r,int n){
//         if(l==n and r==n){
//             res.push_back(s);
//             return;
//         }
//         if(l<n)dfs(res,s+'(',l+1,r,n);
//         if(r<l)dfs(res,s+')',l,r+1,n);
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string>res;
//         dfs(res,"",0,0,n);
//         return res;
//     }
// };
class Solution {
public:
    vector<string> generateParenthesis(int n);
};
// dp as binary tree generate
vector<string> Solution::generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1, vector<string>());
    dp[0] = {""};
    for (int i = 1; i <= n; ++i) { // total
        for (int left = 0; left <= i - 1; ++left) { // left tree size
            int right = i - 1 - left;
            for (int l = 0; l < dp[left].size(); ++l) {
                for (int r = 0; r < dp[right].size(); ++r) {
                    dp[i].push_back("(" + dp[left][l] + ")" + dp[right][r]);
                }
            }
        }
    }
    return dp[n];
}
// Time Complexity: O(2^n). 
// For every index there can be two options ‘{‘ or ‘}’. So it can be said that the upper bound of time complexity is O(2^n) or it has exponential time complexity.

// Space Complexity: O(n). 
// The space complexity can be reduced to O(n) if global variable or static variable is used to store the output string.