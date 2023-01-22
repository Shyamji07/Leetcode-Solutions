class Solution:
    def alternateDigitSum(self, n: int) -> int:
        digits = []

        while n:
            digits.append(n%10)
            n //= 10
        
        return sum(digits[-1-i] * (1 if i%2 == 0 else -1) for i in range(len(digits)))