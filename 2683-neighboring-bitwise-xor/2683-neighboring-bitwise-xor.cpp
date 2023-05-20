// class Solution {
// public:
//     // bool doesValidArrayExist(vector<int>& A) {
//     //     return accumulate(A.begin(), A.end(), 0) % 2 == 0;
//     // }
//     bool doesValidArrayExist(vector<int>& derived) { 
//         return accumulate(begin(derived), end(derived), 0, bit_xor<>()) == 0;
//     }
// };

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int total = 0;
        for(int &a: derived)
            total = total ^ a;
        return total == 0;
    }
};