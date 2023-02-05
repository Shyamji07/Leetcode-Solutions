class Solution {
public:
    bool is(char x){
    if (x == 'a' || x == 'e' || x == 'i' ||x == 'o' || x == 'u')
        return true;
    else return false;
}
    vector<int> vowelStrings(vector<string>& arr, vector<vector<int>>& q) {
        vector<int> ans;
        vector<int>prefix(arr.size(),0);
        if(is(arr[0][0]) and is(arr[0][arr[0].size()-1]))prefix[0]=1;
        for(int i=1;i<arr.size();i++){
            if(is(arr[i][0]) and is(arr[i][arr[i].size()-1])){prefix[i]+=prefix[i-1]+1;}
            else prefix[i]=prefix[i-1];
        }
        for(int i=0;i<q.size();i++){
            int l=q[i][0],r=q[i][1];
            int cnt=0;
            if(l==0) ans.push_back(prefix[r]);
            else ans.push_back(prefix[r]-prefix[l-1]);
        }
        return ans;
    }
};