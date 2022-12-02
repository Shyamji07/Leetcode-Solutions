class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& arr) {
        sort(begin(arr),end(arr));
        vector<int>v(arr.size());
        iota(v.begin(),v.end(),0);
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[*v.begin()]=arr[i];
            v.erase(v.begin());
            v.push_back(*v.begin());
            v.erase(v.begin());
        }
        return ans;
    }
};