class Solution
{
    public:
    
        bool dfs(vector<vector < int>> &grid, int i, int j, vector< vector< int>> &dp)
        {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
            if (grid[i][j] == 1 || grid[i][j] == 2) return true;
            grid[i][j] = 2;	   // VISITED I J
            bool a = dfs(grid, i, j + 1, dp);
            bool b = dfs(grid, i, j - 1, dp);
            bool c = dfs(grid, i + 1, j, dp);
            bool d = dfs(grid, i - 1, j, dp);
            return a &b &c &d;
        }

    int closedIsland(vector<vector < int>> &grid)
    {
        int i, j, ans = 0;
        vector< vector< int>> dp;
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    if (dfs(grid, i, j, dp)) ans++;
                }
            }
        }
        return ans;
    }
};