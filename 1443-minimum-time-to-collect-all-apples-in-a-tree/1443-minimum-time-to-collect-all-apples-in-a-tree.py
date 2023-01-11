class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        vis = set()
        def dfs(node):
            if node in vis:
                return 0
            vis.add(node)
            temp = 0
            for x in adj[node]:
                temp += dfs(x)
            if temp > 0:
                return temp + 2
            return 2 if hasApple[node] else 0

        return max(dfs(0) - 2, 0)