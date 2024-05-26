class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int count = 1;
        for(int i = 1; i < word.size(); ++i, count++){
            if(count < 9 && word[i] == word[i-1] ) continue;
            ans += to_string(count) + word[i-1];
            count = 0;
        }
        ans += to_string(count) + word.back();
        return ans;
    }
};