class Solution {
public:
    int getCommon(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st(begin(arr1),end(arr1));
        int mini=INT_MAX;
        for(auto a:arr2){
            if(st.find(a)!=st.end())
                mini=min(mini,a);
        }
        return mini==INT_MAX?-1:mini;
    }
};