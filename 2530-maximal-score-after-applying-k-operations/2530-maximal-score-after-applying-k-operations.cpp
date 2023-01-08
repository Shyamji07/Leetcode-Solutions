class Solution {
public:
    long long maxKelements(vector<int>& a, int k) {
        make_heap(a.begin(),a.end());
        long long res=0;
        while(k--){
            int t=a[0];
            res+=t;
            pop_heap(a.begin(),a.end());
            a.back()=(t+2)/3;
            push_heap(a.begin(),a.end());
        }
        return res;
    }
};