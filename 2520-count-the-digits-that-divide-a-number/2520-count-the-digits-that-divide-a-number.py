class Solution:
    def countDigits(self, num: int) -> int:
        return sum(1 if num % int(d) == 0 else 0 for d in str(num))