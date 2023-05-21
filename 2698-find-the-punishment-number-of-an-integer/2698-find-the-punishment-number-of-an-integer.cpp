// class Solution {
// public:
//      bool canSplit(int i, string s, int n, int sum) {
//         if (i == s.length()) {
//             if (sum == n){
//                 return true;
//             }
//             return false;
//           }
//          for (int k = i; k < s.length(); k++) {
//             if (canSplit(k + 1, s, n, sum + stoi(s.substr(i, k - i + 1)))){
//               return true;
//             }
//           }
//           return false;
//     }
//     int punishmentNumber(int n) {
//       int ans = 0;
//       for (int i = 1; i <= n; i++)
//         if (canSplit(0, to_string(i * i), i, 0)) ans += i * i;
//       return ans;
//     }
// };

class Solution {
public:
  int punishmentNumber(int n) {
    static vector<int> v{
      1,   9,   10,  36,  45,  55,  82,  91,  99,  100, 235, 297, 369, 370,  379,
      414, 657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000,
    };
    int res = 0;
    for (int i : v) {
      if (i > n) {
        break;
      }
      res += i * i;
    }
    return res;
  }
};