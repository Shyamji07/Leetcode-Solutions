// class Solution {
// public:
//     bool checkValidGrid(vector<vector<int>>& grid) {
//         int da[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
//         int db[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
//         int n=grid.size(),cnt = 0;;
//         queue<pair<int, int>>q;
//         q.push({0, 0});
         
//         while(!q.empty()){
//             bool ok = false;
//             int i = q.front().first, j = q.front().second;
//             q.pop();
//             for(int k=0; k<8; k++){
//                 int next_i = i + da[k], next_j = j + db[k];
//                 if(next_i>=0 && next_i<n && next_j>=0 && next_j<n && grid[next_i][next_j]==cnt+1){
//                     i = next_i;
//                     j = next_j;
//                     ok = true;
//                     break;
//                 }
//             }
//             if(ok) q.push({i,j});
//             cnt++;
//         }
//         return cnt==(n*n) ? 1 : 0;
//     }
// };




typedef long double ld;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl> p3l;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back


// unordered_map<int, int> depth;
// for (auto& [k, v] : depth)


class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pii> v(n*n);
        REP(i,n)REP(j,n)v[grid[i][j]]={i,j};
        if(grid[0][0])return 0;
        FOR(i,1,v.size()){
            int dx = v[i].first-v[i-1].first;
            int dy = v[i].second-v[i-1].second;
            if(abs(dx)==1 && abs(dy)==2 || abs(dx)==2 && abs(dy)==1){}
            else return 0;
        }
        return 1;
    }
};
