class Solution:
    def maxStrength(self, nums):
        size = len(nums)

        if size == 1:
            return nums[0]

        negativeCount = 0
        maxNegative = float('-inf')
        positiveCount = 0
        answer = 1
        zeroCount = 0

        for num in nums:
            if num == 0:
                zeroCount += 1
                continue
            if num < 0:
                negativeCount += 1
                maxNegative = max(maxNegative, num)
            else:
                positiveCount += 1
            answer *= abs(num)

        if zeroCount == size:
            return 0
        if negativeCount + zeroCount == size and negativeCount == 1:
            return 0
        if negativeCount % 2 == 0:
            return answer
        else:
            return answer // abs(maxNegative)
