class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        stack<int>s;
        int length = 0; 
        while(temp){
            length++; 
            s.push(temp->val);
            temp=temp->next;
        }
       int mx=0;
       while((length)/2 >0){
           length--;
           mx=max(mx,s.top()+head->val);
           head=head->next;
           s.pop();
       }
       return mx;
    }
};