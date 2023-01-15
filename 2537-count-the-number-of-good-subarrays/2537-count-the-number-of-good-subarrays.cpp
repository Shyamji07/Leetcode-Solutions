class Solution { 
public: 
    long long countGood(vector<int>& arr, int k) {
        long long res = 0;
        unordered_map<int, int> freq;
        for (int i = 0, j = 0; j < arr.size(); ++j) {
            k -= freq[arr[j]]++;
            while (k <= 0)
                k += --freq[arr[i++]];
            res += i;
        }
        return res;
    }
};