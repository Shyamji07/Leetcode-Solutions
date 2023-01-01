// int ps[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
// // We only need to know primes up to sqrt(1000).

// // If, after dividing n by all these primes, n is still greater than 1, then what remains is a large prime.


// class Solution {
// public:
// int distinctPrimeFactors(vector<int>& nums) {
//     unordered_set<int> primes;
//     for (int n : nums) {
//         for (int p : ps)
//             if (n % p == 0) {
//                 primes.insert(p);
//                 while (n % p == 0)
//                     n /= p;
//             }
//         if (n != 1)
//             primes.insert(n); // large prime.
//     }
//     return primes.size();
// }
// };

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> g;
        for(auto t:nums) {
            for(int i=2;i*i<=t;++i) if(t%i==0) {
                g.insert(i); while(t%i==0) t/=i;
            }
            if(t>1) g.insert(t);
        }
        return g.size();
    }
};