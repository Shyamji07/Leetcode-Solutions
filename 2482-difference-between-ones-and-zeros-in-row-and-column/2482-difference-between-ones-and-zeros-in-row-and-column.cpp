class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& arr) {
        vector<pair<int,int>>row(arr.size(),{0,0}),col(arr[0].size(),{0,0});
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1)row[i].first++,col[j].first++;
                else row[i].second++,col[j].second++;
            }            
        }
        vector<vector<int>>ans;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                arr[i][j]=row[i].first +col[j].first -row[i].second -col[j].second;
            }
        }
        return arr;
    }
};