class Solution {
public:
    int countDigits(int num) {
    auto s = to_string(num);
    return accumulate(begin(s), end(s), 0, [&](int res, char ch){ 
        return res + (num % (ch - '0') == 0);
    });
}
};