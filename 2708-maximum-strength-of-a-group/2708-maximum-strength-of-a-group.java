import java.util.Arrays;

class Solution {
    public long maxStrength(int[] nums) {
        Arrays.sort(nums);
        long res = 1;
        int sz = nums.length;
        int cnt = 0;
        for (int i = 0; i < sz; ++i) {
            if (res * nums[i] > 0 || (i + 1 < sz && nums[i + 1] < 0)) {
                res *= nums[i];
                ++cnt;
            }
        }
        return cnt != 0 ? res : nums[sz - 1];
    }
}
