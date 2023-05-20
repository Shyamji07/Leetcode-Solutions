class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        G = [[] for i in range(n)]
        for i,j in edges:
            G[i].append(j)
            G[j].append(i)
        seen = [0] * n

        res = 0
        for i in range(n):
            if seen[i]: continue
            bfs = [i]
            seen[i] = 1
            for j in bfs:
                for k in G[j]:
                    if seen[k] == 0:
                        bfs.append(k)
                        seen[k] = 1
            if all(len(G[j]) == len(bfs) - 1 for j in bfs):
                res += 1
        return res
        