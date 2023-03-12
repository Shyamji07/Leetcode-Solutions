class Solution {
public:
   int maxScore(vector<int>& arr) {
    sort(begin(arr), end(arr), greater<>());
    for (long long sum = 0, i = 0; i <= arr.size(); sum += arr[i++])
        if (i == arr.size() || sum + arr[i] <= 0)
            return i;
    return 0;
}
};