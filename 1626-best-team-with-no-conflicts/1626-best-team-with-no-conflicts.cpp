class Solution {
  public:
      int bestTeamScore(vector<int>& scores, vector<int>& ages) {
          vector<pair<int, int>> comb;
          for (int i = 0; i < scores.size(); i++) {
              comb.push_back({ages[i], scores[i]});
          }
          sort(comb.begin(), comb.end());
          int n = comb.size();
          int maxi = 0;
          vector<int> dp(n);
          for (int i = 0; i < n; i++) {
              dp[i] = comb[i].second;
              maxi = max(maxi, dp[i]);
          }

          for (int i = 0; i < n; i++) {
              for (int j = i - 1; j >= 0; j--) {
                  if (comb[i].second >= comb[j].second) {
                      dp[i] = max(dp[i], comb[i].second + dp[j]);
                  }
              }
              maxi = max(maxi, dp[i]);
          }

          return maxi;
      }
  };