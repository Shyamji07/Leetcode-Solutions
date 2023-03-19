class Solution {
public:
   int findSmallestInteger(vector<int>& nums, int v) {
        int m[100001] = {}, sz = nums.size();
        for (auto n : nums)
            ++m[(v + n % v) % v];
        for (int i = 0; i < sz; ++i)
            if (--m[i % v] < 0)
                return i;
        return sz;
    }
};