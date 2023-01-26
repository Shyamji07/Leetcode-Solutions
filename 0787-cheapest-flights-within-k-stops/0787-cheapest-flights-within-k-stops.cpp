class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto x : arr){
            adj[x[0]].push_back({x[1], x[2]});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> minCost(n, INT_MAX);
        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while (size--) {
                auto [curr, cost] = q.front();
                q.pop();
                for (auto& [neigh, price] : adj[curr]) {
                    if (price + cost < minCost[neigh]){
                        minCost[neigh] = price + cost;
                        q.push({neigh, minCost[neigh]});
                    }
                }
            }
            stops++;
        }
        if(minCost[dst] == INT_MAX)
            return -1;
        return minCost[dst];
    }
};