class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head, *last = NULL;
        int pos = 1;
        while(temp) {
            if(pos == left) {
                ListNode *curr = temp, *prev = NULL, *next = NULL;
                while(curr and pos <= right) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    pos++;
                }
                temp->next = curr;
                if(last) last->next = prev;
                else head = prev;
                break;
            }
            last = temp;
            temp = temp->next;
            pos++;
        }
        return head;
    }
};