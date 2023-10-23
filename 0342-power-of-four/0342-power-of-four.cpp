class Solution {
public:
 
    bool isPowerOfFour(int n) {
        if(n<=0 || n==INT_MAX ||n==2)return false;
        if(n==1)return true;
        // cout<<(32-(__builtin_popcount(n-1)))<<" "<<(__builtin_clz(n-1))<<endl;
        return (__builtin_popcount(n-1))%2==0 and (__builtin_popcount(n)==1);
    }
};