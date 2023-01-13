class Solution {
public:
    int help(vector<vector<int>>&chids, string &s, int n, int &res){
        if(!chids[n].size()) //leaf node
            return 1;
        int temp,path1=0,path2=0;
        for(auto &x: chids[n]){
            temp=help(chids,s,x,res);
            if(s[n]==s[x])
                continue;
            if(temp>path1){
                path2=path1;
                path1=temp;
            }
            else if(temp>path2)
                path2=temp;
        }
        res=max(res, 1+path1+path2);
        return 1+path1;
    }
    int longestPath(vector<int>& parent, string s) {
        int res=1,n=parent.size();
        vector<vector<int>>chids(n);
        for(int i=0;i<n;i++)
            if(parent[i]>=0)
                chids[parent[i]].push_back(i);
        help(chids,s,0,res);
        return res;
    }
};