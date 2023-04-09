class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
        int n=a.size();
        sort(a.begin(),a.end());
        int l=0,r=a[n-1],res=r;
        while(l<=r){
            int x=(l+r)/2,s=0,F=0;
            for(int i=1;i<n;i++){
                if(a[i]-a[i-1]<=x&&!F)F=1,s++;
                else F=0;
            }
            
            if(s>=p)res=x,r=x-1;
            else l=x+1;
        }return res;
    }
};