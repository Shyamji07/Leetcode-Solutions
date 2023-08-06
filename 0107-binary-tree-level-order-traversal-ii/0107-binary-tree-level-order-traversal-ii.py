class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        from queue import SimpleQueue
        val_list = []
        q = SimpleQueue()
        q.put((root,0))

        while not q.empty():
            cur_node, pos = q.get()
            if cur_node:
                try:
                    val_list[pos].append(cur_node.val)
                except IndexError:
                    val_list.append([cur_node.val])
                q.put((cur_node.left,pos+1))
                q.put((cur_node.right, pos+1))

        return val_list[::-1]