class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr or head->next == nullptr) {
            return head;
        }
        ListNode* nextNode = removeNodes(head->next);
        if(nextNode->val > head->val) {
            return nextNode;
        }
        head->next = nextNode;
        return head;
    }
};