class Solution {
public:
   int n, m;
    int Q[10000];  // storing 2D cordinate of visited node into 1D form (x,y) ==> (x*m + y)
    int head = 0;
    int tail = 0; 
    //dfs marking all node of island 1 visited 
    void dfs(vector <vector <int>> &a, int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
            a[x][y] = 2;
            Q[tail++] = x * m + y;
            dfs(a, x + 1, y);
            dfs(a, x - 1, y);
            dfs(a, x, y + 1);
            dfs(a, x, y - 1);
        }
    }
    // bfs finding nearest distance between two island
    int bfs(vector <vector <int>> &a) {
        int d[5] = {0, 1, 0, -1, 0}; 
        while(head != tail){
            int zz = Q[head++]; 
            int xx = zz / m, yy = zz % m;  // converting 1D cordinate into 2D cordinate
            for (int k = 0; k < 4; k++) {
                int x = xx + d[k], y = yy + d[k + 1];
                if (x < 0 || y < 0 || x == n || y == n || a[x][y] > 1) continue;  //out of bound or already visited node
             if (a[x][y] == 1) return a[xx][yy] - 2; // if we found node of second island we'll return from here only
                // Why (-2)? because we already make our island 1 array node to 2 then we start expanding
                a[x][y] = a[xx][yy] + 1;  //expanding the bridge
                Q[tail++] = x * m + y;    // marking the node visited
            }
        } 
        return -1;
    }
    int shortestBridge(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    dfs(a, i, j);
                    return bfs(a);
                }
            }
        }
        return -1;
    }
};