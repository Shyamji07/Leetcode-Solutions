class Solution {
public:
    int partitionString(string s) {
        vector<int>v(26,0);
        int count=1;
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']==0)v[s[i]-'a']++;
            else {
                count++;
                fill(v.begin(),v.end(),0);
                v[s[i]-'a']++;
            }
        }
            return count;
    }
};