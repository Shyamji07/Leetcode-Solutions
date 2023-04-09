class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<set<int>>pos1(n),pos2(m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                pos1[i].insert(j),pos2[j].insert(i);
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        auto del=[&](int i,int j){pos1[i].erase(j);pos2[j].erase(i);q.emplace(i,j);};
        dis[0][0]=1;
        del(0,0);
        while(q.size()){
            auto [i,j]=q.front();q.pop();
            set<int>::iterator it;
            while((it=pos1[i].lower_bound(j))!=pos1[i].end()&&*it<=j+grid[i][j])
                dis[i][*it]=dis[i][j]+1,del(i,*it);
            while((it=pos2[j].lower_bound(i))!=pos2[j].end()&&*it<=i+grid[i][j])
                dis[*it][j]=dis[i][j]+1,del(*it,j);
        }
        return dis[n-1][m-1];
    }
};