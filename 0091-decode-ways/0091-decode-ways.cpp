class Solution {
public:
    int numDecodings(string s) {
       vector<int> cost(s.size() + 2, 0);
        
        cost[1] = 1;
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '0')
                cost[i+2] = cost[i+1];
            if(i) {
                int twodigit = (s[i-1] - '0') * 10 + s[i] - '0';
                if(twodigit >= 10 && twodigit <= 26)
                    cost[i+2] += cost[i];
            }
        }

        return cost.back();
    }
};