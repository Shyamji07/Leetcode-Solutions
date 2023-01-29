#define ll long long int
const int mod=1e9+7;
class Solution {
public:
    unsigned long long cal_pow(ll x){ 
	unsigned long long res; 
	if (x == 0)	res=1; 
	else if (x == 1)	res=2; 
	else { 
		res = cal_pow(x/2); 
		if (x % 2 == 0)	 
			res = (res * res) % mod; 
		else 
			res = (((res*res) % mod) * 2) % mod; 
	} 
	return res; 
} 
    int monkeyMove(int n) {
        unsigned long long ans=1;
        
        ans= cal_pow(n);
        if(ans==1)ans=1000000008;
        if(ans==0)ans=1000000007;
        return ans-2;
    }
};