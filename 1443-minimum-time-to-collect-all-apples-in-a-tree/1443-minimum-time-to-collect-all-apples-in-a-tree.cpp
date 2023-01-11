class Solution {
public:
    vector<vector<int>> adj;
    int dfs(vector<bool>& hasApple,int node,int d,int prev){
        int ans=0,temp;
        for(auto i:adj[node])
	    if(i!=prev){
	        temp=dfs(hasApple,i,d+1,node);
	        if(temp)
		    ans+=temp-d;
	    }
        return ans||hasApple[node]?ans+d:0;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        adj.resize(n);
        for(vector<int> &e:edges)
            adj[e[0]].push_back(e[1]),adj[e[1]].push_back(e[0]);
        return dfs(hasApple,0,0,-1)*2;     
    }
};
