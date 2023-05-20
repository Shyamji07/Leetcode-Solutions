class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        return reduce(operator.xor, derived) == 0
        