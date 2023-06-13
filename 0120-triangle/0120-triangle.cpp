class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        //bottom up dp
        int n = t.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<t[i].size();j++)
            {
                t[i][j] += min(t[i+1][j],t[i+1][j+1]);
            }
        }
        return t[0][0];
    }
};
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& v) {
//         for(int i=1;i<v.size();i++){
//             v[i][0]+=v[i-1][0];
//             v[i][v[i].size()-1]+=v[i-1][v[i-1].size()-1];
//             for(int j=1;j<v[i].size()-1;j++){
//                 v[i][j]+=min(v[i-1][j-1],v[i-1][j]);
//             }
//         }
//         return *min_element(v[v.size()-1].begin(),v[v.size()-1].end());
//     }
// };