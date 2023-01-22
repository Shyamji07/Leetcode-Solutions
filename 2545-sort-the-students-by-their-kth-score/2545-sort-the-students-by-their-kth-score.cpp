int r;
bool comp(vector<int>& a, vector<int>& b)
{   
    return (a[r]>b[r]); 
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        r=k;
        sort(score.begin(),score.end(),comp);
        return score;
    }
};
// class Solution {
// public:
//     vector<vector<int>> sortTheStudents(vector<vector<int>>& arr, int k) {
//         bool flag=true;
//         for (int i = 0; i< arr.size();i++){
//             if(flag){
//                 flag = false;
//                 for(int jj=0;jj<arr.size()-1;jj++){
//                     if(arr[jj][k] < arr[jj+1][k]){
//                         arr[jj].swap(arr[jj+1]);
//                         flag = true;
//                     }
//                 }
//             }
//             else break;
//         }
//         return arr;
//     }
// };