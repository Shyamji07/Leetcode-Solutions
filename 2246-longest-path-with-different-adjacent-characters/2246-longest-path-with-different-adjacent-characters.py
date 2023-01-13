class Solution(object):
    ans = 1
    def longestPath(self, parent, s):
        childs = collections.defaultdict(list)
        for i in range(len(parent)):
            childs[parent[i]].append(i)


        def dfs(node):
            if node not in childs:
                return 1

            path1 = 0
            for x in childs[node]:
                path2 = dfs(x)
                if s[x]!=s[node]:
                    self.ans = max(self.ans, path1 + path2 +1)

                    path1 = max(path1, path2)

            return path1+1

        dfs(0)
        return self.ans