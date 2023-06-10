class Solution {
public:
    
   long long  int test(int a,int index,int n)
    {
        long long int b=max(0,a-index);
        long long int res=(a+b)*(a-b+1)/2;
        b=max(0,(a-((n-1)-index)));
        res=res+(a+b)*(a-b+1)/2;
        
        return res-a;
    }
    
    int maxValue(int n, int index, int maxSum) {
        
        
        maxSum=maxSum-n;
        int l=0,r=maxSum;
        
        while(l<r)
        {
            int m=(l+r+1)/2;
            if(test(m,index,n)>maxSum)
            {
                r=m-1;
            }
            else
            {
                l=m;
            }
        }
        return l+1;
        
        
    }
};