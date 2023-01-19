class Solution {
public:
    vector<int> fun(vector<int>& a) {
        int n = a.size();
        vector<int> pref(n);
        pref[0] = a[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];
        return pref;
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> pref = fun(nums);
        vector<int> m(k);
        m[0] = 1;
        int ans = 0;
        for (auto& x : pref) {
            // if x is negative, turn it to positive modular equivalent
            if (x < 0) x = (x % k + k) % k;m[x % k]++;
        }
        for (auto& x : m) ans += x * (x - 1) / 2;
        return ans;
    }
};