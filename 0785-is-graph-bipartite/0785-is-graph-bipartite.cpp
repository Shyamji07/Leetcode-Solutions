class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = size(graph);
        vector<int>color(n,0);
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(color[i] == 1 or color[i] == -1)continue;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto neigh : graph[curr]){
                    if(color[neigh] == 0){
                        color[neigh] = -color[curr];
                        q.push(neigh);
                    }
                    if(color[neigh] == color[curr])return false;
                }
            }
        }
        return true;
    }
};