class Solution {
public:
    int appendCharacters(string s, string t) {
       int i=0,j=0;
       while(1){
           if(j>=t.length()) return 0;
           if(i>=s.length()) break;
           if(s[i]==t[j])i++,j++;
           else i++;
       }
        return t.length()-j;
    }
};