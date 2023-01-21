class Solution {
public:
    int getCommon(vector<int>& arr1, vector<int>& arr2) {
        int i = 0, j = 0;
        while(i < arr1.size() && j < arr2.size() ){
            if(arr1[i] == arr2[j]) return arr1[i];
            if(arr1[i] > arr2[j]) j++;
            else i++;
        }
        return -1;
    }
};


// class Solution {
// public:
//     int getCommon(vector<int>& arr1, vector<int>& arr2) {
//         unordered_set<int>st(begin(arr1),end(arr1));
//         int mini=INT_MAX;
//         for(auto a:arr2){
//             if(st.find(a)!=st.end())
//                 mini=min(mini,a);
//         }
//         return mini==INT_MAX?-1:mini;
//     }
// };