class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int,long long> a, b; 
        for (int num : nums2) {
            b[num]++; 
        } 
        int mx=0;
        for (int num : nums1) {
            if(num%k!=0){ continue;}
            a[num]++;
            mx=max(mx,num);
        }
        vector<long long> kp;
        
        long long gp = 0;

        for(auto it:b){
            long long h=k*it.first;
            long long jp=0; 
            int op=1;
            while(op*h<=mx){
                jp+=a[op*h];
                op++;
            }
            gp+=jp*it.second;
        }

        return gp;
    }
};