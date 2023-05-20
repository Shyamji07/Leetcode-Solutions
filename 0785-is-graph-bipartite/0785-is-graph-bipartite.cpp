class Solution {
public:
    int v[101];
    bool isBipartite(vector<vector<int>>& graph) {
        int len =graph.size();
        int Q[101] = {0};
        for(int i=0;i<len;i++){
            if(v[i]==1 ||v[i]==-1)continue;
            int head = 0;
            int tail = 0;
            Q[tail++] = i;
            v[i]=1;
            while(head != tail){
                int curr = Q[head];
                head++;
                for(int next:graph[curr]){
                    if(v[next]==0){
                        v[next]=-v[curr];
                        Q[tail++] = next;
                    }
                    if(v[next]==v[curr])return false;
                }
            }
        }
        return true;
    }
};