class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        long long int total = 0, maxSum = arr[0], curMax = 0, minSum = arr[0], curMin = 0;
        for (int& a : arr) {
            total += a;
            curMax = max<long long>(curMax + a, a);
            maxSum = max<long long>(maxSum, curMax);
            curMin = min<long long>(curMin + a, a);
            minSum = min<long long>(minSum, curMin);
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};