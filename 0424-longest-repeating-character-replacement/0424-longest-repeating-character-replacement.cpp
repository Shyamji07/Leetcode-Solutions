class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0, ans=0, cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            cnt=max(cnt,mp[s[i]]);
            if(i-start-cnt+1>k){
                mp[s[start]]--;
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};
