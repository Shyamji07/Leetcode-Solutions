class Solution {
public:
    int bal[21] = {};
int maximumRequests(int n, vector<vector<int>>& requests, int i = 0) {
    if (i == requests.size())
        return count(begin(bal), begin(bal) + n, 0) == n ? 0 : INT_MIN;
    --bal[requests[i][0]];
    ++bal[requests[i][1]];
    auto take = 1 + maximumRequests(n, requests, i + 1);
    ++bal[requests[i][0]];
    --bal[requests[i][1]];
    return max(take, maximumRequests(n, requests, i + 1));
}
};


// class Solution {
// public:
//     int answer = 0;

//     void maxRequest(vector<vector<int>>& requests, vector<int>& indegree, int n, int index, int count) {
//         if (index == requests.size()) {
//             // Check if all buildings have an in-degree of 0.
//             for (int i = 0; i < n; i++) {
//                 if (indegree[i]) {
//                     return;
//                 }
//             }
            
//             answer = max(answer, count);
//             return;
//         }
        
//         // Consider this request, increment and decrement for the buildings involved.
//         indegree[requests[index][0]]--;
//         indegree[requests[index][1]]++;
//         // Move on to the next request and also increment the count of requests.
//         maxRequest(requests, indegree, n, index + 1, count + 1);
//         // Backtrack to the previous values to move back to the original state before the second recursion.
//         indegree[requests[index][0]]++;
//         indegree[requests[index][1]]--;
        
//         // Ignore this request and move on to the next request without incrementing the count.
//         maxRequest(requests, indegree, n, index + 1, count);
//     }
    
//     int maximumRequests(int n, vector<vector<int>>& requests) {
//         vector<int> indegree(n, 0);
//         maxRequest(requests, indegree, n, 0, 0);
        
//         return answer;
//     }
// };