class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); 
        vector<pair<int, int>> two; 
        for (int i = 0; i < n; ++i) 
            two.emplace_back(nums2[i], nums1[i]); 
        sort(two.begin(), two.end(), greater<>()); 
        for (int i = 0; i < n; ++i) {
            nums1[i] = two[i].second; 
            nums2[i] = two[i].first; 
        }
        priority_queue<int, vector<int>, greater<>> pq; 
        long long ans = 0, sum = 0; 
        for (int i = 0; i < n; ++i) {
            sum += nums1[i]; 
            pq.push(nums1[i]); 
            if (i >= k) {
                sum -= pq.top(); pq.pop(); 
            }
            if (i >= k-1) ans = max(ans, sum * nums2[i]); 
        }
        return ans; 
    }
};