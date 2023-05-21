class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        int n = s.size();
        int i = 0;
        while(i<n){
            if(st.empty())st.push(s[i]);
            else if(s[i] == 'D' and st.top() == 'C')st.pop();
            else if(s[i] == 'B' and st.top() == 'A')st.pop();
            else st.push(s[i]);
            i++;
        }
        return st.size();
    }
};