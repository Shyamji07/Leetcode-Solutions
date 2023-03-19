class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int da[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int db[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        int n=grid.size(),cnt = 0;;
        queue<pair<int, int>>q;
        q.push({0, 0});
         
        while(!q.empty()){
            bool ok = false;
            int i = q.front().first, j = q.front().second;
            q.pop();
            for(int k=0; k<8; k++){
                int next_i = i + da[k], next_j = j + db[k];
                if(next_i>=0 && next_i<n && next_j>=0 && next_j<n && grid[next_i][next_j]==cnt+1){
                    i = next_i;
                    j = next_j;
                    ok = true;
                    break;
                }
            }
            if(ok) q.push({i,j});
            cnt++;
        }
        return cnt==(n*n) ? 1 : 0;
    }
};