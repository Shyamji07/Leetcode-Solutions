class Solution {
public:
    long long countQuadruplets(vector<int>& a) {
        long long res = 0;
        int n = a.size();
        vector<vector<int>> left(n, vector<int>(n+1, 0));
        vector<vector<int>> right(n, vector<int>(n+1, 0));
        for (int i = 1; i < n; ++i) {
            // new array will based on the old array
            left[i] = left[i-1];
            // update all the elements greater than a[i-1]
            for (int j = a[i-1] + 1; j <= n; ++j)
                left[i][j]++;
        }
        for (int i = n-2; i >= 0; --i) {
            right[i] = right[i+1];
            for (int j = 0; j < a[i+1]; ++j)
                right[i][j]++;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j > i; --j) {
                if (a[i] <= a[j]) continue;
                // left[i][a[j]] means the count of "until i, < a[j]"
                // right[j][a[i]] means the count of "unitl j, > a[i]"
                res += left[i][a[j]] * right[j][a[i]];
            }
        }
        return res;
    }
};