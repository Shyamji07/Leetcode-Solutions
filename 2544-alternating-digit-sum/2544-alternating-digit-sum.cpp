class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digits;
        for(; n > 0; n /= 10) {
            digits.push_back(n % 10);
        }
        int ans = 0;
        int sgn = 1;
        for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
            ans += sgn * (*it);
            sgn = -sgn;
        }
        
        return ans;
    }
};