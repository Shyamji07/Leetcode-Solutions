// class Solution {
// public:
//     int buyChoco(vector<int>& arr, int money) {
//         sort(begin(arr),end(arr));
//         return arr[0]+arr[1]<=money?money - (arr[0]+arr[1]) : money;
        
//     }
// };

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int x = INT_MAX,y = INT_MAX;
        for(auto &i: prices){
            if(x>i){
                y = x;
                x = i;
            }else if(y>i){
                y = i;
            }
        }
        if(x+y>money)return money;
        return money-x-y;
    }
};