class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)return s;
        int ans=1;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 and r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            l++;
            r--;
            if(ans<r-l+1){
                ans=r-l+1;
                start=l;
                end=r;
            }
             l=i,r=i+1;
            while(l>=0 and r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else break;
            }
            l++;
            r--;
            if(ans<r-l+1){
                ans=r-l+1;
                start=l;
                end=r;
            }
            
        }

    return s.substr(start,ans);
    }
};
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if(s.size() <= 1)
//             return s;
//         int minL = 0, maxLen = 1, maxR = s.size()-1, left, right, len;
//         for(int mid = 0; mid < s.size(); ){
//             left = right = mid;
//             while(right < maxR && s[right] == s[right+1])
//                 right++;
//             mid = right + 1;
//             while(right < maxR && left > 0 && s[left-1] == s[right+1]){
//                 left--;
//                 right++;
//             }
//             len = right - left + 1;
//             if(len > maxLen){
//                 minL = left;
//                 maxLen = len;
//             }
//         }
//         return s.substr(minL, maxLen);
//     }
// };