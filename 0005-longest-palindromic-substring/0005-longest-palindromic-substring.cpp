class Solution {
public:
    string longestPalindrome(string s) {
      
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        int maxLen=1;
        
        //for substr of length 1
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        //for substr of length 2
        int start=0;
        for(int i=0;i<n-1;i++)
        {
           if(s[i]==s[i+1]) 
           {
               dp[i][i+1]=1;
               start=i;
               maxLen=2;
           }
        }
        
        //sustr of length _k_
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(dp[i+1][j-1]==1 && s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(k>maxLen)
                    {
                        start=i;
                        maxLen=k;
                    }
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};

/*


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
*/