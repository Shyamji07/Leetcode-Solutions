class Solution {
public:
    int minOperations(string s) {
        int st = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    st++;
                }
            } else {
                if (s[i] == '0') {
                    st++;
                }
            }
        }
        
        return min(st, (int) s.size() - st);
    }
};