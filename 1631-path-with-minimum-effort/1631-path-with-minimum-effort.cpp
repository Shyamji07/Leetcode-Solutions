class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
             int m=h.size();
        int n=h[0].size();
        int pos[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        vector<vector<int> > dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;
        
		// Set stores { Distance_from_Source, {Row, Column} }
        set<pair<int, pair<int, int> >> st;
        st.insert({0, {0, 0}});
        
        while(!st.empty()){
            pair<int, pair<int, int> > cell = *st.begin();
            st.erase(st.begin());
            
            int i=cell.second.first;
            int j=cell.second.second;
            int d=cell.first;
            
            for(auto it: pos){
                int u=i+it[0], v=j+it[1];
                
                if(u<0 || v<0 || u>=m || v>=n)  continue;
                
                if(dist[u][v] > max(d , abs(h[u][v]-h[i][j]))){
                    
                    if(dist[u][v]!=INT_MAX)
                        st.erase({dist[u][v], {u, v}});
                    
                    dist[u][v]= max(d , abs(h[u][v]-h[i][j]));
                    
                    st.insert({dist[u][v], {u, v}});
                }
            }
        }
        return dist[m-1][n-1];

    }
};