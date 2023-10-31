class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int n=v.size();
        vector<int>arr(n);
        arr[0]=v[0];
        int curr=arr[0];
        for(int i=1;i<n;i++){
            arr[i]=curr^v[i];
            curr^=arr[i];
        }
        return arr;
    }
};