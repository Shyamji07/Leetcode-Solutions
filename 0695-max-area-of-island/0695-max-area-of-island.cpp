class Solution {
public:
    int ans=0;
    int dir[5]={0,1,0,-1,0};
    void dfs(vector<vector<int>>&arr,int i,int j,int m,int n,int &count){
        if(i<0||j<0||i>=m||j>=n|| arr[i][j]==0){
            ans=max(count,ans);
            return;
        }
        count++;
        arr[i][j]=0;
        for(int k=0;k<4;k++){
            int x=i+dir[k];
            int y=j+dir[k+1];
            dfs(arr,x,y,m,n,count);
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1 ){
                    int count=0;
                    dfs(arr,i,j,m,n,count);
                }
            }
    }
        return ans;
    }
};

