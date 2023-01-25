#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define sv(v) sort(v.begin(), v.end())
#define rsv(v) sort(v.rbegin(), v.rend())
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
#define pll pair<long long, long long>
#define FOR(i,N) for(int i=0;i<N;i++)
#define acc(v) accumulate(v.begin(), v.end(), 0LL)
const int mod=1e9+7;

class Solution{
    public:

 void dfs(int curr,vi &e,vi &memo,int dist){
     if(curr!=-1 and memo[curr]==-1){
         memo[curr]=dist+1;
             dfs(e[curr],e,memo,dist+1);
     }
     return;
 }   
int closestMeetingNode(vector<int>& e, int n1, int n2) {
       int res = -1, min_dist = INT_MAX;
    vi m1(e.size(), -1), m2(e.size(), -1);
    dfs(n1, e, m1,0);
    dfs(n2, e, m2,0);
    for (int i = 0; i < e.size(); ++i){
        if (min(m1[i], m2[i]) >= 0 && max(m1[i], m2[i]) < min_dist) {
            min_dist = max(m1[i], m2[i]);
            res = i;
        }
    }
    return res;
    }
};