class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto it : redEdges){
            adj[it[0]].push_back({it[1], 1});
        }
        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1], 2});
        }

        vector<int> dist(n, -1);
        vector<vector<bool>> vis(n, vector<bool> (3, false));

        queue<vector<int>> q;
        q.push({0, 0, 0}); // {node, steps, color}
        dist[0] = 0;
        vis[0][1] = vis[0][2] = true;

        while(!q.empty()){
            int node = q.front()[0];
            int steps = q.front()[1];
            int prev_color = q.front()[2];
            q.pop();
            for(auto it : adj[node]){
                int adj_node = it.first;
                int color = it.second;
                if(color == prev_color) continue;
                if(!vis[adj_node][color]){
                    vis[adj_node][color] = true;
                    if(dist[adj_node] == -1) {
                        dist[adj_node] = 1 + steps;
                    }
                    q.push({adj_node, 1 + steps, color});
                }
            }
        } 

        return dist;
    }
};