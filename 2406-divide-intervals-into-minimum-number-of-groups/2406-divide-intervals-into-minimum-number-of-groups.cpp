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
#define forr(i,N) for(int i=0;i<N;i++)
#define acc(v) accumulate(v.begin(), v.end(), 0)
//#define map map<int,int>
#define sz size()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)

const int mod=1e9+7;




class Solution {
public:
    int minGroups(vector<vector<int>>& arr2) {
         sort(arr2.begin(), arr2.end());
 int n=arr2.size();
    priority_queue<int, vector<int>, greater<int> > p;
    int count = 1;
    p.push(arr2[0][1]);
 
    for (int i = 1; i < n; i++) {
 
        
        if (p.top() >= arr2[i][0]) {
            count++;
        }
        else {
            p.pop();
        }
        p.push(arr2[i][1]);
    }
 
    return count;

    }
};