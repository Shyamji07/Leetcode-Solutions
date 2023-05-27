class Solution {
public:
    int minExtraChar(string s, vector<string>& arr) {
        unordered_set<string> st(arr.begin(), arr.end());
        int n = s.length();

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;

            for (int j = i; j >= 1; j--) {
                string sub = s.substr(j - 1, i - (j - 1));

                if (st.count(sub) > 0) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }

        return dp[n];
    }
};