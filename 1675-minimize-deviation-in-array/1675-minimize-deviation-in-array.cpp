class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        vector<int> odds = nums;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(odds[i] % 2 == 0) odds[i] >>= 1;
        }
        int max_odd = *max_element(odds.begin(), odds.end());
        vector<int> v;
        for(auto x: nums){
            if(x % 2) v.push_back(x);
            else{
                do{
                    x >>= 1;
                } while(x > max_odd);
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());
        int ans = v[n - 1] - v[0];
        for(int i = 0; i < n - 1; i++){
            ans = min(ans, max(v[n - 1], 2 * v[i]) - min(v[i + 1], 2 * v[0]));
        }
        return ans;
    }
};