import heapq

class Solution:
    def minInterval(self, intervals, queries):
        result = {}
        sortedQueries = sorted(queries)
        sortedIntervals = sorted(intervals)
        pq = []
        i = 0
        n = len(intervals)
        
        for q in sortedQueries:
            while i < n and sortedIntervals[i][0] <= q:
                start, end = sortedIntervals[i][0], sortedIntervals[i][1]
                heapq.heappush(pq, (end - start + 1, end))
                i += 1
            
            while pq and pq[0][1] < q:
                heapq.heappop(pq)
            
            result[q] = pq[0][0] if pq else -1
        
        return [result[q] for q in queries]
