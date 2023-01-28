class SummaryRanges:

    def __init__(self):
        self.nums = set()

    def addNum(self, value: int) -> None:
        self.nums.add(value)

    def getIntervals(self) -> List[List[int]]:
        arr = []
        vis = set()
        for num in self.nums:
            if num in vis:
                continue

            left = num
            while left - 1 in self.nums:
                left -= 1
                vis.add(left)

            right = num
            while right + 1 in self.nums:
                right += 1
                vis.add(right)

            arr.append([left, right])
        return sorted(arr)