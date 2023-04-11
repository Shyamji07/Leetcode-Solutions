#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define mi  multiset<int>
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
const int mod=1e9+7;

class Solution {
public:
    string removeStars(string s) {
        mi s1, s2;
        string ans;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*') s1.insert(i);
            else s2.insert(i);
        }
        for(int i: s1){
            auto it = --(s2.lower_bound(i));
            s2.erase(it);
        }
        
        for(int i: s2) ans += s[i];
        return ans;
        
    }
};