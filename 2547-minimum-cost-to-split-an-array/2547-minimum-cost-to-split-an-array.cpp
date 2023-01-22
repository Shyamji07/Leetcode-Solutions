class Solution {
public:
    int minCost(vector<int>& nums, int k, int i = 0) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = m.find(nums[i]);
        if (it == end(m))
            it = m.insert({nums[i], m.size()}).first;
        nums[i] = it->second;
    }
    int dp[1001] = {};
    for (int i = 0; i < nums.size(); ++i) {
        int cnt[1001] = {}, trim = 0;
        for (int j = i; j < nums.size(); ++j) {
            if (++cnt[nums[j]] > 1)
                trim += cnt[nums[j]] == 2 ? 2 : 1;
            dp[j + 1] = min(dp[j + 1] ? dp[j + 1] : INT_MAX, dp[i] + k + trim);
        }
    }
    return dp[nums.size()];
}
};