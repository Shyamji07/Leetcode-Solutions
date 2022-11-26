const int mod=1e9+7;
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& arr) {
        vector<pair<int,int>>row(arr.size()),col(arr[0].size());
        for(int i=0;i<arr.size();i++){
            int count1=0,count0=0;
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==0)count0++;
                else count1++;
            }
            row[i]={count1,count0};
            
        }
         for(int i=0;i<arr[0].size();i++){
            int count1=0,count0=0;
            for(int j=0;j<arr.size();j++){
                if(arr[j][i]==0)count0++;
                else count1++;
            }
            col[i]={count1,count0};
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