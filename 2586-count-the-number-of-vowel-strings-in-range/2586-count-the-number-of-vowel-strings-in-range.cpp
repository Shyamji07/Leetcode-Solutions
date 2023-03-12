class Solution {
public:
    int vowelStrings(vector<string>& words, int l, int r) {
        return count_if(begin(words) + l, begin(words) + r + 1, [](const auto &s){
        auto isVowel = [](char c) { 
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        return isVowel(s[0]) && isVowel(s.back());
    });
    }
};