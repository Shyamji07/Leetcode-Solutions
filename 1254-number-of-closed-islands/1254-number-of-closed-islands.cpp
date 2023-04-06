// class Solution
// {
//     public:
    
//         bool dfs(vector<vector < int>> &grid, int i, int j, vector< vector< int>> &dp)
//         {
//             if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
//             if (grid[i][j] == 1 || grid[i][j] == 2) return true;
//             grid[i][j] = 2;	   // VISITED I J
//             bool a = dfs(grid, i, j + 1, dp);
//             bool b = dfs(grid, i, j - 1, dp);
//             bool c = dfs(grid, i + 1, j, dp);
//             bool d = dfs(grid, i - 1, j, dp);
//             return a &b &c &d;
//         }

//     int closedIsland(vector<vector < int>> &grid)
//     {
//         int i, j, ans = 0;
//         vector< vector< int>> dp;
//         for (i = 0; i < grid.size(); i++)
//         {
//             for (j = 0; j < grid[0].size(); j++)
//             {
//                 if (grid[i][j] == 0)
//                 {
//                     if (dfs(grid, i, j, dp)) ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, grid, visit)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;
        bool isClosed = true;

        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        while (!q.empty()) {
            x = q.front().first;   // row nnumber
            y = q.front().second;  // column number
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    // (x, y) is a boundary cell.
                    isClosed = false;
                } else if (grid[r][c] == 0 && !visit[r][c]) {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }

        return isClosed;
    }
};