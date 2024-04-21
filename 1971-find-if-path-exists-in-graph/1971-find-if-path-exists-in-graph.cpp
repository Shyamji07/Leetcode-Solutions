// // Approach 1: BFS based approach
// // ==============================

// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
//         vector<vector<int>> graph(n);
//         // Build the graph
//         for(int i=0; i<edges.size(); i++) {
//             graph[edges[i][0]].push_back(edges[i][1]);
//             graph[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         // BFS
//         queue<int> q;
//         vector<int> visited(n, 0);
//         q.push(start);
//         visited[start] = 1;
//         while(!q.empty()){
//             int top = q.front();
//             q.pop();
//             if(top == end)
//                 return true;

//             for(int i=0; i<graph[top].size(); i++){
//                 if(visited[graph[top][i]] == 0){
//                     q.push(graph[top][i]);
//                     visited[graph[top][i]] = 1;
//                 }
//             }
//         }
//         return false;
//     }
// };


// // Approach 2: DFS BASED SOLUTION
// // ===============================
// class Solution {
// public:
    
//     bool dfs(vector<vector<int>>& graph, vector<int>& visited, int current, int end) {
//         if(current == end)
//             return true;
//         if(visited[current])
//             return false;
        
//         visited[current] = 1;
        
//         for(int i=0; i<graph[current].size(); i++){
//             if(dfs(graph, visited, graph[current][i], end))
//                 return true;
//         }
        
//         return false;
//     }
    
//     bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
//         vector<vector<int>> graph(n);
//         for(int i=0; i<edges.size(); i++) {
//             graph[edges[i][0]].push_back(edges[i][1]);
//             graph[edges[i][1]].push_back(edges[i][0]);
//         }
//         vector<int> visited(n, 0);
//         return dfs(graph, visited, start, end);
//     }
// };


// Approach 3: UNION FIND BASED SOLUTION
// =====================================

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x !=parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        
        if(xp == yp)
            return true;
        else {
            if(rank[xp] > rank[yp])
                parent[yp] = xp;
            else if (rank[xp] < rank[yp])
                parent[xp] = yp;
            else {
                parent[yp] = xp;
                rank[xp]++;
            }
            return false;
        }
    }
    
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        DSU uf(n);
        for(int i=0; i<edges.size(); i++) {
            uf.Union(edges[i][0], edges[i][1]);
        }
        return uf.Union(start, end);
    }
};