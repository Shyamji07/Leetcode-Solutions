class Solution {
public:
    int convert(string s){
        int time=((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
        return time>720?time:time+1440;
    }
    int findMinDifference(vector<string>& arr) {
        vector<int>v;
        for(auto s:arr)v.push_back(convert(s));
        sort(begin(v),end(v));
        int mini=v[1]-v[0];
        for(int i=2;i<v.size();i++){
            mini=min(mini,v[i]-v[i-1]);
        }
        mini = min(mini, 1440 + v.front() - v.back());
        return mini;
    }
};