class Solution {
public:
    long long minimumCost(string s) {
        long long ans=0;
        for(int i = 0;i+1<s.size();i++){
            if(s[i]!=s[i+1]){
                ans+=min(i+1,(int)s.size()-i-1);
            }
        }
        return ans;
    }
};