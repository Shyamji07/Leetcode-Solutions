class Solution {
public:
    int equalPairs(vector<vector<int>>& arr) {
        long long ans=0;
        int n=arr.size();
        map<vector<int>,int>m1,m2;
        for(int i=0;i<n;i++){
            vector<int>temp1,temp2;
            for(int j=0;j<n;j++){
                temp1.push_back(arr[i][j]);
                temp2.push_back(arr[j][i]);
            }
            m1[temp1]++;
            m2[temp2]++;
        }
        for(auto m:m1){
            if(m2[m.first]!=0){
                ans+=(m.second*m2[m.first]);
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        for (const auto& row : grid) {
            rows[row]++;
        }
        
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> col;
            for (int j = 0; j < grid.size(); j++) {
                col.push_back(grid[j][i]);
            }
            ans += rows[col];
        }
        
        return ans;
    }
};
*/