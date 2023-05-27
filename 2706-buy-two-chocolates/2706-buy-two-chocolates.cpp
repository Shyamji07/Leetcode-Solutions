class Solution {
public:
    int buyChoco(vector<int>& arr, int money) {
        sort(begin(arr),end(arr));
        return arr[0]+arr[1]<=money?money - (arr[0]+arr[1]) : money;
        
    }
};