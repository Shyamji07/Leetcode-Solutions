class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256, -1); // when a char is not seen, its index is -1
        int start = -1, res = 0;
        for (int i = 0; i < s.size(); i++) {
            start = max(start, vis[s[i]]); // update the start index of the substring
            res = max(res, i - start); // update the result
            vis[s[i]] = i; // update the index when last seen
        }
        return res;
    }  
};