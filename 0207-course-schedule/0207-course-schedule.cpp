class Solution { //BFS
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == n;
    }
   
};

//DFS
// class Solution {
// public:
//     //In visited: 0->not explored, 1->being explored, 2->fully explored
//     bool iscycle(vector<int> adj[],vector<int> &vis,int id){
//         if(vis[id]==1)
//             return true;
//         if(vis[id]==0){
//             vis[id]=1;
//             for(auto edge : adj[id]){
//                 if(iscycle(adj,vis,edge))
//                     return true;
//             }
//         }
//         vis[id] = 2;
//         return false;
//     }
//     bool canFinish(int n, vector<vector<int>>& pre) {
//         vector<int> adj[n];
//         for(auto edge : pre)
//             adj[edge[1]].push_back(edge[0]);
//         vector<int> vis(n,0);
        
//         for(int i=0;i<n;i++){
//             if(iscycle(adj,vis,i))
//                 return false;
//         }
//         return true;
//     }
// };


