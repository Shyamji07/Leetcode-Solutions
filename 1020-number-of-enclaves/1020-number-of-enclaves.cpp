class Solution {
void dfs(vector<vector<int>>& grid, int i, int j){
    grid[i][j]=0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    for(int k=0;k<4;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if( x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y]==1)
        dfs(grid, x, y);
    }
}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i == m-1 || j==0 || j==n-1) && grid[i][j]==1){
                    dfs(grid, i, j);
                }
            }
        }
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) res++;
            }
        }
        return res;
    }
};