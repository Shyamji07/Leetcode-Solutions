class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res(nums.size());
        unordered_map<int, long long> sum_l, sum_r, cnt_l, cnt_r;    
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = cnt_l[nums[i]] * i - sum_l[nums[i]];
            sum_l[nums[i]] += i;
            ++cnt_l[nums[i]];
        }  
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] += sum_r[nums[i]] - cnt_r[nums[i]] * i;
            sum_r[nums[i]] += i;
            ++cnt_r[nums[i]];
        }
        return res;
}
};