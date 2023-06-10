class Solution {
public:
    int semiOrderedPermutation(vector<int>& A) {
        int n = A.size();
        int i = find(A.begin(), A.end(), 1) - A.begin();
        int j = find(A.begin(), A.end(), n) - A.begin();
        return i + n - 1 - j - (i > j);
    }
};