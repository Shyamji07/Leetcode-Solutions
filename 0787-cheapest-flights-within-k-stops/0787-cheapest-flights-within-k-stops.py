class Solution:
    def findCheapestPrice(self, n, arr, src, dst, k):
        adj = defaultdict(list)
        for s, d, p in arr:
            adj[s].append((d, p))
        queue = deque()
        queue.append((src, 0))
        costs = [float("inf")] * n
        while queue and k >= 0:
            m = len(queue)
            for _ in range(m):
                curr, cost = queue.popleft()
                for node, price in adj[curr]:
                    if cost + price < costs[node]:
                        costs[node] = cost + price
                        queue.append((node, costs[node]))
            k -= 1
        return costs[dst] if costs[dst] != float("inf") else -1
