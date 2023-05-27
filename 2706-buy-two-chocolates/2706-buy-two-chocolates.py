class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        first_min = second_min = maxsize

        for p in prices:
            if p < first_min:
                second_min, first_min = first_min, p
            elif p < second_min:
                second_min = p

        min_price = first_min + second_min
        return money - min_price if min_price <= money else money