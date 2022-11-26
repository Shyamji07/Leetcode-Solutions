class Solution {
public:
    int numberOfCuts(int n) {
        return n % 2 ? (n==1?0:n) : n / 2;
    }
};