class Solution {
public:
    void dfs(vector<string>&res,string s, int l,int r,int n){
        if(l==n and r==n){
            res.push_back(s);
            return;
        }
        if(l<n)dfs(res,s+'(',l+1,r,n);
        if(r<l)dfs(res,s+')',l,r+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        dfs(res,"",0,0,n);
        return res;
    }
};
// Time Complexity: O(2^n). 
// For every index there can be two options ‘{‘ or ‘}’. So it can be said that the upper bound of time complexity is O(2^n) or it has exponential time complexity.

// Space Complexity: O(n). 
// The space complexity can be reduced to O(n) if global variable or static variable is used to store the output string.