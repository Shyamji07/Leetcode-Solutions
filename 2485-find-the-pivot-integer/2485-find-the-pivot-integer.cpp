//Binary Search


// class Solution {
// public:
//     int pivotInteger(int n) {
//     int l = 1, r = n, sum = n * (n + 1) / 2;
//     while (l < r) {
//         int m = (l + r) / 2;
//         if (m * m - sum < 0)
//             l = m + 1;
//         else
//             r = m;
//     }
//     return l * l - sum == 0 ? l : -1;
// }
// };


// Pre-Computation DP

int dp[1001] = { 0, 0 };
class Solution {
public:
int pivotInteger(int n) {
    if (dp[1] == 0)
       for (int i = 1, j = 1; i <= 1000; ++i) {
           int sum = i * (i + 1) / 2;
           while (j * j < sum)
               ++j;
           dp[i] = j * j == sum ? j : -1;
       }
    return dp[n];
}
};