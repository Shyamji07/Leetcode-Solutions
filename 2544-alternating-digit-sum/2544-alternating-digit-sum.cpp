class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digs;
        for(; n > 0; n /= 10) {
            digs.push_back(n % 10);
        }
        int ans = 0;
        int sgn = 1;
        for(auto it = digs.rbegin(); it != digs.rend(); ++it) {
            ans += sgn * (*it);
            sgn = -sgn;
        }
        
        return ans;
    }
};