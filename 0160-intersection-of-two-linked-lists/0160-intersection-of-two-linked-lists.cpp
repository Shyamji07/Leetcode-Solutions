class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode *s1=head1, *s2=head2;
        while(s1!=s2){
            s1=s1==NULL?head2:s1->next;
            s2=s2==NULL?head1:s2->next;
        }
        return s1;
    }
};