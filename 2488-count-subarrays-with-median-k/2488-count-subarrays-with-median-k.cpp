class Solution {
public:
    int countSubarrays(vector<int>& n, int k) {
    unordered_map<int, int> cnt;
    int p = find(begin(n), end(n), k) - begin(n), res = 0;
    for(int i = p, bal = 0; i < n.size(); ++i) {
        bal += n[i] == k ? 0 : n[i] < k ? -1 : 1;
        ++cnt[bal];
    }
    for(int i = p, bal = 0; i >= 0; --i) {
        bal += n[i] == k ? 0 : n[i] < k ? -1 : 1;
        res += cnt[-bal] + cnt[-bal + 1];
    }
    return res;
}
};