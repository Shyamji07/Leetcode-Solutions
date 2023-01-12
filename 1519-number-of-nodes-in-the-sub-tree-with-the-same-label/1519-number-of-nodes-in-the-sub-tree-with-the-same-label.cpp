class Solution {
public:
void helper(vector<int>&v1 , vector<int>&v2){
    for(int i = 0 ;i < v1.size();i++)
        v1[i]+=v2[i];
}
    map<int , int>m;
    vector<int> dfs(int node , vector<vector<int>> & adjlist , vector<bool>&visited , string & labels){

        visited[node] = true;
        vector<int>freq(26 , 0);
        for(int i = 0 ;i < adjlist[node].size();i++)
            if(!visited[adjlist[node][i]])
            {
                vector<int> s = dfs(adjlist[node][i] , adjlist , visited , labels);
                helper(freq , s);
            }
        m[node] = ++freq[labels[node] - 'a'];
        return freq;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adjlist(n);
        vector<bool>visited(n , false);
        vector<int>freq(26 , 0);
        vector<int>res;
        for(auto & edge : edges)
            adjlist[edge[0]].push_back(edge[1]) , adjlist[edge[1]].push_back(edge[0]);
        freq = dfs(0 , adjlist , visited , labels);
        for(auto & [x,y] : m)
            res.push_back(y);
        return res;

    }
};