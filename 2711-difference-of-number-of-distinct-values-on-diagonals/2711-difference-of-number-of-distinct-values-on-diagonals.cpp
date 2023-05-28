class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int> > ans(grid.size(),vector<int>(grid[0].size()));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                set<int> a,b;
                for(int k =1;i-k>=0&&j-k>=0;k++)a.insert(grid[i-k][j-k]);
                for(int k =1;i+k<grid.size()&&j+k<grid[0].size();k++)b.insert(grid[i+k][j+k]);
                ans[i][j]=abs((int)(a.size()-b.size()));    
            }
        }
        return ans;
    }
};