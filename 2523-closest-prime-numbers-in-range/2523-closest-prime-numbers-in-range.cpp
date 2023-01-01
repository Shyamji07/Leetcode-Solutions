bool np[1333333];
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        memset(np,0,sizeof np);
        int gap=1e9,ls=-1,I,J;
        for(int i=2;i<=right;++i) if(!np[i]) {
            if(i>=left) {
            if(ls!=-1) {
                if(i-ls<gap) gap=i-ls,I=i,J=ls;
            }
            ls=i;
            }
            for(int j=i;j<=right;j+=i) np[j]=1;
        }
        if(gap>1e8) return {-1,-1};
        return {J,I};
    }
};