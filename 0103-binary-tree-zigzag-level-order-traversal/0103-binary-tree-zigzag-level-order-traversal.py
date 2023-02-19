class Solution(object):
    def zigzagLevelOrder(self, root):
        levels=[]
        if not root:
            return []
        queue = [root]
        level=0
        while queue:
            rev = []
            for i in range(len(queue)):
                curr = queue.pop(0)
                rev.append(curr.val)
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            if level%2:
                levels.append(rev[::-1])
            else: 
                levels.append(rev)
            level += 1
        return levels