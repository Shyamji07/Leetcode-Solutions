class Solution:
    def getIntersectionNode(self, head1: ListNode, head2: ListNode) -> Optional[ListNode]:
        s1=head1;
        s2=head2;
        while(s1!=s2):
            s1= head2 if s1 is None else s1.next
            s2= head1 if s2 is None else s2.next
        return s1;
        