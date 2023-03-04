/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(head1, head2) {
        let s1=head1;
        var s2=head2;
        while(s1!=s2){
            s1=s1==null?head2:s1.next;
            s2=s2==null?head1:s2.next;
        }
        return s1;
};