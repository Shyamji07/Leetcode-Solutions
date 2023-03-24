class Solution {
    int dfs(int node, int prnt, vector<pair<int, int>> adj[]) {
        int cnt = 0;
        for(auto ad : adj[node]) {
            if(ad.first == prnt) continue;
            cnt += ad.second + dfs(ad.first, node, adj);
        }
        return cnt;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for(auto e : connections) {
            adj[e[0]].push_back({e[1], 1});
            adj[e[1]].push_back({e[0], 0});
        }
        return dfs(0, -1, adj);
    }
};