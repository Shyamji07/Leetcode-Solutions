class Solution {
public:
    bool makeStringsEqual(string s, string t) {
    return (count(begin(s), end(s), '1') > 0) == (count(begin(t), end(t), '1') > 0);
}
    
    // bool makeStringsEqual(string s, string t) {
    //     return (s.find('1') != string::npos) == (t.find('1') != string::npos);
    // }
};