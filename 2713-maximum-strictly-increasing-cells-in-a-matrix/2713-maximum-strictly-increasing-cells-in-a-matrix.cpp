class Solution {
public:
    int Maxr[100005],Maxc[100005];
    int maxIncreasingCells(vector<vector<int>>& mat) {
        fill(Maxr,Maxr+mat.size(),0);
        fill(Maxc,Maxc+mat[0].size(),0);
        map<int,vector<pair<int,int> > > m;
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                m[mat[i][j]].push_back(make_pair(i,j));
            }
        }
        int ans=0;
        for(auto it:m){
            vector<int> val;
            for(auto it2:it.second){
                val.push_back(max(Maxr[it2.first],Maxc[it2.second])+1);
            }
            for(int i = 0;i<val.size();i++){
                int x=it.second[i].first;
                int y=it.second[i].second;
                Maxr[x]=max(val[i],Maxr[x]);
                Maxc[y]=max(val[i],Maxc[y]);
                ans=max(ans,val[i]);
            }
        }
        return ans;
    }
};