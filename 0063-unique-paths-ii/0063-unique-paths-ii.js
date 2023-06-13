var uniquePathsWithObstacles = function(grid) 
{
        let rows = grid.length, cols = grid[0].length;
        if(grid[0][0] === 1 || grid[rows-1][cols-1] === 1)
                return 0;
        let dp = new Array(rows);
        for(let i=0; i<rows; i++)
                dp[i] = new Array(cols).fill(0);
        
        /* Initialize the top and left sides. */
        dp[0][0] = 1;
        for(let i=1; i<cols; i++)
        {
                if(grid[0][i] === 1)
                        break;
                dp[0][i] = 1;
        }
        for(let i=1; i<rows; i++)
        {
                if(grid[i][0] === 1)
                        break;
                dp[i][0] = 1;
        }

        /* Each cell can be accessed from the left or top, so add the accesses for both. */
        for(let r=1; r<rows; r++)
        {
                for(let c=1; c<cols; c++)
                {
                        if(grid[r][c] === 1)
                                continue;
                        dp[r][c] = dp[r-1][c] + dp[r][c-1];
                }
                        
        }
        
        return dp[rows-1][cols-1];
};