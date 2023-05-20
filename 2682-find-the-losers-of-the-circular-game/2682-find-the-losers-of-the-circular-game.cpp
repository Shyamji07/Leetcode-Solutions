class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> res(n);
        iota(begin(res), end(res), 1);
        for (int cur = 0, mul = 1; res[cur]; ++mul) {
            res[cur] = 0;
            cur = (cur + mul * k) % n;
        }
        res.erase(remove(begin(res), end(res), 0), end(res));
        return res;
    }
};