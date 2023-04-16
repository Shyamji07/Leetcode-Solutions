class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& arr) {
        vector<long long>ans(arr.size());
        long long int maxi = 0;
        long long sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            maxi = max<long long>(maxi , (long long)arr[i]);
            ans[i] = maxi + arr[i] + sum;
            sum = ans[i]; 
        }
        return ans;
    }
};