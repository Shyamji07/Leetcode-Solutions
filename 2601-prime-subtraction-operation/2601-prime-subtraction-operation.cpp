class Solution {
public:
    // bool primeSubOperation(vector<int>& arr) {
    //     vector<int>prime ={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1000};
    //     int prev=0;
    //     for(int i=0;i<arr.size();i++){
    //         std::vector<int>::iterator low1;
    //         low1 = std::lower_bound(prime.begin(), prime.end(), arr[i]-prev);
    //         if(low1-prime.begin() == prime.size() || low1-prime.begin() == 0){
    //             prev = arr[i];
    //             continue;
    //         }
    //         else {
    //             int j = low1-prime.begin()-1;
    //             while(arr[i] -prime[j] <= prev and j>=0){
    //                  cout<<i<<" loww  ";
    //                 j--;
    //             }
    //             arr[i] = arr[i] - prime[j];
    //         }
    //         prev = arr[i];
    //     }
    //     for(int i=1;i<arr.size();i++){
    //         if(arr[i]<= arr[i-1])return false;
    //     }
    //     return true;
    // }
    
    vector<int> getPrimes() {
    vector<int> ps = {2}, sieve(1001);
    for (int i = 3; i < 32; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= 1000; j += i)
                sieve[j] = true;
    for (int i = 3; i <= 1000; i += 2)
        if (!sieve[i])
            ps.push_back(i);
    return ps;
}
bool primeSubOperation(vector<int>& nums) {
    auto ps = getPrimes();
    for (int i = 0; i < nums.size(); ++i) {
        auto it = lower_bound(begin(ps), end(ps), nums[i] - (i ? nums[i - 1] : 0));
        if (it != begin(ps))
            nums[i] -= *prev(it);
        if (i && nums[i] <= nums[i - 1])
            return false;
    }
    return true;
}
};