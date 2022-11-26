#define ll long long
class Solution {
public:
    ll dp[10001][11][11][6];
    ll mod = 1e9 + 7;;
    ll dfs(int ind, int first, int second, int i, string &s) {
        if(i == 5) return 1; //found a subsequence
        if(ind == s.length()) return 0; // traversed full string
        if(dp[ind][first][second][i] != -1) return dp[ind][first][second][i]; //already traversed
        
        //Not choosing current digit
        ll res = dfs(ind + 1, first, second, i, s);
        
      //Choosing the first digit of the subsequence
        if(i == 0) {
            res += dfs(ind + 1, s[ind] - '0', second, i + 1, s);
            res %= mod;
        } 
        
      //option of choosing the second digit of the subsequence
        else if(i == 1) {
            res += dfs(ind + 1, first, s[ind] - '0', i + 1, s);
            res %= mod;
        } 
        
      //Choosing the third digit of the subsequence
        else if(i == 2) {
            res += dfs(ind + 1, first, second, i + 1, s);
            res %= mod;
        } 
        
      //Choosing the fourth digit of the subsequence if it matches with the second digit
        else if(i == 3 and s[ind] - '0' == second) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
        } 
        
      //Choosing the fifth digit of the subsequence if it matches with the first digit
        else if(i == 4 and s[ind] - '0' == first) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
        }
        return dp[ind][first][second][i] = res;
    }
    int countPalindromes(string s) {
        memset(dp, -1, sizeof dp); 
        return dfs(0, 10, 10, 0, s);
    }
};