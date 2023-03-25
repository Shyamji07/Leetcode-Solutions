class Solution {
public:
    vector<long long> adj[100001];
    long long vis[100001];
    int count;
    
    void DFS(int src) {
        vis[src] = 1;
        count++;

        for (int adjacent : adj[src]) {
            if (vis[adjacent] == 0) {
                DFS(adjacent);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<long long> v;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                count = 0;
                DFS(i);
                v.push_back(count);
            }
        }
        
        long long ans = 0;
        long long sum = 0;
        for (int i=0; i <= v.size() - 1; i++) {
            ans += (v[i] * sum);
            sum += v[i];
        }
        
        return ans;
    }
};