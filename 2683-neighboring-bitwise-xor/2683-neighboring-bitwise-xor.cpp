class Solution {
public:
    bool doesValidArrayExist(vector<int>& A) {
        return accumulate(A.begin(), A.end(), 0) % 2 == 0;
    }
};