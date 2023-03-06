class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing=0;
        int index = 0;
        for(int i=1 ; i<=arr.back();i++){
            if(arr[index]==i){
             index++;
            }else{
                missing++;
            }
            if(missing==k){
                return i;
            }
        }

        return arr.back()+k-missing;
    }
};