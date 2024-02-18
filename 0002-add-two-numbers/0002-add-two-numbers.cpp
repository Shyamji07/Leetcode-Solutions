class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* l3=new ListNode();
        int carry =0;
        ListNode *temp3=l3;
        while(l1 || l2 || carry>0){
            int sum=0;
            if(l1){
            sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* temp=new ListNode(sum);
            temp3->next=temp;
            temp3=temp3->next;
            
        }
     
        return l3->next;
    }
};