class Solution {
public:
     bool canSplit(int i, string s, int n, int sum) {
        if (i == s.length()) {
            if (sum == n){
                return true;
            }
            return false;
          }
         for (int k = i; k < s.length(); k++) {
            if (canSplit(k + 1, s, n, sum + stoi(s.substr(i, k - i + 1)))){
              return true;
            }
          }
          return false;
    }
    int punishmentNumber(int n) {
      int ans = 0;
      for (int i = 1; i <= n; i++)
        if (canSplit(0, to_string(i * i), i, 0)) ans += i * i;
      return ans;
    }
};