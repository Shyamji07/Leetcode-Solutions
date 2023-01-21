class Solution {
public:
    bool isReachable(int x, int y) {
        int v = gcd(x, y);
        while (v % 2 == 0)
            v /= 2;
        return v == 1;
    }
};