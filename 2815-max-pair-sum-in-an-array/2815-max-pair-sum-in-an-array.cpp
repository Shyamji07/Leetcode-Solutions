class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,vector<int>> mp;
        for(auto n: nums){
            int t = n, maxDigit = 0;
            while(t){ //evaluate max digit in the number
                maxDigit = max(t%10, maxDigit);
                t = t/10;
            }
            mp[maxDigit].push_back(n); // add the number to the map 
        }
        for(auto [k, v]: mp){
            sort(v.rbegin(), v.rend()); //to find max two number in each max digit 
            if(v.size() >= 2) ans = max(ans, v[0] + v[1]); //sum max two number and take max
        }
        return ans;
    }
};