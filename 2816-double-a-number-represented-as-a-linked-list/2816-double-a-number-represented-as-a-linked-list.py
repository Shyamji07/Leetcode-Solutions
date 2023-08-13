class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0,head)
        node = head
        while node:
            node.val = (node.val * 2) % 10
            if node.next and node.next.val > 4:
                node.val = node.val + 1 # add carry
            node = node.next
            
        return head.next if head.val == 0 else head