class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), steps = 0;
        vector<int> max_i(n), max_j(m);
        vector<pair<int, int>> q{{0, 0}}, q1;
        while (!q.empty()) {
            ++steps;
            for (auto [i, j] : q) {
                if (i == m - 1 && j == n - 1)
                    return steps;
                for (int k = max(max_i[j], i) + 1; k < m && k - i <= g[i][j]; ++k)
                    q1.push_back({k, j});
                for (int k = max(max_j[i], j) + 1; k < n && k - j <= g[i][j]; ++k)
                    q1.push_back({i, k});
                max_i[j] = max(max_i[j], i + g[i][j]);
                max_j[i] = max(max_j[i], j + g[i][j]);
            }
            swap(q, q1);
            q1.clear();
        }
        return -1;
    }
    // int minimumVisitedCells(vector<vector<int>>& grid) {
    //     int n=grid.size(),m=grid[0].size();
    //     vector<set<int>>pos1(n),pos2(m);
    //     for(int i=0;i<n;i++)
    //         for(int j=0;j<m;j++)
    //             pos1[i].insert(j),pos2[j].insert(i);
    //     vector<vector<int>>dis(n,vector<int>(m,-1));
    //     queue<pair<int,int>>q;
    //     auto del=[&](int i,int j){pos1[i].erase(j);pos2[j].erase(i);q.emplace(i,j);};
    //     dis[0][0]=1;
    //     del(0,0);
    //     while(q.size()){
    //         auto [i,j]=q.front();q.pop();
    //         set<int>::iterator it;
    //         while((it=pos1[i].lower_bound(j))!=pos1[i].end()&&*it<=j+grid[i][j])
    //             dis[i][*it]=dis[i][j]+1,del(i,*it);
    //         while((it=pos2[j].lower_bound(i))!=pos2[j].end()&&*it<=i+grid[i][j])
    //             dis[*it][j]=dis[i][j]+1,del(*it,j);
    //     }
    //     return dis[n-1][m-1];
    // }
};