class Solution {
public:
    int strStr(string haystack, string needle) {
           if (needle.empty()) return 0; // edge case 
        
        for (int i = 0; i <= (int) (haystack.size() - needle.size()); ++i) {
            if (haystack.substr(i, needle.size()) == needle) 
                return i; 
        }
        return -1; 
    }
    
};