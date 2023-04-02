class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& pot, long long success) {
        sort(pot.begin(), pot.end());
        int n = sp.size();
        int m = pot.size();
        for(int i = 0 ;i < n;i++){
            long long st = success/sp[i];
            if(success%sp[i] != 0) st += 1;
            int idx = lower_bound(pot.begin() , pot.end(), st) - pot.begin();
            sp[i] = m - idx;
        }
        return sp;
    }
};