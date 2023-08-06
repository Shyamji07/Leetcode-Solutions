class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        rem = purchaseAmount % 10
        if rem < 5:
            purchaseAmount = purchaseAmount - rem
        else:
            purchaseAmount = purchaseAmount + (10 - rem)

        return 100 - purchaseAmount