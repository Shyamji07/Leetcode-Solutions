class Solution {
public:
int dp[2001] = {};
bool pal[2001][2001] = {};
int dfs(int i, int k, string &s) {
    if (i + k > s.size())
        return 0;
    if (!dp[i]) {
        dp[i] = 1 + dfs(i + 1, k, s);
        if (pal[i][i + k - 1])
            dp[i] = max(dp[i], 2 + dfs(i + k, k, s));
        if (i + k < s.size() && pal[i][i + k])
            dp[i] = max(dp[i], 2 + dfs(i + k + 1, k, s));
    }
    return dp[i] - 1;
}
int maxPalindromes(string s, int k) {
    if (k == 1)
        return s.size();
    for (int len = 1; len <= k + 1; ++len)
        for (int i = 0, j = i + len - 1; j < s.size(); ++i, ++j)
            pal[i][j] = (len < 3 ? true : pal[i + 1][j - 1]) && (s[i] == s[j]);   
    return dfs(0, k, s);
}
};