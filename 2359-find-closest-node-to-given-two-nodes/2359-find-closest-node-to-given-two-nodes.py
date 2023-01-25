class Solution:
    def closestMeetingNode(self, edges: List[int], n1: int, n2: int) -> int:
        def dfs(node):
            dist, res = 0, [-1]*len(edges)
            
            while node != -1 and res[node] == -1:
                res[node], node = dist, edges[node]
                dist += 1
            return res
    
        ans = (inf,-1)
        for i, (d1,d2) in enumerate(zip(dfs(n1),dfs(n2))):
            if d1 == -1 or d2 == -1: continue
            ans = min(ans,(max(d1, d2),i))
        return ans[1]