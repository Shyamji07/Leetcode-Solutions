class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freqmap;
        vector<int> freqvect;
        for (int i = 0; i < arr.size(); i++)
            freqmap[arr[i]]++;
        for (auto i: freqmap) 
            freqvect.push_back(i.second);
        sort(freqvect.begin(), freqvect.end());
        for (int i = 0; i < freqvect.size()-1; i++) 
            if (freqvect[i] == freqvect[i+1]) 
                return false;
        return true;
    }
};