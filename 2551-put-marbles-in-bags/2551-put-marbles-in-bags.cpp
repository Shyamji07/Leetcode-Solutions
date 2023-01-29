// class Solution {
// public:
//     // long long putMarbles(vector<int>& weights, int k) {
//     //     int n = weights.size();
//     //     if (k == 1 || n == k) return 0;
//     //     for (int i = 0; i < n-1; i++){
//     //         weights[i] += weights[i+1];
//     //     }
//     //     weights.pop_back();
//     //     sort(weights.begin(), weights.end());
//     //     long long mins = 0, maxs = 0;
//     //     for (int i = 0; i < k-1; i++){
//     //         mins += weights[i];
//     //         maxs += weights[n-2-i];
//     //     }
//     //     return maxs - mins;
//     // }
//     long long putMarbles(vector<int> A, int k) {
//         long long res = 0, n  = A.size() - 1;
//         for (int i = 0; i < n; ++i)
//             A[i] += A[i + 1];
//         A.pop_back();
//         nth_element(A.begin(), A.begin() + k - 1, A.end());
//         for (int i = 0; i < k - 1; ++i)
//             res -= A[i];
//         nth_element(A.begin(), A.begin() + n - k + 1, A.end());
//         for (int i = 0; i < k - 1; ++i)
//             res += A[n - 1 - i];
//         return res;
//     }
// };

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        
        int n = weights.size();
        for (int i = 0; i < n - 1; i++) {
            maxQ.push(weights[i] + weights[i + 1]);
            if (maxQ.size() == k) {
                maxQ.pop();
            }
            
            minQ.push(weights[i] + weights[i + 1]);
            if (minQ.size() == k) {
                minQ.pop();
            }
        }
        
        
        long long diff = 0;
        while (!minQ.empty()) {
            diff += minQ.top() - maxQ.top();
            minQ.pop(); maxQ.pop();
        }
        
        return diff;
    }
};