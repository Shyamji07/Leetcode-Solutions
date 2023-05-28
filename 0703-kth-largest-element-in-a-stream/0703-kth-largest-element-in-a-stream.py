import heapq

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.num_elems = k
        self.pq_elems = []
        for num in nums:
            heapq.heappush(self.pq_elems, num)
            if len(self.pq_elems) > k:
                heapq.heappop(self.pq_elems)

    def add(self, val: int) -> int:
        if len(self.pq_elems) < self.num_elems:
            heapq.heappush(self.pq_elems, val)
        else:
            if val > self.pq_elems[0]:
                heapq.heappop(self.pq_elems)
                heapq.heappush(self.pq_elems, val)
        return self.pq_elems[0]
