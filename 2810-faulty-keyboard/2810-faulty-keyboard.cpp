class Solution {
public:
    string finalString(const string &s) {
        deque<char> dq;
        bool flip = false;
        for (auto ch: s)
            if (ch == 'i')
                flip = !flip;
            else
                dq.insert(flip ? begin(dq) : end(dq), ch);
        return flip ? string(rbegin(dq), rend(dq)) : string(begin(dq), end(dq));
    }
    // string finalString(string s) {
    //     string ans = "";
    //     for(int i = 0; i<size(s) ; i++){
    //         if(s[i] != 'i')ans+=s[i];
    //         else reverse(begin(ans),end(ans));
    //     }
    //     return ans;
    // }
};