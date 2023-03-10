class Solution {
public:
    Solution(ListNode* head) {
        h = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int rd = 1;
        ListNode* tmp = h;
        ListNode* res = NULL;
        while(tmp){
            if(rand()%rd==0)
                res = tmp;
            tmp = tmp->next;
            rd++;
        }
        return res->val;
    }

private:
    ListNode* h;
};