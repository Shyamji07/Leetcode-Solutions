int ps[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
// We only need to know primes up to sqrt(1000).

// If, after dividing n by all these primes, n is still greater than 1, then what remains is a large prime.


class Solution {
public:
int distinctPrimeFactors(vector<int>& nums) {
    unordered_set<int> primes;
    for (int n : nums) {
        for (int p : ps)
            if (n % p == 0) {
                primes.insert(p);
                while (n % p == 0)
                    n /= p;
            }
        if (n != 1)
            primes.insert(n); // large prime.
    }
    return primes.size();
}
};