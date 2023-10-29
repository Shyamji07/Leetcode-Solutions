class Solution {
public:
    int poorPigs(int buckets, int m, int t) {
        int ans=0;
        while(pow((t/m+1),ans)<buckets) ans++;
        return ans;
    }
};