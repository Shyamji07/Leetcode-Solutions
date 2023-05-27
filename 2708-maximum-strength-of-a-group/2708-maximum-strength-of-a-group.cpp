class Solution {
public:
    long long maxStrength(vector<int> nums) {
        int size = nums.size();

        if (size == 1) {
            return nums[0];
        }

        long long negativeCount = 0;
        int maxNegative = INT_MIN;
        long long positiveCount = 0;
        long long answer = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
                continue;
            }
            if (num < 0) {
                negativeCount++;
                maxNegative = max(maxNegative, num);
            }
            else positiveCount++;
            answer *= abs(num);
        }

        if (zeroCount == size)return 0;
        if (negativeCount + zeroCount == size && negativeCount == 1)return 0;
        if (negativeCount % 2 == 0)return answer;
        else return answer / abs(maxNegative);
    }
};