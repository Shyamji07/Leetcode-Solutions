class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        vector<set<int>> graph(n);
        for (auto connection : connections) {
            int u = connection[0], v = connection[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        vector<int> visited(n, 0);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                dfs(i, graph, visited);
            }
        }
        
        return components - 1;
    }
    
private:
    int dfs(int node, vector<set<int>>& graph, vector<int>& visited) {
        if (visited[node] != 0) return 0;
        visited[node] = 1;
        for (int neighbor : graph[node]) dfs(neighbor, graph, visited);
        return 1;
    }
};