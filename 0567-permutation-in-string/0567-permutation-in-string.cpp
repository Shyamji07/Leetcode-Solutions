class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0, m = s1.size(), n = s2.size();
        if(m > n) return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        
        for(i=0; i<m; i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }
        
        for(; i<n; i++){
            if(cnt1 == cnt2) return true;
            cnt2[s2[i-m]-'a']--;
            cnt2[s2[i]-'a']++;
        }
        return cnt1 == cnt2 ? true : false;
    }
};