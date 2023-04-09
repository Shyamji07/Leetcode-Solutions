bool sieve[4000001] =  { true, true }; 
class Solution {
public:
void buildSieve() {
    for (int p = 2; p * p < 400001; ++p)
        if (!sieve[p])
            for (int i = p * p; i < 400001; i += p)
                sieve[i] = true;
}    
int diagonalPrime(vector<vector<int>>& n) {
    if (!sieve[4])
        buildSieve();
    int p = 0;
    for (int i = 0; i < n.size(); ++i)
        p = max({p, !sieve[n[i][i]] * n[i][i], 
            !sieve[n[i][n.size() - i - 1]] * n[i][n.size() - i - 1]});
    return p;
}
};